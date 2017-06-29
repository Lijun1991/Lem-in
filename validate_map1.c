/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:04:23 by lwang             #+#    #+#             */
/*   Updated: 2017/05/31 20:04:25 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_hash_hash(char **map, t_leminfo *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_location)
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") || map[i][0] == '\0')
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
	while (map[i])
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") || map[i][0] == '\0')
			return (1);
		if (map[i][0] != '#')
			info->count_link++;
		i++;
	}
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

int		get_room(char **map, t_leminfo *info)
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
			if (!(info->room_name[j] = ft_strdup(info->tmp_room_name[0])) \
				|| !(info->room_x[j] = ft_strdup(info->tmp_room_name[1])) \
				|| !(info->room_y[j] = ft_strdup(info->tmp_room_name[2])) \
				|| info->tmp_room_name[3])
				return (1);
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

int		ck_link_repeat(t_leminfo *info)
{
	int i;
	int j;
	char **tmp;

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

int		ck_is_room(char *s, t_leminfo *info)
{
	int i;

	i = 0;
	while (info->room_name[i])
	{

		if (!ft_strcmp(info->room_name[i], s))
			return (1);
		i++;
	}
	return (0);
}

int		ck_start_end(char **map, t_leminfo *info)
{
	int i;

	i = info->nbr_location + 1;
	while (i < info->link_location)
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end"))
		{
			i++;
			if (map[i][0] == '#' || map[i][0] == 'L' \
				|| i >= info->link_location)
				return (1);
		}
		i++;
	}
	return (0);
}

static int		check_map_helper(char **map, t_leminfo *info)
{
	if (get_check_link(map, info))
	{
		free(info->nbr_of_ant);
		free_room(info, map);
		deep_free(info->link);
		deep_free(info->tmp_link);
		return (1);
	}
	if (ck_link_repeat(info) || ck_start_end(map, info))
	{
		free(info->nbr_of_ant);
		free_room(info, map);
		deep_free(info->link);
		return (1);
	}
	return (0);
}

int		check_map(char **map, t_leminfo *info)
{
	if (info->count_end != 1 || info->count_start != 1)
	{
		free(info->nbr_of_ant);
		deep_free(map);
		return (1);
	}
	if (check_nbr_of_ants(info->nbr_of_ant) || check_hash_hash(map, info))
	{
		free(info->nbr_of_ant);
		deep_free(map);
		return (1);
	}
	if (get_room(map, info) || check_room(info))
	{
		free(info->nbr_of_ant);
		deep_free(info->tmp_room_name);
		free_room(info, map);
		return (1);
	}
	if (check_map_helper(map, info))
		return (1);
	return (0);
}

void	validate_map(char **map, t_leminfo *info)
{
	int	i;

	i = 0;
	while (map[i])
	{
		while (map[i] && map[i][0] == '#')
			i++;
		if (!info->nbr_of_ant)
		{
			info->nbr_location = i;
			info->nbr_of_ant = ft_strdup(map[i]);
		}
		i++;
		while ( map[i] && !check_dash(map[i]))
		{
			if (!ft_strcmp(map[i], "##start"))
				info->count_start++;
			if (!ft_strcmp(map[i], "##end"))
				info->count_end++;
			i++;
		}
		if (info->link_location == 0)
			info->link_location = i;
		i++;
	}
}
