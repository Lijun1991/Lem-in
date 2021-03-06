/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:34:02 by lwang             #+#    #+#             */
/*   Updated: 2017/05/30 22:34:04 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_range(int count, char **map)
{
	if (count > MAX_ROOM_TOTAL)
	{
		perror("unsupport too large map");
		deep_free(map);
		exit(1);
	}
}

int		check_dash_link(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && i >= 1 && s[i + 1])
		{
			if (!(s[i - 1] == ' ' && ft_isdigit(s[i + 1])))
				return (1);
		}
		i++;
	}
	return (0);
}

int		count_dash(char *s)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '-')
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int		ck_is_int(char *s)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	tmp = ft_ato_longlong(s);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (1);
	return (0);
}

char	*sep(char *s)
{
	char **tmp;
	char *dst;

	tmp = ft_strsplit(s, ' ');
	dst = ft_strdup(tmp[0]);
	deep_free(tmp);
	return (dst);
}
