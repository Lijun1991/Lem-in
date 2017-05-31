/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:11:27 by lwang             #+#    #+#             */
/*   Updated: 2016/10/17 17:45:50 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int flag;
	int nb;

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
		nb = nb * 10 + (int)(str[i] - 48);
		i++;
	}
	return (nb * flag);
}
