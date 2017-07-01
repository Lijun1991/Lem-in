/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:45:42 by lwang             #+#    #+#             */
/*   Updated: 2017/06/28 08:45:44 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_vertex(t_vertex *v, t_leminfo *info)
{
	int i;

	i = 0;
	while (i < info->room_total)
	{
		free(v->graph[i]);
		i++;
	}
	free(v->graph);
	v->graph = NULL;
	free(v->path);
	free(v->visited);
	free(v);
}

void	deep_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	deep_free_path(int **path)
{
	int i;

	i = 0;
	while (i < MAX_ROOM_TOTAL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	free_room(t_leminfo *info, char **map)
{
	deep_free(map);
	deep_free(info->room_name);
	deep_free(info->room_x);
	deep_free(info->room_y);
}

void	free_everything(t_leminfo *info, char **map)
{
	free_vertex(info->v, info);
	deep_free(map);
	free(info->nbr_of_ant);
	free(info->start);
	free(info->end);
	deep_free(info->room_name);
	deep_free(info->room_x);
	deep_free(info->room_y);
	deep_free(info->link);
	deep_free_path(info->path);
}
