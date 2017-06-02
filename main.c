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

char	**find_edges(char *name, t_leminfo *info)
{
	char	**dst;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	tmp = NULL;
	dst = (char**)malloc(sizeof(char*) * (info->room_total + 1));
	dst[0] = ft_strdup(name);
	while (info->link[i])
	{
		tmp = ft_strsplit(info->link[i], '-');
		if (!ft_strcmp(tmp[0], name))
		{
			dst[j] = ft_strdup(tmp[1]);
			j++;
		}
		if (!ft_strcmp(tmp[1], name))
		{
			dst[j] = ft_strdup(tmp[0]);
			j++;
		}
		deep_free(tmp);
		tmp = NULL;
		i++;
	}
	dst[j] = NULL;
	return (dst);
}

char	***get_adj_list(t_leminfo *info)
{
	int i;
	char ***adj;

	i = 0;
	while (info->room_name[i])
		i++;
	info->room_total = i;
	adj = (char***)malloc(sizeof(char**) * (i + 1));
	i = 0;
	while (info->room_name[i])
	{
		adj[i] = find_edges(info->room_name[i], info);
		i++;
	}
	adj[i] = NULL;

	int j = 0;
	while (adj[j])
	{
		ft_printf("\n%s %s %s %s %s\n", adj[j][0], adj[j][1], adj[j][2], adj[j][3], adj[j][4]);
		j++;
	}

	return (adj);
}

void	print_lemin_result(t_leminfo *info, char **map)
{
	char ***adj;
	print_map(map, info);
	adj = get_adj_list(info);
	get_all_paths(info->start, info->end);
}

int	main(void)
{
	int			r;
	char		*line;
	char		**map;
	t_leminfo	info;

	ft_memset(&info, 0, sizeof(t_leminfo));
	map = (char**)malloc(sizeof(char*) * (10000 + 1));
	r = -100;
	while ((r = get_next_line(0, &line)) && r != -1)
	{
		map[info.count_line] = ft_strdup(line);
		info.count_line++;
		free(line);
	}
	map[info.count_line] = NULL;
	check_range(info.count_line, map);

	validate_map(map, &info);
	if (check_map(map, &info))
	{
		deep_free(map);
		perror("Invalid map");
		return (1);
	}
	print_lemin_result(&info, map);
}
