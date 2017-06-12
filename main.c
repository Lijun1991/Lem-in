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

// void	move_ants(t_leminfo *info, int *path, int len)
// {
// 	int nbr;
// 	int i;
// 	int j;
// 	int tmp;

// 	i = 1;
// 	j = 1;
// 	tmp = 0;
// 	nbr = ft_atoi(info->nbr_of_ant);
// 	while (i <= len)
// 	{
// 		tmp = i;
// 		j = 1;
// 		while (tmp > 0 && path[tmp - j] != -10)
// 		{
// 			while (j <= tmp && j <= nbr && path[tmp - j] != -10)
// 			{
// 				ft_printf("L%d-%d%c", j, path[tmp - j], j < tmp && j < nbr ? ' ' : '\n');
// 				j++;
// 			}
// 			tmp--;
// 		}
// 		i++;
// 	}
// 	ft_printf("here\n");
// 	i--;
// 	j = 1;
// 	tmp = 0;
// 	int 	tmp1;
// 	tmp1 = 3;
// 	while (j <= nbr - 1)
// 	{
// 		tmp = nbr - j;
// 		tmp1--;
// 		i = 4;
// 		while (tmp > 0 && path[i - 1] != -10 && tmp1 <= nbr)
// 		{
// 			ft_printf("L%d-%d ", tmp1, path[i - 1]);
// 			tmp--;
// 			i--;
// 			tmp1++;
// 		}
// 		ft_printf("\n");
// 		j++;
// 	}
// }

int		*change_path(int *path, int len)
{
<<<<<<< HEAD
	int *dst;
=======
	int nbr;
>>>>>>> 034644dbf392a9287d57d49730c9cd4f3d5630ab
	int i;
	int j;

	i = 0;
	j = 1;
<<<<<<< HEAD
	dst = (int*)malloc(sizeof(int) * (len + 2));
	dst[0] = -1;
	while (i < len)
	{
		dst[j] = path[i];
		i++;
		j++;
	}
	dst[j] = -2;
	return (dst);
}

void	check_all_ants(t_ant **ants, int *stack, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (ants[i]->room)
	}
}

void	moveing(int *stack, int *path, int nbr, t_ant **ants)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (i > 0 && i != nbr + 1)
			stack[i - 1] = 0;
		stack[i] = 1;
		ants[i]->room = path[i];
		check_all_ants(ants, stack, nbr);
		i++;
	}
	

}

void	move_ants(t_leminfo *info, int *path, int len)
{
	// if (path)
	// 	;
	int nbr;
	int	i;
	int *stack;
	t_ant **ants;
	t_path **path

	i = 0;
=======
	tmp = 0;
>>>>>>> 034644dbf392a9287d57d49730c9cd4f3d5630ab
	nbr = ft_atoi(info->nbr_of_ant);
	stack = (int*)malloc(sizeof(int) * len);
	ft_memset(stack, 0, len);
	ants = (t_ant**)malloc(sizeof(t_ant*) * nbr);
	while (i < nbr)
	{
		ants[i] = (t_ant*)malloc(sizeof(t_ant));
		ants[i]->indx = i;
		ants[i]->room = -1;
		i++;
	}
	// i = 0;
	// while (i < nbr)
	// {
	// 	ft_printf("%d, %d\n", ants[i]->indx, ants[i]->room);
	// 	i++;
	// }
	path = change_path(path, len);
	moveing(stack, path, nbr, ants);
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
