/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_adj_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:45:17 by lwang             #+#    #+#             */
/*   Updated: 2017/06/05 11:45:19 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_stack_element(int indx, int *path, t_leminfo *info)
{
	int i;

	i = 0;

	// ft_printf("info->count_path is %d, indx is %d\n", info->count_path, indx);
	info->path[info->count_path] = (int*)malloc(sizeof(int) * (indx + 1));
	while (i < indx)
	{
		// ft_printf("%d ", path[i]);
		info->path[info->count_path][i] = path[i];
		i++;
	}
	// ft_printf("\n");
	info->path[info->count_path][i] = -10;
	// ft_printf("info->count_path is %d\n", info->count_path);
	info->count_path++;
}

static void	print_path(int src, int dest, t_vertex *v, t_leminfo *info)
{
	int i;

	i = 0;
	v->visited[src] = true;
	v->path[v->indx] = src;
	v->indx++;
	if (src == dest)
	{
		print_stack_element(v->indx, v->path, info);
	}
	else
	{
		i = 0;
		while (i < v->N)
		{
			if (v->visited[i] == false && v->graph[src][i])
				print_path(i, dest, v, info);
			i++;
		}
	}
	v->visited[src] = false;
	v->indx--;
}

t_vertex		*solve_adj_matrix(int **adj, t_leminfo *info)
{
	t_vertex *v;
	int		src;
	int		dest;
	char	*start;
	char	*end;

	// v = NULL;
	v = (t_vertex*)malloc(sizeof(t_vertex));
	ft_memset(v, 0, sizeof(t_vertex));
	v->graph = adj;
	v->N = info->room_total;
	v->path = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset(v->path, 0, sizeof(int) * info->room_total);
	v->visited = (int*)malloc(sizeof(int) * info->room_total);
	ft_memset (v->visited, 0, sizeof(int) * info->room_total);

	int y=0;
	while (y < info->room_total)
	{
		ft_printf("%d\n", v->visited[y]);
		y++;
	}


	info->count_path = 0;
	info->path = (int**)malloc(sizeof(int*) * (MAX_ROOM_TOTAL + 1));
	ft_memset(info->path, 0, sizeof(int*) * (MAX_ROOM_TOTAL + 1));
	ft_printf("\n");
	start = sep(info->start);
	end = sep(info->end);
	src = num_linked_room_name(start, info);
	dest = num_linked_room_name(end, info);
	free(start);
	free(end);
	print_path(src, dest, v, info);
	return (v);	
}
