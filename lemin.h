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
# include <stdio.h>
# include <string.h>

# define true 1
# define false 0

# define MAX_ROOM_TOTAL 10000
# define LONG_CONDITION !(info->room_name[j] = ft_strdup(info->tmp_room_name[0])) || !(info->room_x[j] = ft_strdup(info->tmp_room_name[1])) || !(info->room_y[j] = ft_strdup(info->tmp_room_name[2]))

typedef struct 	s_ant
{
	int tmp_path_len;
	int ant_nbr;
	int ant_reach_end;
	int move_times;
	int sign;
	int	path_len;
	int ants_total;
}				t_ant;

typedef struct 	s_vertex
{
	int		**graph;
	int 	*path;
  	int 	*visited;
  	int		N;
  	int		indx;
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
	int		**path;
	int		count_path;
	t_vertex *v;
}				t_leminfo;

/*
** free.c
*/
void	free_everything(t_leminfo *info, char **map);
void	deep_free(char **s);
void	free_vertex(t_vertex *v, t_leminfo *info);
void	deep_free_path(int **path);
void	free_room(t_leminfo *info, char **map);

/*
** get_path.c
*/
char		*sep(char *s);
int			**get_adj_matrix(t_leminfo *info);
int			*get_dst(int len, t_leminfo *info);	
int			*pick_path(t_leminfo *info);
int			num_linked_room_name(char *room_name, t_leminfo *info);

/*
** helper.c
*/
void	check_range(int count, char **map);
void	deep_free(char **map);
int		check_dash(char *s);
int		count_dash(char *s);

/*
** print_map.c
*/
char	*get_start_room(char **map, t_leminfo *info);
char	*get_end_room(char **map, t_leminfo *info);
void	print_normal_room(char **map, t_leminfo *info, char *start, char *end);
void	print_link(t_leminfo *info);
void	print_map(char **map, t_leminfo *info);

/*
** solve_adj_matrix.c
*/
t_vertex		*solve_adj_matrix(int **adj, t_leminfo *info);

/*
** solve_move_ants.c 
*/
void	move_ants(t_leminfo *info, int *path, int path_len, int ants_total);
char	*rename_base_room_nbr(int nbr, t_leminfo *info);
void	update_path_taken(int *path_taken, int room_nbr, int *path);
int		*get_path_taken(t_leminfo *info);

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
** validate_map3.c 
*/
int			check_hash_hash(char **map, t_leminfo *info);
int			get_room(char **map, t_leminfo *info);
int			ck_link_repeat(t_leminfo *info);

#endif
