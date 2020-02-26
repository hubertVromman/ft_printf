#include "ft_printf.h"

int		micro_atoi(t_a *all)
{
	int		result;

	result = 0;
	while (ft_isdigit(all->format[0]))
	{
		result = result * 10 + all->format[0] - '0';
		all->format++;
	}
	printf("%d\n", result);
	return (result);
}