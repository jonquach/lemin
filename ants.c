/*
** ants.c for ants in /home/kauch_j/remdu/prog_elem/lem_in
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Wed Apr 30 16:47:20 2014 frayss_c
** Last update Sun May  4 14:53:16 2014 kauch_j
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lem.h"

int	go_forward(int *room, t_lem *lem, int r)
{
  static int	i = 0;

  i++;
  lem[room[0]].ant_num = i;
  while (r > 0)
    {
      if (lem[room[r - 1]].ant > 0)
	{
	  lem[room[r]].ant += 1;
	  lem[room[r - 1]].ant -= 1;
	  lem[room[r]].ant_num = lem[room[r - 1]].ant_num;
	  my_putchar('P');
	  my_putnbr(lem[room[r]].ant_num);
	  my_putchar('-');
	  my_putstr(lem[room[r]].name);
	  my_putchar(' ');
	}
      r--;
    }
  my_putchar('\n');
  return (0);
}

void	init_ant_num(int *room, t_lem *lem, int r)
{
  while (r > 0)
    {
      lem[room[r]].ant = 0;
      r--;
    }
}

int	to_the_exit(int *room, t_lem *lem, int r)
{
  int	ants;

  ants = lem[room[0]].ant;
  init_ant_num(room, lem, r);
  while (lem[room[r]].ant < ants)
    go_forward(room, lem, r);
  return (0);
}
