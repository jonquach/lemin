/*
** find_pipe.c for find_pipe in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Thu Apr 24 18:50:12 2014 quach_a
** Last update Sun May  4 17:57:18 2014 kauch_j
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lem.h"

int	set_reverse_pipe(t_lem *lem, char *s, int j, int k)
{
  k = k_get_link_value(lem, j, k);
  lem[j].pipe[k] = get_value_reverse(lem, s);
  lem[j].link++;
  return (k + 1);
}

int	reverse_pipe(t_lem *lem, char *s, char *tmp)
{
  int	k;
  int	j;
  char	*tmp2;

  k = 0;
  j = 0;
  if ((tmp2 = malloc(my_strlen(tmp))) == NULL)
    return (-1);
  while (s[j] != '-')
    j++;
  j++;
  while (s[j] != 0)
    tmp2[k++] = s[j++];
  tmp2[k] = '\0';
  j = -1;
  k = 0;
  while (lem[++j].name != NULL)
    {
      if (my_strncmp(tmp2, lem[j].name, my_strlen(tmp2)) == 0)
	k += set_reverse_pipe(lem, s, j, k);
    }
  return (0);
}

int	set_pipe(t_lem *lem, char *s, char *tmp, int j)
{
  int	k;

  k = 0;
  k = k_get_link_value(lem, j, k);
  lem[j].pipe[k] = get_value(lem, s);
  lem[j].link++;
  reverse_pipe(lem, s, tmp);
  return (k + 1);
}

void	find_pipe(t_lem *lem, char **tab, int i, int j)
{
  int	k;
  char	*tmp;

  k = 0;
  tmp = get_name(tab[0]);
  while (tab[++i] != NULL && lem[j].name != NULL)
    {
      i += check_same(tab[i], tmp);
      tmp = get_name(tab[i]);
      if (my_strncmp(tmp, lem[j].name, my_strlen(tmp)) == 0
	  && lem[j].name != NULL)
	{
	  if (is_already_here(lem, tab[i], j) == 0)
	    k += set_pipe(lem, tab[i], tmp, j);
	  else
	    k = 0;
	  j = 0;
	}
      else
      	{
	  j++;
      	  i--;
      	  k = 0;
      	}
    }
}
