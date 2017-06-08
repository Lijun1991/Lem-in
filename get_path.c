/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:39:33 by lwang             #+#    #+#             */
/*   Updated: 2017/06/08 13:39:34 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*sep(char *s)
{
	char **tmp;

	tmp = ft_strsplit(s, ' ');
	return (tmp[0]);
}

int			**get_adj_matrix(t_leminfo *info)
{
	int **adj;
	char **tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (info->room_name[i])
		i++;
	info->room_total = i;
	adj = (int**)malloc(sizeof(int*) * i);

	i = 0;
	while (j < info->room_total)
	{
		adj[j] = (int*)malloc(sizeof(int) * info->room_total);
		ft_memset(adj[j], 0, (sizeof(int) * info->room_total));
		j++;
	}
	while (info->link[i])
	{
		tmp = ft_strsplit(info->link[i], '-');
		adj[ft_atoi(tmp[0])][ft_atoi(tmp[1])] = 1;
		adj[ft_atoi(tmp[1])][ft_atoi(tmp[0])] = 1;
		i++;
	}

	int z=0;
	while (z < info->room_total)
	{
		int x=0;
		while (x < info->room_total)
		{
			ft_printf("%d ", adj[z][x]);
			x++;
		}
		ft_printf("\n");
		z++;
	}
	return (adj);
}

int			*get_dst(int len, t_leminfo *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->count_path)
	{
		j = 0;
		while (info->path[i][j] != -10)
		{
			j++;
		}
		if (j == len)
			return (info->path[i]);
	}
	ft_printf("sth wrong\n");
	return (NULL);
}

int			*pick_path(t_leminfo *info)
{
	int i;
	int j;
	int	len;

	i = 0;
	len = info->room_total;
	while (i < info->count_path)
	{
		j = 0;
		while (info->path[i][j] != -10)
			j++;
		len = j > len ? len : j;
		i++;
	}
	// ft_printf("len is %d\n", len);
	return (get_dst(len, info));
}
