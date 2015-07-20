/*
** my_str_to_wordtab.c for /home/kauch_j/rendu/prog_elem/lem_in
**
** Made by kauch_j
** Login   <kauch_j@epitech.net>
**
** Started on  Fri Dec 20 17:08:18 2013 kauch_j
** Last update Sun May  4 15:00:43 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

int		count_word(char *str, char c)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	cpt++;
      i++;
    }
  return (cpt);
}

char		*copy_in_tab(char *str, char *dest, int start, char c)
{
  int		i;

  i = 0;
  while ((str[start] != c) && (str[start] != '\0'))
    {
      dest[i] = str[start];
      start++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int		count_letter(char *str, int start, char c)
{
  int		i;

  i = 0;
  while ((str[start] != c) && (str[start] != '\0'))
    {
      start++;
      i++;
    }
  return (i);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  char		tmp;
  char		**tab;

  i = 0;
  j = 0;
  if ((tab = malloc((count_word(str, c) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  tmp = c;
  while (str[i] != '\0')
    {
      if (tmp == c && str[i] != c)
	{
	  if ((tab[j] = malloc((count_letter(str, i, c) + 1)
			       * sizeof(char))) == NULL)
	    return (NULL);
	  copy_in_tab(str, tab[j], i, c);
	  j++;
	}
      tmp = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
