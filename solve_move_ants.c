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
	int	*dst;

	dst = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset(dst, 0, sizeof(int) * info->room_total);
	return (dst);
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

void	check_n_move(int *path_taken, int *path, t_ant *ant, t_leminfo *info)
{
	if (ant->ant_nbr <= ant->ants_total)
		ft_printf("L%d-%s ", ant->ant_nbr, \
			rename_base_room_nbr(path[ant->tmp_path_len], info));
	if (ant->tmp_path_len != ant->path_len - 1)
		path_taken[path[ant->tmp_path_len]] = 1;
	if (ant->tmp_path_len != 1)
		path_taken[path[ant->tmp_path_len - 1]] = 0;
	ant->ant_reach_end++;
	ant->ant_nbr++;
}

void	initial_ant(t_ant *ant, int path_len, int ants_total)
{
	ant->move_times = path_len - 1 + ants_total - 1;
	ant->ant_reach_end = 0;
	ant->sign = 0;
	ant->tmp_path_len = 0;
	ant->ant_nbr = 0;
	ant->path_len = path_len;
	ant->ants_total = ants_total;
}

void	move_ants(t_leminfo *info, int *path, int path_len, int ants_total)
{
	int		*path_taken;
	t_ant	ant;

	initial_ant(&ant, path_len, ants_total);
	path_taken = get_path_taken(info);
	path_taken[path[0]] = 1;
	while (ant.move_times)
	{
		ant.ant_nbr = 1;
		if (ant.ant_reach_end >= path_len - 1 + path_len - 2 + path_len - 3)
			ant.sign++;
		ant.ant_nbr = ant.ant_nbr + ant.sign;
		ant.tmp_path_len = path_len - 1;
		while (ant.tmp_path_len > 0)
		{
			if (path_taken[path[ant.tmp_path_len - 1]] \
				&& !(path_taken[path[ant.tmp_path_len]]))
				check_n_move(path_taken, path, &ant, info);
			ant.tmp_path_len--;
		}
		ft_printf("\n");
		ant.move_times--;
	}
	free(path_taken);
}
