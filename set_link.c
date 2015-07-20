/*
** set_link.c for set_link.c in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May  3 01:59:37 2014 quach_a
** Last update Sun May  4 15:01:23 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

void	set_link(t_lem *lem)
{
  int	i;

  i = -1;
  while (lem[++i].name != NULL)
    lem[i].link = 0;
}
