/*
** pipe_check_funtion.c for pipe_checkin in /home/kauch_j/rendu/prog_elem/lem_in
**
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May  3 02:16:11 2014 quach_a
** Last update Sun May  4 15:01:00 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

int	check_same(char *s, char *tmp)
{
  char	*tmp2;
  int	k;
  int	j;

  k = 0;
  j = 0;
  if ((tmp2 = malloc(my_strlen(tmp) + 1)) == NULL)
    return (0);
  while (s[j] != '-')
    j++;
  j++;
  while (s[j] != 0)
    tmp2[k++] = s[j++];
  tmp2[k] = '\0';
  if (my_strcmp(tmp, tmp2) == 0)
    return (1);
  return (0);
}

int	is_already_here(t_lem *lem, char *s, int j)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (k < lem[j].link)
    {
      i = get_value(lem, s);
      if (lem[j].pipe[k] == i)
        return (-1);
      k++;
    }
  return (0);
}
