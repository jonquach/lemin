/*
** check_name.c for  in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Thu Apr 17 19:30:39 2014 kauch_j
** Last update Sun May  4 14:54:37 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

int		check_name(t_lem *lem, char *str)
{
  int		i;

  i = 0;
  while (lem[i].name)
    {
      if (my_strcmp(str, lem[i].name) == 0)
        return (0);
      i++;
    }
  if (lem[i].name == NULL)
    return (1);
  return (0);
}
