/*
** solve.c for solve.c in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Sat May  3 19:28:33 2014 frayss_c
** Last update Sun May  4 17:56:59 2014 kauch_j
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lem.h"

void		aff_path(t_lem *lem, int r, int *room)
{
  int		k;

  k = 0;
  my_putstr("<---------------PATH--------------->\n");
  while (k < r)
    {
      my_putstr("\n\t\t");
      my_putstr(lem[room[k]].name);
      k++;
    }
  my_putstr("\n\n<---------------ANTS--------------->\n\n");
}

int		if_one_way(t_lem *lem, int i, int *room, t_stock stock)
{
  int		j;

  j = 0;
  while (j < stock.r)
    {
      if (room[j] == lem[i].pipe[0])
        return (-1);
      j++;
    }
  return (solve(lem, lem[i].pipe[0], room, stock));
}

int		multiple_ways(t_lem *lem, int i, int *room, t_stock stock)
{
  int		j;
  int		val;

  val = -1;
  while (++val < lem[i].link)
    {
      j = -1;
      while (++j < stock.r)
        if (room[j] == lem[i].pipe[val])
          {
            val++;
            j = -1;
          }
      if (val < lem[i].link)
        if ((solve(lem, lem[i].pipe[val], room, stock)) == 0)
          return (0);
    }
  return (-1);
}

int		solve(t_lem *lem, int i, int *room, t_stock stock)
{
  int		val;

  room[stock.r] = i;
  stock.r++;
  if (lem[i].type == 2)
    {
      aff_path(lem, stock.r, room);
      to_the_exit(room, lem, stock.r - 1);
      return (0);
    }
  val = -1;
  while (++val < lem[i].link)
    if (lem[i].pipe[val] == stock.end)
      if ((solve(lem, lem[i].pipe[val], room, stock)) == 0)
	return (0);
  if (lem[i].link == 1)
    return (if_one_way(lem, i, room, stock));
  return (multiple_ways(lem, i, room, stock));
}
