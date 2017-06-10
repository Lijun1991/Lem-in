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

void	move_ants(t_leminfo *info, int *path, int len)
{
	int nbr;
	int i;
	int j;
	int tmp;

	i = 1;
	j = 1;
	tmp = 0;
	nbr = ft_atoi(info->nbr_of_ant);
	while (i <= len + nbr - 1)
	{
		tmp = i > nbr ? nbr : i;
		while (tmp > 0)
		{
			j = 1;
			while (j <= tmp)
			{
			// 	ft_printf("tmp is %d\n", tmp);
				ft_printf("L%d-%d ", j, path[tmp - j]);
				j++;
			}
			tmp--;
		}
		// stack[i] = 1;
		// j = 0;
		// while (j < i && j && j - 1)
		// {
		// 	ft_printf("L%d-%d ", j, path[j - 1]);
		// 	j++;
		// }
		ft_printf("\n");
		i++;
	}
}

int	print_lemin_result(t_leminfo *info, char **map)
{
	int		**adj;
	int		*final_path;

	print_map(map, info);
	adj = get_adj_matrix(info);
	solve_adj_matrix(adj, info);
	final_path = pick_path(info);

	int z=0;
	ft_printf("\n");
	while (final_path[z] != -10)
	{
		ft_printf("%d ", final_path[z]);
		z++;
	}
	ft_printf("\n");
	ft_printf("\n");
	move_ants(info, final_path, z);
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
