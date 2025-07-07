/**
 *	objdump-d.h
 */

#ifndef _OBJDUMP_D_H
# define _OBJDUMP_D_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/mman.h>

# define	LOG_FMT		"[\033[90;1m INFO  \033[0m]: "
# define	LOG(X, ...)	printf(LOG_FMT X "\n", ##__VA_ARGS__)

# define	ERR_FMT		"[\033[31;1m ERROR \033[0m]: "
# define	ERR(X, ...)	printf(ERR_FMT X "\n", ##__VA_ARGS__)

# define	WRN_FMT		"[\033[31;1mWARNING\033[0m]: "
# define	WRN(X, ...)	printf(WRN_FMT X "\n", ##__VA_ARGS__)

# include <celf.h>

typedef struct s_elf
{
	uint8_t		*raw;
	uint64_t	size;
}	Elf;

void
*od_elf_map(int fd, uint64_t size);

bool
od_elf_open(const char *fp, Elf *file);

void
od_elf_close(Elf *file);

#endif
