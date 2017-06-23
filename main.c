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

// int		*get_ants_path(int *path, int len)
// {
// 	int *dst;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	dst = (int*)malloc(sizeof(int) * (len + 2));
// 	dst[i] = -1;
// 	i++;
// 	while (j < len)
// 	{
// 		dst[i] = path[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = -2;
// 	// i++;
// 	// dst[i] = -3;

// 	// int z=0;
// 	// while (z < len + 2)
// 	// {
// 	// 	ft_printf("%d ", dst[z]);
// 	// 	z++;
// 	// }
// 	// ft_printf("\n");

// 	return (dst);
// }

void	initial_ants(t_ant	**ants, int ants_total, int *path)
{
	int i;

	i = 0;
	ants = (t_ant**)malloc(sizeof(t_ant*) * ants_total);
	ft_memset(ants, 0, sizeof(t_ant*));
	while (i < ants_total)
	{
		ants[i]->cur_room = path[0];
		ants[i]->next_room = path[1];
		i++;
	}

	// int z=0;
	// while (z < )

}

void	get_ants_status(t_ant *ants, int *path, int indx_ant, int indx_room)
{
	ants[indx_ant].cur_room = path[indx_room];
	ants[indx_ant].next_room = path[indx_room + 1];
}

int		*get_path_taken(int *path, t_leminfo *info)
{
	int *dst;

	if (path)
		;
	dst = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset(dst, 0, sizeof(dst));
	return (dst);
}

void	update_path_taken(int *path_taken, int room_nbr, int *path)
{
	if (room_nbr != path[0])
	{
		path_taken[room_nbr] = 1;
		if (room_nbr > 0)
			path_taken[room_nbr - 1] = 0;
	}
}

void	move_ants(t_leminfo *info, int *path, int len, int ants_total)
{
	// int		*ants_path;
	int		*path_taken;
	t_ant	*ants;
	int		indx_ant;
	int		indx_room;

	ants = NULL;
	// ants_path = get_ants_path(path, len);
	path_taken = get_path_taken(path, info);
	initial_ants(&ants, ants_total, path);
	while (ants[ants_total - 1].cur_room != path[len - 1])
	{
		indx_ant = 0;
		indx_room = 0;
		while (indx_ant < ants_total)
		{
			if (!path_taken[ants[indx_ant].next_room] && ants[indx_ant].cur_room != path[len - 1])
			{
				get_ants_status(ants, path, indx_ant, indx_room);
				update_path_taken(path_taken, ants[indx_ant].cur_room, path);
				ft_printf("L%d-%d ", indx_ant + 1, path[indx_room]);
				indx_room++;
			}
			indx_ant++;
		}
		ft_printf("\n");
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
