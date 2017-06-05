/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:15:39 by lwang             #+#    #+#             */
/*   Updated: 2017/06/05 10:15:42 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void print_stack_elements (int indx, int *path)
{
  int i;
  for (i = 0; i < indx; i++)
    printf ("%d ", path[i]);
 
  printf ("\n");
}

static void printPath (t_vertex *v, int **graph, t_leminfo *info)
{
  int indx;
  int i;

  indx = 0;
  i = 0;
  v->visited[v->src] = true;
  v->path[indx] = v->src;
  indx++;
 
  if (v->src == v->dest)
      print_stack_elements (indx, v->path);
  else
    {
      while (i < info->room_total)
      {
          if (v->visited[i] == false && graph[v->src][i])
          {
              v->src = i;
              printPath (v, graph, info);
          }
          i++;
      }
    }
 
  v->visited[v->src] = false;
  indx--;
}

int solve(int **adj, t_leminfo *info)
{
  t_vertex v;

  ft_memset(&v, 0, sizeof(t_vertex));
  v.src = ft_atoi(sep(info->start));
  v.dest = ft_atoi(sep(info->end));
  v.path = (int*)malloc(sizeof(int) * info->room_total);
  v.visited = (int*)malloc(sizeof(int) * info->room_total);
  ft_memset (v.visited, 0, sizeof (v.visited));
  ft_memset (v.path, 0, sizeof (v.path));
  printPath (&v, adj, info);

  return 0;
}
