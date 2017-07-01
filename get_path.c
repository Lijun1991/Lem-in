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

int				num_linked_room_name(char *room_name, t_leminfo *info)
{
	int i;

	i = 0;
	while (info->room_name[i])
	{
		if (!ft_strcmp(info->room_name[i], room_name))
			return (i);
		i++;
	}
	return (0);
}

static void		fill_adj_matrix(t_leminfo *info, int **adj)
{
	char	**tmp;
	int		i;

	i = 0;
	while (info->link[i])
	{
		tmp = ft_strsplit(info->link[i], '-');
		adj[num_linked_room_name(tmp[0], info)]\
		[num_linked_room_name(tmp[1], info)] = 1;
		adj[num_linked_room_name(tmp[1], info)]\
		[num_linked_room_name(tmp[0], info)] = 1;
		deep_free(tmp);
		i++;
	}
}

int				**get_adj_matrix(t_leminfo *info)
{
	int **adj;
	int i;
	int j;

	i = 0;
	j = 0;
	while (info->room_name[i])
		i++;
	info->room_total = i;
	adj = (int**)malloc(sizeof(int*) * i);
	ft_memset(adj, 0, sizeof(int*) * i);
	while (j < info->room_total)
	{
		adj[j] = (int*)malloc(sizeof(int) * info->room_total);
		ft_memset(adj[j], 0, (sizeof(int) * info->room_total));
		j++;
	}
	fill_adj_matrix(info, adj);
	return (adj);
}

int				*get_dst(int len, t_leminfo *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->count_path)
	{
		j = 0;
		while (info->path[i][j] != -10)
			j++;
		if (j == len)
			return (info->path[i]);
		i++;
	}
	return (NULL);
}

int				*pick_path(t_leminfo *info)
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
	return (get_dst(len, info));
}
