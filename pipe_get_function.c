/*
** pipe_get_function.c for find_pipe_function in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May  3 02:10:12 2014 quach_a
** Last update Sun May  4 15:01:12 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

char	*get_name(char *s)
{
  int	i;
  char	*tmp;

  i = 0;
  if (s == NULL)
    return (NULL);
  while (s[i] != '-' && s[i] != '\n')
    ++i;
  if ((tmp = malloc(i + 1)) == NULL)
    return (NULL);
  if (tmp != NULL && s != NULL)
    my_strncpy(tmp, s, i);
  return (tmp);
}

int	k_get_link_value(t_lem *lem, int j, int k)
{
  while (k < lem[j].link)
    k++;
  return (k);
}
int	get_value(t_lem *lem, char *s)
{
  int	i;
  int	j;
  int	k;
  char	*tmp;

  i = 0;
  j = 0;
  k = 0;
  while (s[i] != '-')
    i++;
  i++;
  if ((tmp = malloc(my_strlen(s) + 1)) == NULL)
    return (-1);
  while (s[i] != 0)
    tmp[k++] = s[i++];
  tmp[k] = '\0';
  while (lem[j].name != NULL)
    {
      if (my_strcmp(tmp, lem[j].name) == 0)
        return (j);
      j++;
    }
  return (-1);
}

int	get_value_reverse(t_lem *lem, char *s)
{
  int	i;
  int	j;
  int	k;
  char	*tmp;

  i = 0;
  j = 0;
  k = 0;
  if ((tmp = malloc(my_strlen(s) + 1)) == NULL)
    return (-1);
  while (s[i] != '-')
    tmp[k++] = s[i++];
  tmp[k] = '\0';
  while (lem[j].name != NULL)
    {
      if (my_strcmp(tmp, lem[j].name) == 0)
        return (j);
      j++;
    }
  return (-1);
}
