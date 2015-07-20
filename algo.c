/*
** algo.c for algo in /home/frayss_c/Dropbox/EPITECH PROJET/kauch_j/lem-in/v1
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Wed Apr 30 15:18:42 2014 frayss_c
** Last update Sun May  4 17:58:45 2014 kauch_j
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lem.h"

void		do_algo(t_lem *lem, int max, int end, int *room)
{
  int		i;
  t_stock	stock;
  i = 0;
  stock.r = 0;
  stock.end = end;
  while (i < max)
    {
      if (lem[i].type == 1)
	if ((solve(lem, i, room, stock)) != 0)
	  my_putstr("Error: There is no path to the exit\n");
      i++;
    }
}

int		start_algo(int max, t_lem *lem)
{
  int		end;
  int		*room;
  int		i;

  if ((room = malloc(sizeof(int) * max)) == NULL)
    return (-1);
  i = 0;
  while (i < max)
    room[i++] = -1;
  i = -1;
  while (++i < max)
    {
      if (lem[i].type == 2)
	end = i;
    }
  do_algo(lem, max, end, room);
  return (0);
}
