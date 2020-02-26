#include "ft_printf.h"

int		init(t_a *all, char *format) 
{
	ft_bzero(all, sizeof(*all));
	all->format = format;
	return (0);
}

int		realloc_g_str(t_a *all)
{
	char	*tmp;

	if (!(tmp = malloc(all->g_str_len + all->percent_index)))
		return (-1);
	ft_memcpy(tmp, all->g_str, all->g_str_len);
	ft_memcpy(tmp + all->g_str_len, all->format, all->percent_index);
	all->g_str_len += all->percent_index;
	all->format += all->percent_index;
	free(all->g_str);
	all->g_str = tmp;
	all->percent_index = 0;
	return (0);
}

int		main_loop(t_a *all)
{
	while ((all->percent_index = ft_indexof(all->format, '%')) != -1) {
		if (realloc_g_str(all))
			return (-1);
		parser(all);
		// writer(all);
	}
	all->percent_index = ft_strlen(all->format);
	if (realloc_g_str(all))
		return (-1);
	return (0);
}

int		write_output(t_a *all)
{
	ssize_t	ret;

	ret = write(1, all->g_str, all->g_str_len);
	return (ret == -1);
}

int		ft_printf(const char *format, ...)
{
	t_a		all;

	init(&all, (char *)format);
	va_start(all.backup_arg_list, format);
	va_copy(all.arg_list, all.backup_arg_list);
	if (main_loop(&all) || write_output(&all))
		return (-1);
	return (0);
}