
#include "objdump-d.h"
#include <sys/mman.h>

void *read_file(char *argv, t_elf *elf){

	int			file;
	struct stat	file_stat;
	void		*filemap;

	file = open(argv, O_RDONLY);
	if (file == -1)
		return (NULL);
	if (stat(argv, &file_stat))
		return (NULL);
	filemap = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file, 0);
	elf->fileStat = file_stat;
	return (filemap);
}


int main(int argc, char **argv){
	if (argc != 2)
		return (1);
	t_elf elf = {0};

	void *filemap = read_file(argv[1], &elf);
	write(1, filemap, elf.fileStat.st_size);
}
