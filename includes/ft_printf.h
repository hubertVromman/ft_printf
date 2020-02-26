#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MERROR -2
# define FLAGS "#0- +'"
# define MODIFIERS "hljtz"
# define CONVERTERS "diouxXDOUeEfFgGaAcCsSpn%"


enum flags {
	DIESIS =		0b000001,
	ZERO =			0b000010,
	MINUS =			0b000100,
	SPACE =			0b001000,
	PLUS =			0b010000,
	APOSTROPHE =	0b100000,
};

typedef struct	s_parser_info
{
	int		flags;
	char	converter;
	char	modifier[2];
	int		min_width;
	int		precision;
	int		next_arg_pos;
}				t_parser_info;

typedef struct	s_a
{
	char			*format;
	char			*g_str;
	int				g_str_len;
	int				percent_index;
	va_list			arg_list;
	va_list			backup_arg_list;
	t_parser_info	parser_info;
}				t_a;

int		ft_printf(const char *format, ...);

#endif