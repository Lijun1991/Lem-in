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
}
