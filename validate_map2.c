/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:04:37 by lwang             #+#    #+#             */
/*   Updated: 2017/05/31 20:04:39 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_nbr_of_ants(char *s)
{
	int i;

	i = 0;
	if (!s || ft_strlen(s) > 10 || s[0] == '0')
		return (1);
	while (s[i])
	{
		if (s[i] > 57 || s[i] < 48)
			return (1);
		i++;
	}
	if (ft_ato_longlong(s) > 2147483647 || ft_ato_longlong(s) < 1)
		return (1);
	return (0);
}

int		ck_is_int(char *s)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	tmp = ft_ato_longlong(s);
	if (tmp > 2147483647)
		return (1);
	return (0);
}

int		ck_is_room_name(char *s, t_leminfo *info)
{
	int	i;

	i = 0;
	while (info->room_name[i])
	{
		if (!ft_strcmp(info->room_name[i], s))
			return (1);
		i++;
	}
	return (0);
}

int		check_room(t_leminfo *info)
{
	int i;

	i = 0;
	if (info->count_room < 2 || info->count_link < 1)
		return (1);
	while (info->room_name[i])
	{
		if (info->room_name[i][0] == 'L')
			return (1);
		i++;
	}
	i = 0;
	while (info->room_x[i])
	{
		if (ck_is_int(info->room_x[i]))
			return (1);
		i++;
	}
	i = 0;
	while (info->room_y[i])
	{
		if (ck_is_int(info->room_y[i]))
			return (1);
		i++;
	}
	return (0);
}

int		get_check_link(char **map, t_leminfo *info)
{
	int i;
	int j;

	i = info->link_location;
	j = 0;
	info->link = (char**)malloc(sizeof(char*) * (info->count_link + 1));
	ft_memset(info->link, 0, sizeof(char*) * (info->count_link + 1));
	while (map[i])
	{
		if (map[i][0] != '#')
		{
			info->tmp_link = ft_strsplit(map[i], '-');
			if (count_dash(map[i]))
				return (1);
			if (!info->tmp_link[0] || !info->tmp_link[1] || info->tmp_link[2])
				return (1);
			if (!ck_is_room_name(info->tmp_link[0], info) || !ck_is_room_name(info->tmp_link[1], info))
				return (1);
			if (!ft_strcmp(info->tmp_link[0], info->tmp_link[1]))
				return (1);
			info->link[j] = ft_strdup(map[i]);
			deep_free(info->tmp_link);
			j++;
		}
		i++;
	}
	info->link[j] = NULL;
	return (0);
}
