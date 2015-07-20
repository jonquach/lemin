/*
** get_pipe_number.c for  in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Thu Apr 17 19:29:59 2014 kauch_j
** Last update Sun May  4 14:58:51 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

int		 get_pipe_number(char **tab)
{
  int		i;
  int		j;
  int		max;

  i = 0;
  max = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
        {
          if (tab[i][j] == '-')
            max++;
          j++;
        }
      i++;
    }
  if (max != 0)
    return (max);
  else
    {
      my_putstr("Error : No pipe\n");
      exit (-1);
    }
}
