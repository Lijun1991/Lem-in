/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:41:50 by lwang             #+#    #+#             */
/*   Updated: 2017/05/30 21:41:52 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_leminfo
{
	int count_line;
	int	count_start;
	int	count_end;
	int	nbr_location;
	int link_location;
	char *nbr_of_ant;

}				t_leminfo;

/*
** helper.c
*/
void	check_range(int count, char **map);
void	deep_free(char **map);

#endif
