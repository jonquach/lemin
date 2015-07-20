/*
** check_error.c for check_error in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Sun May  4 14:53:56 2014 kauch_j
** Last update Sun May  4 14:53:58 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

int		check_error(t_lem *lem, char **tab, int line)
{
  int		i;
  char		*str;
  char		*str2;

  i = 0;
  while (tab[i])
    {
      str = xmalloc(str, my_strlen(tab[i]));
      str2 = xmalloc(str2, my_strlen(tab[i]));
      copy_name(tab, str, str2, i);
      check_all_name(lem, str, str2, line);
      line++;
      i++;
    }
  return (0);
}
