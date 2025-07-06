
#include "objdump-d.h"

void	_load_elf(t_elf **elfAddr, struct stat *fileStatAddr, char *buffer){
	(*elfAddr)->fileBuffer = malloc(fileStatAddr->st_size);
	if (!(*elfAddr)->fileBuffer)
		return ;
	memcpy(&(*elfAddr)->fileStat, fileStatAddr, sizeof(*fileStatAddr));
	memcpy((*elfAddr)->fileBuffer, buffer, fileStatAddr->st_size);
}

t_elf *read_file(char *argv){

	int			file;
	struct stat	file_stat;
	char		*buffer;
	t_elf		*elf;

	elf = malloc(sizeof(t_elf));
	if(!elf)
		return(NULL);
	file = open(argv, O_RDONLY);
	if (file == -1)
		return (NULL);
	if (stat(argv, &file_stat))
		return (NULL);
	buffer = malloc(file_stat.st_size);
	if (!buffer)
		return (NULL);
	ssize_t bytes = read(file, buffer, file_stat.st_size);
	if (bytes == -1){
		free(buffer);
		return (NULL);
	}
	buffer[file_stat.st_size] = '\0';
	_load_elf(&elf, &file_stat, buffer);
	free(buffer);
	if (!elf->fileBuffer){
		free(elf);
		return (NULL);
	}
	return (elf);
}


int main(int argc, char **argv){
	if (argc != 2)
		return (1);

	t_elf *elf = read_file(argv[1]);
	if (!elf)
		return (1);
	write(1, elf->fileBuffer, elf->fileStat.st_size);
	free(elf->fileBuffer);
	free(elf);
}
