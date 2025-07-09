/**
 *	celf_enums.h | ELF Enums
 *
 *	ELF Header fields:
 *		-	ELF_IdentIndices,
 *		-	ELF_Class,
 *		-	ELF_Endianness,
 *		-	ELF_OsAbi,
 *		-	ELF_ExType,
 *		-	ELF_Machine,
 *		-	ELF_Version,
 *
 *	ELF Program Header fields:
 *		-	ELF_ProgType,
 *		-	ELF_ProgFlags,
 *
 *	ELF Section Header fields:
 *		-	ELF_SectionType,
 *		-	ELF_SectionFlags,
 *
 *	ELF Symbol fields:
 *		-	ELF_SymbolVisibility,
 *		-	ELF_SymbolBind,
 *		-	ELF_SymbolType,
 *
 *	ELF Dynamic Symbol field:
 *		-	ELF_DynamicTag,
 *	
 *	These aren't used in the struct definitions to keep the original
 *	integer types for all fields.
 *
 ** ***************************************************************************/

#ifndef _CELF_ENUMS_H
# define _CELF_ENUMS_H

enum	ELF_IdentIndices
{
	EI_MAG0			= 0,
	EI_MAG1			= 1,
	EI_MAG2			= 2,
	EI_MAG3			= 3,
	EI_CLASS		= 4,
	EI_DATA			= 5,
	EI_VERSION		= 6,
	EI_OSABI		= 7,
	EI_ABIVERSION	= 8,
};

enum	ELF_Class
{
	ELF_32BIT		= 1,
	ELF_64BIT		= 2,
};

enum	ELF_Endianness
{
	ELF_DATANONE	= 0x00,
	ELF_DATA2LSB	= 0x01,
	ELF_DATA2MSB	= 0x02,
};

enum	ELF_OsAbi
{
	EABI_SYSV		= 0x00,
	EABI_HPUX		= 0x01,
	EABI_NETBSD		= 0x02,
	EABI_LINUX		= 0x03,
	EABI_HURD		= 0x04,
	EABI_SOLARIS	= 0x06,
	EABI_AIX		= 0x07,
	EABI_IRIX		= 0x08,
	EABI_FREEBSD	= 0x09,
	EABI_TRU64		= 0x0A,
	EABI_MODESTO	= 0x0B,
	EABI_OPENBSD	= 0x0C,
	EABI_OPENVMS	= 0x0D,
	EABI_NSK		= 0x0E,
	EABI_AROS		= 0x0F,
	EABI_FENIXOS	= 0x10,
	EABI_CLOUDABI	= 0x11,
	EABI_OPENVOS	= 0x12,
};

enum	ELF_ExType
{
	ET_NONE		= 0x00,
	ET_REL		= 0x01,
	ET_EXEC		= 0x02,
	ET_DYN		= 0x03,
	ET_CORE		= 0x04,
	ET_LOOS		= 0xFE00,
	ET_HIOS		= 0xFEFF,
	ET_LOPROC	= 0xFF00,
	ET_HIPROC	= 0xFFFF
};

enum	ELF_Machine
{
    EM_NONE        = 0x00,
    EM_M32         = 0x01,
    EM_SPARC       = 0x02,
    EM_386         = 0x03,
    EM_68K         = 0x04,
    EM_88K         = 0x05,
    EM_IAMCU       = 0x06,
    EM_860         = 0x07,
    EM_MIPS        = 0x08,
    EM_ARM         = 0x28,
    EM_X86_64      = 0x3E,
	EM_AARCH64     = 0xB7,
    EM_RISCV       = 0xF3,
};

enum	ELF_Version
{
	EV_NONE		=	0x00,
	EV_CURRENT	=	0x01,
	EV_NUM		=	0x02,
};

enum	ELF_ProgType
{
	PT_NULL			= 0x00000000,
	PT_LOAD			= 0x00000001,
	PT_DYNAMIC		= 0x00000002,
	PT_INTERP		= 0x00000003,
	PT_NOTE			= 0x00000004,
	PT_SHLIB		= 0x00000005,
	PT_PHDR			= 0x00000006,
	PT_TLS			= 0x00000007,
	PT_LOOS			= 0x60000000,
	PT_GNU_EH_FRAME	= 0x6474e550,
	PT_GNU_STACK	= 0x6474e551,
	PT_GNU_RELRO	= 0x6474e552,
	PT_GNU_PROPERTY	= 0x6474e553,
	PT_LOSUNW		= 0x6ffffffa,
	PT_SUNWBSS		= 0x6ffffffa,
	PT_SUNWSTACK	= 0x6ffffffb,
	PT_HISUNW		= 0x6fffffff,
	PT_HIOS			= 0x6FFFFFFF,
	PT_LOPROC		= 0x70000000,
	PT_HIPROC		= 0x7FFFFFFF,
};

enum	ELF_ProgFlags
{
	PF_X		= (1 << 0),
	PF_W	= (1 << 1),
	PF_R		= (1 << 2),
	PF_MASKOS	= 0x0FF00000,
	PF_MASKPROC	= 0xF0000000,
};

