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

void	deep_free(char **info)
{
	int i;

	i = 0;
	while (info[i])
	{
		free(info[i]);
		info[i] = NULL;
		i++;
	}
	free(info);
	info = NULL;
}

void	check_range(int count, char **info)
{
	if (count > 10000)
	{
		perror("unsupport too large map");
		deep_free(info);
		exit(1);
	}
}