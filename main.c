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
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	if (s[0] == '0')
		return (1);
	return (0);
}

int	validate_map(char **info)
{
	int i;

	i = 1;
	while (info[i])
	{
		while (info[i][0] == "#")
			i++:
		if ((check_nbr_of_ants(info[i])))
			return (1);
		i++;
		if (info[i][0] == '#' && info[i][1] == '#')
		{
			if (!(!ft_strcmp(info[i], "##start") || !ft_strcmp(info[i], "##end")))
				return (1);
		}
		if (info[i][0] != "#" && info[i][0] != "L")
		i++;
	}
	return (0);
}

int main(void)
{
	int		r;
	char	*line;
	char	**info;
	int		count;

	count = 0;
	info = (char**)malloc(sizeof(char*) * (10000 + 1));
	while ((r = get_next_line(0, &line)) && r != -1)
	{
		info[count] = ft_strdup(line);
		count++;
		free(line);
		line = NULL;
	}
	info[count] = NULL;
	check_range(count, info);
	if (validate_map(info))
	{
		deep_free(info);
		perror("Invalid map");
		return (1);
	}
}