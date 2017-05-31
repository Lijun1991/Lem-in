/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:12:23 by lwang             #+#    #+#             */
/*   Updated: 2017/05/30 21:12:25 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	check_nbr_of_ants(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] > 57 || s[i] < 48)
		{
			ft_printf("nbr is %c\n", s[i]);
			return (1);
		}
		i++;
	}
	if (s[0] == '0')
		return (1);
	return (0);
}

int	check_dash(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

// int	check_room_link(char **info)
// {

// }

int	validate_map(char **map, t_leminfo *info)
{
	int i;

	i = 0;
	while (map[i])
	{
		while (map[i][0] == '#')
			i++;
		if (!info->nbr_of_ant)
		{
			info->nbr_location = i;
			info->nbr_of_ant = ft_strdup(map[i]);
			ft_printf("indise nbr_of_ant is %s\n", info->nbr_of_ant);
		}
		i++;
		while (!check_dash(map[i]))
		{
			if (!ft_strcmp(map[i], "##start\n"))
				info->count_start++;
			if (!ft_strcmp(map[i], "##end\n"))
				info->count_end++;
			i++;
		}
		if (info->link_location == 0)
			info->link_location = i;
		i++;
		ft_printf("2indise nbr_of_ant is %s\n", info->nbr_of_ant);
	}
	ft_printf("nbr_of_ant is %s\n", info->nbr_of_ant);
	// if (info->count_end != 1 || info->count_start != 1 || (check_nbr_of_ants(info->nbr_of_ant)))
	// 	return (1);
	// if (check_room_link(map))
	// 	return (1);
	return (0);
}

int main(void)
{
	int		r;
	char	*line;
	char	**map;
	t_leminfo info;

	ft_memset(&info, 0, sizeof(info));
	map = (char**)malloc(sizeof(char*) * (10000 + 1));
	while ((r = get_next_line(0, &line)) && r != -1)
	{
		map[info.count_line] = ft_strdup(line);
		info.count_line++;
		free(line);
		line = NULL;
	}
	map[info.count_line] = NULL;
	free(line);
	check_range(info.count_line, map);
	if (validate_map(map, &info))
	{
		deep_free(map);
		perror("Invalid map");
		return (1);
	}
}
