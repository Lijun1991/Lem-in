/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:23:00 by lwang             #+#    #+#             */
/*   Updated: 2017/06/30 17:23:02 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_hash_in_link(char **map, int i, t_leminfo *info)
{
	while (map[i])
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") \
			|| map[i][0] == '\0')
			return (1);
		if (map[i][0] != '#')
			info->count_link++;
		i++;
	}
	return (0);
}

int			check_hash_hash(char **map, t_leminfo *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_location)
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") \
			|| map[i][0] == '\0')
			return (1);
		i++;
	}
	i++;
	while (i < info->link_location)
	{
		if (map[i][0] == '\0')
			return (1);
		if (map[i][0] != '#')
			info->count_room++;
		i++;
	}
	if (check_hash_in_link(map, i, info))
		return (1);
	return (0);
}

static void	prepare(t_leminfo *info)
{
	info->room_name = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	ft_memset(info->room_name, 0, sizeof(char*) * (info->count_room + 1));
	info->room_x = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	ft_memset(info->room_x, 0, sizeof(char*) * (info->count_room + 1));
	info->room_y = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	ft_memset(info->room_y, 0, sizeof(char*) * (info->count_room + 1));
}

int			get_room(char **map, t_leminfo *info)
{
	int	i;
	int	j;

	i = info->nbr_location + 1;
	j = 0;
	prepare(info);
	while (i < info->link_location)
	{
		if (map[i][0] != '#')
		{
			info->tmp_room_name = ft_strsplit(map[i], ' ');
			if (C1 || C2 || C3 || info->tmp_room_name[3])
			{
				deep_free(info->tmp_room_name);
				return (1);
			}
			deep_free(info->tmp_room_name);
			j++;
		}
		i++;
	}
	info->room_name[j] = NULL;
	info->room_x[j] = NULL;
	info->room_y[j] = NULL;
	return (0);
}

int			ck_link_repeat(t_leminfo *info)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = info->link;
	i = 0;
	while (info->link[i])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (!ft_strcmp(tmp[j], info->link[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
