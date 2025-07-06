#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *read_file(char *argv){

	int	file;
	file = open(argv, O_RDONLY);
	if (file == -1)
		return (NULL);
	struct stat file_stat;
	if (stat(argv, &file_stat))
		return (NULL);
	char *buffer = malloc(file_stat.st_size + 1);
	if (!buffer)
		return (NULL);
	ssize_t bytes = read(file, buffer, file_stat.st_size);
	if (bytes == -1){
		free(buffer);
		return (NULL);
	}
	buffer[file_stat.st_size] = '\0';
	return (buffer);
}

int main(int argc, char **argv){
	if (argc != 2) return (1);
	char *buffer = read_file(argv[1]);	
	
	printf("file = %s\n", buffer);
	free(buffer);
}
