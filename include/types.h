/**
 *	types.h | Generic typedef header.
 * -------------------------------------------------------------------------- */

#ifndef _TYPES_H
# define _TYPES_H

/**
 * Numeral types.
 */

# include <stdint.h>

typedef uint64_t	u64;
typedef uint32_t	u32;
typedef uint16_t	u16;
typedef uint8_t		u8;

typedef	uintptr_t	uptr;

typedef int64_t		i64;
typedef int32_t		i32;
typedef int16_t		i16;
typedef int8_t		i8;

typedef	intptr_t	iptr;

typedef float		f32;
typedef double		f64;

/**
 * Verbose types
 */

typedef const char	*String;
typedef u8			*RawData;
typedef u64			Size;
typedef u64			Address;

#endif // _TYPES_H
