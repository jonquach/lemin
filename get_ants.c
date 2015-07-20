/*
** get_ants.c for get_ants.c in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Wed Apr 30 21:03:23 2014 kauch_j
** Last update Sun May  4 14:58:15 2014 kauch_j
*/

#include <stdlib.h>
#include <unistd.h>
#include "lem.h"

int		get_ants(char *buffer, t_lem *lem, int count)
{
  int		i;
  char		*str;

  i = 0;
  if (lem[count].type != 1)
    return (-1);
  while (buffer[i] != '\n')
    i++;
  if ((str = malloc(i)) == NULL)
    return (-1);
  i = -1;
  while (buffer[++i] != '\n' && buffer[i])
    {
      if (is_num(buffer[i]) == 0)
	str[i] = buffer[i];
      else
	{
	  my_putstr("Error : number of ants is not numeric\n");
	  exit(EXIT_FAILURE);
	}
    }
  str[i] = 0;
  if (str[i - 1] != 0)
    lem[count].ant = my_getnbr(str);
  return (0);
}
