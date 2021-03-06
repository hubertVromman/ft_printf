/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvromman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:11:56 by hvromman          #+#    #+#             */
/*   Updated: 2018/10/02 15:11:59 by hvromman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2 && (*s1 != '\0' || *s2 != '\0'))
		return ((*s1 - *s2) ? 0 : ft_strequ(s1 + 1, s2 + 1));
	return (((s1 && !s2) || (!s1 && s2)) ? 0 : 1);
}
