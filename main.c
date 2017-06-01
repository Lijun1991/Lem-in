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

int	check_nbr_of_ants(char *s)
{
	int i;

	i = 0;
	if (ft_strlen(s) > 10)
		return (1);
	while (s[i])
	{
		if (s[i] > 57 || s[i] < 48)
		{
			ft_printf("nbr is %c\n", s[i]);
			return (1);
		}
		i++;
	}
	if (s[0] == '0' || ft_ato_longlong(s) > 2147483647)
		return (1);
	return (0);
}

int	check_dash(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ck_is_int(char *s)
{
	int i;
	long long	tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	tmp = ft_ato_longlong(s);
	if (tmp > 2147483647)
		return (1);
	return (0);
}

int		ck_is_room_name(char *s, t_leminfo *info)
{
	int i;

	i = 0;
	while (info->room_name[i])
	{
		if (!ft_strcmp(info->room_name[i], s))
			return (1);
		i++;
	}
	return (0);
}

int	count_hash(char *s)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '-')
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

// int		check_link(t_leminfo *info, char **map)
// {
// 	char **tmp;
// 	int		i;

// 	i = info->link_location;
// 	tmp = NULL;
// 	while (map[i])
// 	{
// 		if (count_hash(map[i]))
// 			return (1);
// 		tmp = ft_strsplit(map[i], '-');
// 		if (!tmp[0] || !tmp[1] || tmp[2])
// 			return (1);
// 		if (!ck_is_room_name(tmp[0], info) || !ck_is_room_name(tmp[1], info))
// 			return (1);
// 		if (!ft_strcmp(tmp[0], tmp[1]))
// 			return (1);
// 		i++;
// 	}
// 	deep_free(tmp);
// 	return (0);
// }


int		check_room(t_leminfo *info)
{
	int i;

	i = 0;
	if (info->count_room < 2 || info->count_link < 1)
		return (1);
	while (info->room_x[i])
	{
		if (ck_is_int(info->room_x[i]))
			return (1);
		i++;
	}
	i = 0;
	while (info->room_y[i])
	{
		if (ck_is_int(info->room_y[i]))
			return (1);
		i++;
	}
	return (0);
}

int		get_link(char **map, t_leminfo *info)
{
	int i;

	i = info->link_location;
	while (map[i])
	{
		if (map[i][0] != '#')
		{
			if (count_hash(map[i]))
				return (1);
			info->tmp_link = ft_strsplit(map[i], '-');
			if (!info->tmp_link[0] || !info->tmp_link[1] || info->tmp_link[2])
				return (1);
			if (!ck_is_room_name(info->tmp_link[0], info) || !ck_is_room_name(info->tmp_link[1], info))
				return (1);
			if (!ft_strcmp(info->tmp_link[0], info->tmp_link[1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int		get_room(char **map, t_leminfo *info)
{
	int i;
	int j;

	i = info->nbr_location + 1;
	j = 0;
	info->room_name = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	info->room_x = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	info->room_y = (char**)malloc(sizeof(char*) * (info->count_room + 1));
	while (i < info->link_location)
	{
		if (map[i][0] != '#')
		{
			info->tmp_room_name = ft_strsplit(map[i], ' ');
			if (!(info->room_name[j] = ft_strdup(info->tmp_room_name[0])) || \
				!(info->room_x[j] = ft_strdup(info->tmp_room_name[1])))
				return (1);
			if (!(info->room_y[j] = ft_strdup(info->tmp_room_name[2])) || info->tmp_room_name[3])
				return (1);
			j++;
		}
		i++;
	}
	info->room_name[j] = NULL;
	info->room_x[j] = NULL;
	info->room_y[j] = NULL;
	return (0);
}

int	check_hash_hash(char **map, t_leminfo *info)
{
	int i;

	i = 0;
	while (i < info->nbr_location)
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") || map[i][0] == '\0')
			return (1);
		i++;
	}
	i++;
	while (i < info->link_location)
	{
		if (map[i][0] == '\0')
			return (1);
		if (map[i][0] != '#')
			info->count_room++;
		i++;
	}
	while (map[i])
	{
		if (!ft_strcmp(map[i], "##start") || !ft_strcmp(map[i], "##end") || map[i][0] == '\0')
			return (1);
		if (map[i][0] != '#')
			info->count_link++;
		i++;
	}
	// ft_printf("info->count_room is %d, info->count_link is %d\n", info->count_room, info->count_link);
	return (0);
}

int		check_map(char **map, t_leminfo *info)
{
	if (info->count_end != 1 || info->count_start != 1)
	{
		ft_printf("hello\n");
		return (1);
	}
	if (check_nbr_of_ants(info->nbr_of_ant))
	{
		ft_printf("1hello\n");
		return (1);
	}
	if (check_hash_hash(map, info))
	{
		ft_printf("2hello\n");
		return (1);
	}
	if (get_room(map, info))
	{
		ft_printf("3hello\n");
		return (1);
	}
	if (check_room(info))
	{
		ft_printf("4hello\n");
		return (1);
	}
	if (get_link(map, info))
	{
		ft_printf("5ello\n");
		return (1);
	}
	return (0);
}

void	validate_map(char **map, t_leminfo *info)
{
	int i;

	i = 0;
	while (map[i])
	{
		while (map[i] && map[i][0] == '#')
			i++;
		if (!info->nbr_of_ant)
		{
			info->nbr_location = i;
			info->nbr_of_ant = ft_strdup(map[i]);
		}
		i++;
		while ( map[i] && !check_dash(map[i]))
		{
			if (!ft_strcmp(map[i], "##start"))
				info->count_start++;
			if (!ft_strcmp(map[i], "##end"))
				info->count_end++;
			i++;
		}
		if (info->link_location == 0)
			info->link_location = i;
		i++;
	}
	// ft_printf("nbr_location is %d, link_location is %d\n", info->nbr_location, info->link_location);
	// ft_printf("info->count_end is %d, info->count_start is %d\n", info->count_end, info->count_start);
	// ft_printf("nbr_of_ant is %s\n", info->nbr_of_ant);
}

int main(void)
{
	int		r;
	char	*line;
	char	**map;
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
}
