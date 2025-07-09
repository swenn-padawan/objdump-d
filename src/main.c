/**
 * main.c
 * -------------------------------------------------------------------------- */

#include <objdump-d.h>

#define	SHIFT(ac, av)	(ac--, *argv++)

static const char	*exe;

void
od_usage(int ret)
{
	LOG("Usage: %s [file]", exe);
	exit(ret);
}

int
main2(int argc, char **argv)
{
	exe = SHIFT(argc, argv);

	if (argc != 1)
		od_usage(1);

	Elf	target = {0};

	if (!od_elf_open(*argv, &target))
	{
		ERR("%s: %s", *argv, strerror(errno));
		return (1);
	}
	od_elf_close(&target);

	return (0);
}

#include <termios.h>
#include <sys/ioctl.h>

#define	TTY_CANONICAL		0
#define	TTY_NON_CANONICAL	1

bool
od_terminal_mode(u32 mode)
{
	struct termios			attr;
	static struct termios	back;

	if (!isatty(STDIN_FILENO))
		return (false);
	tcgetattr(STDIN_FILENO, &back);
	if (mode == TTY_NON_CANONICAL)
	{
		attr = back;
		attr.c_lflag &= ~(ICANON | ECHO);
		attr.c_cc[VMIN] = 0;
		attr.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &back);
	return (true);
}

void
od_terminal_size(u32 *row, u32 *col)
{
	struct winsize	win;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	*row = win.ws_row;
	*col = win.ws_col;
}

int
main(void)
{
	u32 x, y;

	od_terminal_mode(TTY_NON_CANONICAL);
	od_terminal_size(&x, &y);

	LOG("Terminal is %u x %u", x, y);

	char	c[4] = {0};

	while (1)
	{
		*(u32 *)c = 0;

		int r = read(STDIN_FILENO, c, 1);

		if (r < 0)
			break ;
		if (c[0] == 0)
			continue ;
		
		LOG("character = %c\n", c[0]);
	}

	od_terminal_mode(TTY_CANONICAL);

	return (0);
}
