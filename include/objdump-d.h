/**
 *	objdump-d.h
 */

#ifndef _OBJDUMP_D_H
# define _OBJDUMP_D_H

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <celf.h>

typedef struct s_elf
{
	uint8_t		*raw;
	uint64_t	size;
}	elf;

#endif
