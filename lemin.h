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
# include <stdbool.h>
# include "./libft/libft.h"


typedef struct 	s_vertex
{
	char	*name;
	int		index;
}				t_vertex;

typedef struct	s_leminfo
{
	int		count_line;
	int		count_start;
	int		count_end;
	int		count_room;
	int		count_link;
	int		nbr_location;
	int		link_location;
	char	*nbr_of_ant;
	char	*start;
	char	*end;
	int		room_total;
	char	**tmp_room_name;
	char	**room_name;
	char	**room_x;
	char	**room_y;
	char	**tmp_link;
	char	**link;
	char	**path;
}				t_leminfo;

/*
** print_map.c
*/
char	*get_start_room(char **map, t_leminfo *info);
char	*get_end_room(char **map, t_leminfo *info);
void	print_normal_room(char **map, t_leminfo *info, char *start, char *end);
void	print_link(t_leminfo *info);
void	print_map(char **map, t_leminfo *info);

/*
** validate_map1.c
*/
int		check_nbr_of_ants(char *s);
int		get_room(char **map, t_leminfo *info);
int		check_map(char **map, t_leminfo *info);
void	validate_map(char **map, t_leminfo *info);

/*
** validate_map2.c
*/
int		check_hash_hash(char **map, t_leminfo *info);
int		ck_is_int(char *s);
int		ck_is_room_name(char *s, t_leminfo *info);
int		check_room(t_leminfo *info);
int		get_check_link(char **map, t_leminfo *info);

/*
** helper.c
*/
void	check_range(int count, char **map);
void	deep_free(char **map);
int		check_dash(char *s);
int		count_hash(char *s);

#endif
