/**
 * main.c
 * -------------------------------------------------------------------------- */

#include "objdump-d.h"

// void *read_file(char *argv, t_elf *elf)
// {
// 	int			file;
// 	struct stat	file_stat;
// 	void		*filemap;
// 
// 	file = open(argv, O_RDONLY);
// 	if (file == -1)
// 		return (NULL);
// 	if (stat(argv, &file_stat))
// 		return (NULL);
// 	filemap = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file, 0);
// 	elf->fileStat = file_stat;
// 	return (filemap);
// }

void
*od_elf_map(int fd, uint64_t size)
{
	void	*p = NULL;

	p = mmap(NULL, size, PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, fd, 0);
	if (p == MAP_FAILED)
		return (NULL);
	return (p);
}

bool
od_elf_open(const char *fp, Elf *file)
{
	struct stat	st = {0};
	int			fd;

	fd = open(argv, O_RDONLY)
	if (fd == -1)
		return (false);

	if (stat(fp, &st))
		return (false);

	file->raw = od_elf_map(fd, st.st_size);
	close(fd);
	if (!file->raw)
		return (false);
	file->size = st.st_size;
	
	return (true);
}

void
od_elf_close(Elf *file)
{
	munmap(file.raw, file.size);
	memset(file, 0, sizeof(Elf));
}

#define	SHIFT(ac, av)	(ac--, *argv++)

int main(int argc, char **argv)
{
	const char	*exe = SHIFT(argc, argv);

	if (argc != 1)
		od_usage(1);

	Elf	target = {0};

	od_elf_open(*argv, &file);
	od_elf_close(&file);
}
