/*
** functions_str.c for functions_str in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May  3 02:50:39 2014 quach_a
** Last update Sun May  4 18:05:28 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

char	*my_strcpy(char *dest, char *src)
{
  int	count;
  int	stop;

  stop = 0;
  while (src[stop] != 0)
    {
      stop = stop + 1;
    }
  count = 0;
  while (count <= stop)
    {
      dest[count] = src[count];
      count = count + 1;
    }
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	res;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i])
    {
      if (s1[i] < s2[i])
        {
          res = -1;
          return (res);
        }
      if (s1[i] > s2[i])
        {
          res  = 1;
          return (res);
        }
      if (s1[i] == s2[i])
        res = 0;
      i = i + 1;
    }
  return (res);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && i != n)
    {
      i = i + 1;
      if (s1[i] == s2[i] && i == n)
        return (0);
    }
  if (s2[i] == '\0')
    return (s1[i] - s2[i]);
  return (-1);
}
