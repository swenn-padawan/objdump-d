/**
 * elf.c
 */

#include <objdump-d.h>

RawData
od_elf_map(int fd, uint64_t size)
{
	RawData	p = NULL;

	p = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED)
		return (NULL);
	return (p);
}

bool
od_elf_open(const char *fp, Elf *file)
{
	struct stat	st = {0};
	int			fd;
	RawData		raw;

	if (stat(fp, &st))
		return (false);

	fd = open(fp, O_RDONLY);
	if (fd == -1)
		return (false);

	raw = od_elf_map(fd, st.st_size);
	close(fd);
	if (!raw)
		return (false);

	*file = (Elf) { .raw = raw, .size = st.st_size };
	
	return (true);
}

void
od_elf_close(Elf *file)
{
	munmap(file->raw, file->size);
	memset(file, 0, sizeof(Elf));
}

static inline RawData
od_elf_section_content(Elf *file, u32 idx)
{
	ELF64_Shdr	*sections = (ELF64_Shdr *)od_elf_section_headers(file);
	ELF64_Shdr	*section = sections + idx;

	return (file->raw + section->sh_offset);
}

// TODO SWENN FAIT TOUT CA STP PLEASE

RawData
od_elf_section_headers(Elf *file)
{
	ELF64_Hdr	*header = (ELF64_Hdr *)file->raw;
	uint64_t	offset  = header->e_shoff;

	return (file->raw + offset);
}

RawData
od_elf_symtab(Elf *file)
{
	(void) file;
	return (NULL);
}

RawData
od_elf_dynsym(Elf *file)
{
	(void) file;
	return (NULL);
}

RawData
od_elf_rel(Elf *file)
{
	(void) file;
	return (NULL);
}

RawData
od_elf_rela(Elf *file)
{
	(void) file;
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////
