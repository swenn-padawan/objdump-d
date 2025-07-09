/**
 *	ansic.h | utils file for ansi string formatting.
 *
 *	sourced from https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 * -------------------------------------------------------------------------- */

#ifndef _ANSIC_H
# define _ANSIC_H

# define	ESC_CHAR	"\x1b"
# define	ESC_CSI		ESC_CHAR "["

# define	SEQ(X)		ESC_CHAR X
# define	SEQ_CSI(X)	ESC_CSI X

/**
 * @ Cursor control sequences
 * -------------------------------------------------------------------------- */

# define	_CURSOR_TO(x, y)	SEQ_CSI(#x SEP_CHAR #y "H")

# define	CURSOR_TO_0			_CURSOR_TO(0, 0)
# define	CURSOR_TO(x, y)		_CURSOR_TO(x, y)

# define	CURSOR_UP(n)		SEQ_CSI(#n "A")
# define	CURSOR_DOWN(n)		SEQ_CSI(#n "B")
# define	CURSOR_RIGHT(n)		SEQ_CSI(#n "C")
# define	CURSOR_LEFT(n)		SEQ_CSI(#n "D")

# define	CURSOR_UP_CR(n)		SEQ_CSI(#n "E")
# define	CURSOR_DOWN_CR(n)	SEQ_CSI(#n "F")

# define	CURSOR_COLUMN(n)	SEQ_CSI(#n "G")

# define	CURSOR_SAVE			SEQ("7")
# define	CURSOR_RESTORT		SEQ("8")

/**
 * @ Erase control sequences.
 * -------------------------------------------------------------------------- */

# define	ERASE_SCREEN(X)		SEQ_CSI(X, "J")
# define	ERASE_LINE(X)		SEQ_CSI(X, "K")

# define	ERASE_SCREEN_IN		ERASE_SCREEN("")
# define	ERASE_SCREEN_END	ERASE_SCREEN("0")
# define	ERASE_SCREEN_START	ERASE_SCREEN("1")
# define	ERASE_SCREEN_ALL	ERASE_SCREEN("2")

# define	ERASE_LINE_IN		ERASE_LINE("")
# define	ERASE_LINE_END		ERASE_LINE("0")
# define	ERASE_LINE_START	ERASE_LINE("1")
# define	ERASE_LINE_ALL		ERASE_LINE("2")

# define	ERASE_SAVED_LINES	ERASE_SCREEN("3")

/**
 * @ Colors and graphics modes.
 * -------------------------------------------------------------------------- */

# define	SEQ_GRAPHICS(X)		SEQ_CSI(X "m")

# define	GRAPH_SET_MODE(X)	SEQ_GRAPHICS(X)
# define	GRAPH_UNSET_MODE(X)	SEQ_GRAPHICS("2" X)
# define	GRAPH_RESET			SEQ_GRAPHICS("0")

# define	GRAPH_MODE(X, S)	GRAPH_SET_MODE(X) S GRAPH_UNSET_MODE(X)

# define	BOLD(S)				GRAPH_SET_MODE("1") S GRAPH_UNSET_MODE("2")
# define	FAINT(S)			GRAPH_MODE("2", S)
# define	ITALIC(S)			GRAPH_MODE("3", S)
# define	UNDERLINE(S)		GRAPH_MODE("4", S)
# define	BLINKING(S)			GRAPH_MODE("5", S)
# define	REVERSE(S)			GRAPH_MODE("7", S)
# define	HIDDEN(S)			GRAPH_MODE("8", S)
# define	STRIKETHROUGH(S)	GRAPH_MODE("9", S)

# define	COLOR_MODE(M, C, S)	SEQ_GRAPHICS(M C) S SEQ_GRAPHICS(M "9")

# define	COLOR_FG(C, S)		COLOR_MODE("3", C, S)
# define	COLOR_BG(C, S)		COLOR_MODE("4", C, S)

# define	FG_BLACK(S)			COLOR_FG("0", S)
# define	FG_RED(S)			COLOR_FG("1", S)
# define	FG_GREEN(S)			COLOR_FG("2", S)
# define	FG_YELLOW(S)		COLOR_FG("3", S)
# define	FG_BLUE(S)			COLOR_FG("4", S)
# define	FG_MAGENTA(S)		COLOR_FG("5", S)
# define	FG_CYAN(S)			COLOR_FG("6", S)
# define	FG_WHITE(S)			COLOR_FG("7", S)
# define	FG_GRAY(S)			SEQ_GRAPHICS("90") S GRAPH_RESET
# define	FG_DEFAULT(S)		COLOR_FG("9", S)

# define	BG_BLACK(S)			COLOR_BG("0", S)
# define	BG_RED(S)			COLOR_BG("1", S)
# define	BG_GREEN(S)			COLOR_BG("2", S)
# define	BG_YELLOW(S)		COLOR_BG("3", S)
# define	BG_BLUE(S)			COLOR_BG("4", S)
# define	BG_MAGENTA(S)		COLOR_BG("5", S)
# define	BG_CYAN(S)			COLOR_BG("6", S)
# define	BG_WHITE(S)			COLOR_BG("7", S)
# define	BG_DEFAULT(S)		COLOR_BG("9", S)

#endif // _ANSIC_H
