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

int		*get_path_taken(t_leminfo *info)
{
	int *dst;

	dst = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset(dst, 0, sizeof(dst));

	// int z= 0;
	// while (z < info->room_total)
	// {
	// 	ft_printf("%d ", dst[z]);
	// 	z++;
	// }
	// ft_printf("\n");
	return (dst);
}

void	update_path_taken(int *path_taken, int room_nbr, int *path)
{
	if (room_nbr != path[0])
	{
		path_taken[room_nbr] = 1;
		if (room_nbr > path[1])
			path_taken[room_nbr - 1] = 0;
	}
}

char	*rename_base_room_nbr(int nbr, t_leminfo *info)
{
	int i;

	i = 0;
	while (info->room_name[i])
	{
		if (i == nbr)
			return (info->room_name[i]);
		i++;
	}
	return (NULL);
}

void	move_ants(t_leminfo *info, int *path, int path_len, int ants_total)
{
	int		*path_taken;
	int		tmp_path_len;
	int		ant_nbr;
	int		ant_reach_end;
	int		move_times;
	int		sign;

	path_taken = get_path_taken(info);
	move_times = path_len - 1 + ants_total - 1;

	ant_reach_end = 0;
	sign = 0;
	path_taken[path[0]] = 1;
	while (move_times)
	{
		ant_nbr = 1;
		if (ant_reach_end >= path_len - 1 + path_len - 2 + path_len - 3)
		{
			sign++;
			ant_nbr = ant_nbr + sign;
		}
		tmp_path_len = path_len - 1;
		while (tmp_path_len > 0)
		{
			// ft_printf("tmp_path_len is %d, path_taken[path[tmp_path_len - 1]] is %d, path_taken[path[tmp_path_len] is %d\n", tmp_path_len, path_taken[path[tmp_path_len - 1]], path_taken[path[tmp_path_len]]);
			if (path_taken[path[tmp_path_len - 1]] && !(path_taken[path[tmp_path_len]]))
			{
				if (ant_nbr <= ants_total)
					ft_printf("L%d-%s ", ant_nbr, rename_base_room_nbr(path[tmp_path_len], info));
				ant_reach_end++;
				if (tmp_path_len != path_len - 1)
					path_taken[path[tmp_path_len]] = 1;
				if (tmp_path_len != 1)
					path_taken[path[tmp_path_len - 1]] = 0;
				ant_nbr++;
			}
			tmp_path_len--;
		}
		ft_printf("\n");
		move_times--;
	}
}

int	print_lemin_result(t_leminfo *info, char **map)
{
	int		**adj;
	int		*final_path;
	int		ants_total;

	ants_total = ft_atoi(info->nbr_of_ant);

	print_map(map, info);
	adj = get_adj_matrix(info);
	solve_adj_matrix(adj, info);
	if (!(final_path = pick_path(info)))
		return (0);

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
	map = (char**)malloc(sizeof(char*) * (10000 + 1));
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
}
