/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:34:02 by lwang             #+#    #+#             */
/*   Updated: 2017/05/30 22:34:04 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void	deep_free(char **map)
// {
// 	int i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		map[i] = NULL;
// 		i++;
// 	}
// 	free(map);
// 	map = NULL;
// }

void	check_range(int count, char **map)
{
	if (count > MAX_ROOM_TOTAL)
	{
		perror("unsupport too large map");
		deep_free(map);
		exit(1);
	}
}

int		check_dash(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		count_hash(char *s)
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