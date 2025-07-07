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
main(int argc, char **argv)
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
