#include "ft_printf.h"

int		check_precision(t_a *all)
{
	all->format++;
	all->parser_info.precision = micro_atoi(all);
	return (0);
}

int		check_width_or_dollar(t_a *all)
{
	(void)all;
	return (0);
}

int		check_converter(t_a *all)
{
	(void)all;
	return (0);
}

int		check_modifier(t_a *all)
{
	char	new_modifier;

	new_modifier = all->format[0];
	if (!all->parser_info.modifier[0])
		all->parser_info.modifier[0] = new_modifier;
	else if (!all->parser_info.modifier[1] && all->format[-1] == new_modifier)
		all->parser_info.modifier[1] = new_modifier;
	else {
		all->parser_info.modifier[0] = new_modifier;
		all->parser_info.modifier[1] = 0;
	}
	return (0);
}

int		check_flags(t_a *all, int ret)
{
	all->parser_info.flags |= 1 << ret;
	all->format++;
	return (0);
}