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

int	print_lemin_result(t_leminfo *info, char **map)
{
	int		**adj;
	int		*final_path;
	int		ants_total;

	ants_total = ft_atoi(info->nbr_of_ant);

	print_map(map, info);
	adj = get_adj_matrix(info);
	info->v = solve_adj_matrix(adj, info);
	if (!(final_path = pick_path(info)))
	{
		free_everything(info, map);
		perror("Invalid map");
		return (1);
	}
	int z=0;
	ft_printf("\n");
	while (final_path[z] != -10)
	{
		ft_printf("%d ", final_path[z]);
		z++;
	}
	ft_printf("\n");
	ft_printf("\n");

	move_ants(info, final_path, z, ants_total);
	return (0);
}

int	main(void)
{
	int			r;
	char		*line;
	char		**map;
	t_leminfo	info;

	ft_memset(&info, 0, sizeof(t_leminfo));
	map = (char**)malloc(sizeof(char*) * (MAX_ROOM_TOTAL + 1));
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
	if (print_lemin_result(&info, map))
		return (1);
	free_everything(&info, map);
}
