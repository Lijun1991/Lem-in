/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_longlong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 00:37:23 by lwang             #+#    #+#             */
/*   Updated: 2017/05/21 00:37:25 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_ato_longlong(char *str)
{
	int			i;
	int			flag;
	long long	nb;

	i = 0;
	flag = 1;
	nb = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || \
		str[i] == '\r' || str[i] == '\f' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (long long)(str[i] - 48);
		i++;
	}
	return (nb * flag);
}