enum	ELF_SectionType
{
	SHT_NULL			= 0x0,
	SHT_PROGBITS		= 0x1,
	SHT_SYMTAB			= 0x2,
	SHT_STRTAB			= 0x3,
	SHT_RELA			= 0x4,
	SHT_HASH			= 0x5,
	SHT_DYNAMIC			= 0x6,
	SHT_NOTE			= 0x7,
	SHT_NOBITS			= 0x8,
	SHT_REL				= 0x9,
	SHT_SHLIB			= 0x0A,
	SHT_DYNSYM			= 0x0B,
	SHT_INIT_ARRAY		= 0x0E,
	SHT_FINI_ARRAY		= 0x0F,
	SHT_PREINIT_ARRAY	= 0x10,
	SHT_GROUP			= 0x11,
	SHT_SYMTAB_SHNDX	= 0x12,
	SHT_NUM				= 0x13,
	SHT_LOOS			= 0x60000000,
	SHT_GNU_VERSYM		= 0x6FFFFFF0,
	SHT_GNU_HASH		= 0x6FFFFFF6,
	SHT_GNU_LIBLIST		= 0x6FFFFFF7,
	SHT_GNU_VERDEF		= 0x6FFFFFFD,
	SHT_GNU_VERNEED		= 0x6FFFFFFE,
	SHT_HIOS			= 0xFFFFFFFF,
};

enum	ELF_SectionFlags
{
	SHF_WRITE				= 0x1,
	SHF_ALLOC				= 0x2,
	SHF_EXECINSTR			= 0x4,
	SHF_MERGE				= 0x10,
	SHF_STRINGS				= 0x20,
	SHF_INFO_LINK			= 0x40,
	SHF_LINK_ORDER			= 0x80,
	SHF_OS_NONCONFORMING	= 0x100,
	SHF_GROUP				= 0x200,
	SHF_TLS					= 0x400,
	SHF_MASKOS				= 0x0FF00000,
	SHF_MASKPROC			= 0xF0000000,
	SHF_ORDERED				= 0x4000000,
	SHF_EXCLUDE				= 0x8000000,
	SHF_SOLARIS				= 0x80000000,
};

enum	ELF_SymbolVisibility
{
	STV_DEFAULT		= 0,
	STV_INTERNAL	= 1,
	STV_HIDDEN		= 2,
	STV_PROTECTED	= 3,
};

enum	ELF_SymbolBind
{
	STB_LOCAL		= 0,
	STB_GLOBAL		= 1,
	STB_WEAK		= 2,
	STB_NUM			= 3,
	STB_LOOS		= 10,
	STB_GNU_UNIQUE	= 10,
	STB_HIOS		= 12,
	STB_LOPROC		= 13,
	STB_HIPROC		= 15, 
};

enum	ELF_SymbolType
{
	STT_NOTYPE		= 0,
	STT_OBJECT		= 1,
	STT_FUNC		= 2,
	STT_SECTION		= 3,
	STT_FILE		= 4,
	STT_COMMON		= 5,
	STT_TLS			= 6,
	STT_NUM			= 7,
	STT_LOOS		= 10,
	STT_GNU_IFUNC	= 10,
	STT_HIOS		= 12,
	STT_LOPROC		= 13,
	STT_HIPROC		= 15,
};

enum	ELF_SectionIndices
{
	SHN_UNDEF		= 0,
	SHN_LORESERVE	= 0xFF00,
	SHN_LOPROC		= 0xFF00,
	SHN_BEFORE		= 0xFF00,
	SHN_AFTER		= 0xFF01,
	SHN_HIPROC		= 0xFF1F,
	SHN_ABS			= 0xFFF1,
	SHN_COMMON		= 0xFFF2,
	SHN_HIRESERVE	= 0xFFFF,
};

enum	ELF_DynamicTag
{
	DT_NULL				= 0,
	DT_NEEDED			= 1,
	DT_PLTRELSZ			= 2,
	DT_PLTGOT			= 3,
	DT_HASH				= 4,
	DT_STRTAB			= 5,
	DT_SYMTAB			= 6,
	DT_RELA				= 7,
	DT_RELASZ			= 8,
	DT_RELAENT			= 9,
	DT_STRSZ			= 10,
	DT_SYMENT			= 11,
	DT_INIT				= 12,
	DT_FINI				= 13,
	DT_SONAME			= 14,
	DT_RPATH			= 15,
	DT_SYMBOLIC			= 16,
	DT_REL				= 17,
	DT_RELSZ			= 18,
	DT_RELENT			= 19,
	DT_PLTREL			= 20,
	DT_DEBUG			= 21,
	DT_TEXTREL			= 22,
	DT_JMPREL			= 23,
	DT_BIND_NOW			= 24,
	DT_INIT_ARRAY		= 25,
	DT_FINI_ARRAY		= 26,
	DT_INIT_ARRAYSZ		= 27,
	DT_FINI_ARRAYSZ		= 28,
	DT_RUNPATH			= 29,
	DT_FLAGS			= 30,
	DT_ENCODING			= 32,
	DT_PREINIT_ARRAY	= 32,
	DT_PREINIT_ARRAYSZ	= 33,
	DT_SYMTAB_SHNDX		= 34,
	DT_NUM				= 35,
	DT_LOOS				= 0x6000000d,
	DT_HIOS				= 0x6ffff000,
	DT_LOPROC			= 0x70000000,
	DT_HIPROC			= 0x7fffffff
};

#endif	// _CELF_ENUMS_H
