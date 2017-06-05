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

char		*sep(char *s)
{
	char **tmp;

	tmp = ft_strsplit(s, ' ');
	return (tmp[0]);
}

// int			loc(char *s, char ***adj)
// {
// 	int i;

// 	i = 0;
// 	// ft_printf("s is %s\n", s);
// 	while (adj[i])
// 	{
// 		if (!ft_strcmp(adj[i][0], s))
// 			return (i);
// 		i++;
// 	}
// 	ft_printf("sth not right happened\n");
// 	return (0);
// }

// int			test_vist(char *s, char **path)
// {
// 	int i;

// 	i = 0;
// 	while (path[i])
// 	{
// 		if (!ft_strcmp(path[i], s))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int			check_end(t_leminfo *info)
// {
// 	int i;

// 	i = 0;
// 	while (info->path[i])
// 		i++;
// 	if (!ft_strcmp(info->path[i - 1], sep(info->end)))
// 		return (1);
// 	return (0);
// }

// char		**remove_last(char **path)
// {
// 	int i;
// 	int len;
// 	char **dst;

// 	i = 0;
// 	while (path[i])
// 		i++;
// 	ft_printf("i is %d\n", i);
// 	len = i - 1;
// 	i = 0;
// 	dst = (char**)malloc(sizeof(char*) * (len + 1));
// 	while (i < len)
// 	{
// 		dst[i] = ft_strdup(path[i]);
// 		i++;
// 	}

// 	int z=0;
// 	while (dst[z])
// 	{
// 		ft_printf("tmp path is %s\n", dst[z]);
// 		z++;
// 	}
// 	deep_free(path);
// 	return (dst);
// }

// void		find_path_till(t_leminfo *info, char ***adj, int i, int j)
// {
// 	int tmp;
	
// 	ft_printf("the %dth path is info->path[i] is %s\n", i, info->path[i]);
// 	if (check_end(info))
// 	{
// 		ft_printf("haha, found one\n");
// 		int z=0;
// 		while (info->path[z])
// 		{
// 			ft_printf("%s\n", info->path[z]);
// 			z++;
// 		}
// 	}
// 	else
// 	{
// 		tmp = loc(info->path[i], adj);
// 		while (adj[tmp][j])
// 		{	
// 			ft_printf("room in adj location is %d choose %dth one connected with room, adj[tmp][j] is %s\n", tmp, j, adj[tmp][j]);
// 			if (!test_vist(adj[tmp][j], info->path))
// 			{
// 				info->path[i + 1] = ft_strdup(adj[tmp][j]);
// 				info->path[i + 2] = NULL;
// 				ft_printf("now path is: ");
// 				int z=0;
// 				while (info->path[z])
// 				{
// 					ft_printf("%s ", info->path[z]);
// 					z++;
// 				}
// 				ft_printf("done\n");
// 				find_path_till(info, adj, ++i, j);
// 			}
// 			// else
// 			j++;
// 		}
// 	}
// 	info->path = remove_last(info->path);
// 	// j--;
// }

// void		find_one_path(t_leminfo *info, char ***adj)
// {
// 	int i;
// 	int j;
// 	int tmp;

// 	i = 0;
// 	j = 1;
// 	tmp = 0;
// 	info->path = (char**)malloc(sizeof(char*) * (info->room_total + 1));
// 	info->path[i] = ft_strdup(sep(info->start));
// 	info->path[i + 1] = NULL;
// 	find_path_till(info, adj, i, j);
// }

// char	**find_edges(char *name, t_leminfo *info)
// {
// 	char	**dst;
// 	char	**tmp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 1;
// 	tmp = NULL;
// 	dst = NULL;
// 	dst = (char**)malloc(sizeof(char*) * (info->room_total + 1));
// 	dst[0] = ft_strdup(name);
// 	while (info->link[i])
// 	{
// 		tmp = ft_strsplit(info->link[i], '-');
// 		if (!ft_strcmp(tmp[0], name))
// 		{
// 			dst[j] = ft_strdup(tmp[1]);
// 			j++;
// 		}
// 		if (!ft_strcmp(tmp[1], name))
// 		{
// 			dst[j] = ft_strdup(tmp[0]);
// 			j++;
// 		}
// 		deep_free(tmp);
// 		tmp = NULL;
// 		i++;
// 	}
// 	dst[j] = NULL;

// 	// int f = 0;
// 	// while (dst[f])
// 	// {
// 	// 	ft_printf("%s\n", dst[f]);
// 	// 	f++;
// 	// }
// 	return (dst);
// }

// char	***get_adj_list(t_leminfo *info)
// {
// 	int i;
// 	char ***adj;
// 	// char **adj;

// 	i = 0;
// 	while (info->room_name[i])
// 		i++;
// 	info->room_total = i;
// 	adj = (char***)malloc(sizeof(char**) * (i + 1));
// 	i = 0;
// 	while (info->room_name[i])
// 	{
// 		adj[i] = find_edges(info->room_name[i], info);
// 		i++;
// 	}
// 	adj[i] = NULL;

// 	int j = 0;
// 	while (adj[j])
// 	{
// 		i = 0;
// 		while (adj[j][i])
// 			ft_printf("\n%s ", adj[j][i++]);
// 		ft_printf("\n");
// 		j++;
// 	}
// 	return (adj);
// }

int	**get_adj_matrix(t_leminfo *info)
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
	// ft_printf("j is %d\n", j);
	while (info->link[i])
	{
		tmp = ft_strsplit(info->link[i], '-');
		// ft_printf("ft_atoi(tmp[0] is %d, ft_atoi(tmp[1] is %d\n", ft_atoi(tmp[0]), ft_atoi(tmp[1]));
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


int	print_lemin_result(t_leminfo *info, char **map)
{
	int		**adj;

	print_map(map, info);

	adj = get_adj_matrix(info);

	solve_adj_matrix(adj, info);

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
