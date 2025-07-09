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

# include <types.h>
# include <ansic.h>

# include <celf.h>
# define CELF_ENUMS_STRINGIFY
# define CELF_ENUMS_IMPL
# include <celf_enums.h>

# define	LOG_FMT		"[" BOLD(FG_GRAY("INFO")) "]: "

# define	LOG(X, ...)	printf(LOG_FMT X "\n", ##__VA_ARGS__)
# define	ERR(X, ...)	printf(LOG_FMT FG_RED(X) "\n", ##__VA_ARGS__)
# define	WRN(X, ...)	printf(LOG_FMT FG_YELLOW(X) "\n", ##__VA_ARGS__)

typedef struct s_elf
{
	RawData	raw;
	Size	size;
}	Elf;

typedef struct s_section
{
	String	name;
	Address	addr;
	Size	size;
	u64		offset;
	u64		flags;
	u32		type;
	RawData	content;
}	Section;

typedef struct s_symbol
{
	String	name;
	Address	value;
	Size	size;
	u16		section;
	u8		bind;
	u8		type;
	bool	dyn;
}	Symbol;

typedef struct s_reloc
{
	u64		offset;
	u32		type;
	u32		sym;
	i64		addend;
}	Relocation;

/**
 * File handling.
 */

RawData
od_elf_map(int fd, u64 size);

bool
od_elf_open(String fp, Elf *file);

void
od_elf_close(Elf *file);

/**
 * Getters.
 */

RawData
od_elf_section_headers(Elf *file);

RawData
od_elf_symtab(Elf *file);

RawData
od_elf_dynsym(Elf *file);

RawData
od_elf_rela(Elf *file);

#endif
