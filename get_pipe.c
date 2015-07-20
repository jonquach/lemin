/*
** get_pipe.c for  in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Wed Apr 16 12:09:56 2014 kauch_j
** Last update Sun May  4 14:58:33 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

char		**put_pipe(char *str, int max)
{
  static char	**tab = NULL;
  static int	i = 0;

  if (i == 0)
    {
      if ((tab = malloc(sizeof(char **) * max + 1)) == NULL)
	return (NULL);
      tab[i] = str;
      i++;
      return (tab);
    }
  tab[i] = str;
  i++;
  return (tab);
}

int		check_all_name(t_lem *lem, char *str, char *str2, int line)
{
  int		res;
  int		res2;

  if ((res = check_name(lem, str)) == 1)
    aff_str(str, line);
  if ((res2 = check_name(lem, str2)) == 1)
    aff_str(str2, line);
  if (res > 0 || res2 > 0)
    return (1);
  return (0);
}

void		copy_name(char **tab, char *str, char *str2, int i)
{
  int		j;
  int		k;

  j = 0;
  k = 0;
  while (tab[i][j] != '-')
    {
      str[j] = tab[i][j];
      j++;
    }
  str[j] = 0;
  ++j;
  while (tab[i][j])
    str2[k++] = tab[i][j++];
  str2[k] = 0;
}

char		**get_pipe(t_lem *lem, char **tab)
{
  int		i;
  int		j;
  int		line;
  int		max;
  char		**stock;

  i = 0;
  line = 0;
  max = get_pipe_number(tab);
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '-')
	    stock = put_pipe(tab[i], max);
	  j++;
	}
      line++;
      i++;
    }
  check_error(lem, stock, line - max);
  return (stock);
}

char		**get_all_elem(t_lem *lem, char *buffer)
{
  char		**tab;
  char		**stock;

  if ((tab = my_str_to_wordtab(buffer, '\n')) == NULL)
    return (NULL);
  stock = get_pipe(lem, tab);
  return (stock);
}
