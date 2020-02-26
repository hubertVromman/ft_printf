#include "ft_printf.h"

int		init_parser(t_a *all)
{
	all->parser_info.flags = 0;
	all->parser_info.converter = 0;
	all->parser_info.modifier[0] = 0;
	all->parser_info.modifier[1] = 0;
	all->parser_info.min_width = -1;
	all->parser_info.precision = -1;
	all->parser_info.next_arg_pos = -1;
	return (0);
}

int		parser_loop(t_a *all) 
{
	int		ret;

	while (all->format[0])
	{
		if ((ret = ft_indexof(FLAGS, all->format[0])) != -1)
			check_flags(all, ret);
		else if (ft_indexof(MODIFIERS, all->format[0]) != -1)
			check_modifier(all);
		else if (all->format[0] == '.')
			check_precision(all);
		else if (ft_isdigit(all->format[0]))
			check_width_or_dollar(all);
		else
			return (check_converter(all));
	}
	return (-1);
}

int		parser(t_a *all) 
{
	init_parser(all);
	all->format++; // percent
	parser_loop(all);
	return (0);
}