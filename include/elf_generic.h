#ifndef ELF_GENERIC_H
# define ELF_GENERIC_H

#include <stdint.h>

# define PACKED	__attribute__((packed))

/**
 * @struct	ELF_Ident.
 *
 * @brief		16 bytes ELF File identifier.
 *
 *		e_magic			0x7F 'E' 'L' 'F'
 *		e_class			File class			(32 or 64 bit)
 *		e_endianness	File endianness		(from offset 0x10)
 *		e_version		ELF version			(should always be 1)
 *		e_ABI			OS ABI
 *		e_ABIversion	ABI version spec
 *		e_padding		empty space			(should be 0 filled)
 */
typedef union
{
	struct
	{
		uint8_t	e_magic[4];
		uint8_t	e_class;
		uint8_t	e_endianness;
		uint8_t	e_version;
		uint8_t	e_ABI;
		uint8_t	e_ABIversion;
		uint8_t	e_padding[7];
	};
	uint8_t	e_ident[16];
}	ELF_Ident;

# define	ELF_MAG0	'\x7f'
# define	ELF_MAG1	'E'
# define	ELF_MAG2	'L'
# define	ELF_MAG3	'F'

# define	ELF_MAGIC	0x464C457F

/**
 * @struct	ELF64_Hdr
 *
 * @brief		64-bit ELF Header.
 *
 *		e_ident			Identification bytes
 *		e_type			File type
 *		e_machine		Instruction set architecture
 *		e_version		ELF version	(should always be 1)
 *		e_entry			Program entrypoint address
 *		e_phoff			Program header table offset
 *		e_shoff			Section header table offset
 *		e_flags			Architecture-specific
 *		e_hsize			ELF header size
 *		e_phsize		Program header table entry size
 *		e_phnum			Program header table entry count
 *		e_shsize		Section header table entry size
 *		e_shnum			Section header table entry count
 *		e_shstridx		Section header index for section names
 */
typedef struct
{
	ELF_Ident	e_ident;
	uint16_t	e_type;
	uint16_t	e_machine;
	uint32_t	e_version;
	uint64_t	e_entry;
	uint64_t	e_phoff;
	uint64_t	e_shoff;
	uint32_t	e_flags;
	uint16_t	e_hsize;
	uint16_t	e_phsize;
	uint16_t	e_phnum;
	uint16_t	e_shsize;
	uint16_t	e_shnum;
	uint16_t	e_shstridx;
}	PACKED ELF64_Hdr;





#endif
