/**
 * elf.c
 */

#include <objdump-d.h>

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

	fd = open(fp, O_RDONLY);
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
	munmap(file->raw, file->size);
	memset(file, 0, sizeof(Elf));
}
