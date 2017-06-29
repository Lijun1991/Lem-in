/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:40:45 by lwang             #+#    #+#             */
/*   Updated: 2017/06/01 18:40:48 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_start_room(char **map, t_leminfo *info)
{
	int i;

	i = info->nbr_location + 1;
	while (i < info->link_location)
	{
		if (!ft_strcmp(map[i], "##start"))
		{
			i++;
			break ;
		}
		i++;
	}
	info->start = ft_strdup(map[i]);
	return (map[i]);
}

char	*get_end_room(char **map, t_leminfo *info)
{
	int i;

	i = info->nbr_location + 1;
	while (i < info->link_location)
	{
		if (!ft_strcmp(map[i], "##end"))
		{
			i++;
			break ;
		}
		i++;	
	}
	info->end = ft_strdup(map[i]);
	return (map[i]);
}

void	print_normal_room(char **map, t_leminfo *info, char *start, char *end)
{
	int i;

	i = info->nbr_location + 1;
	while (i < info->link_location)
	{
		if (map[i][0] != '#' && ft_strcmp(map[i], start) \
			&& ft_strcmp(map[i], end))
			ft_printf("%s\n", map[i]);
		i++;
	}
}

void	print_link(t_leminfo *info)
{
	int i;

	i = 0;
	while (info->link[i])
	{
		ft_printf("%s\n", info->link[i]);
		i++;
	}
}

void	print_map(char **map, t_leminfo *info)
{
	char *start;
	char *end;

	start = get_start_room(map, info);
	end = get_end_room(map, info);
	ft_printf("%s\n", info->nbr_of_ant);
	ft_printf("##start\n%s\n", start);
	ft_printf("##end\n%s\n", end);
	print_normal_room(map, info, start, end);
	print_link(info);
}

