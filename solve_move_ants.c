/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_move_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:05:38 by lwang             #+#    #+#             */
/*   Updated: 2017/06/28 08:05:40 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*get_path_taken(t_leminfo *info)
{
	int *dst;

	dst = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset(dst, 0, sizeof(int) * info->room_total);
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
			sign++;
		ant_nbr = ant_nbr + sign;
		tmp_path_len = path_len - 1;
		while (tmp_path_len > 0)
		{
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
	free(path_taken);
}
