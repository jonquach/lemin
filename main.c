/*
** main.c for main.c in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Tue Apr 15 13:13:04 2014 frayss_c
** Last update Sun May  4 18:04:03 2014 kauch_j
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lem.h"

int    check_stanend(t_lem *lem, int max)
{
  int   count;
  int	i;

  i = 0;
  count = 0;
  while (count < max)
    {
      if (lem[count].type == 1)
	i++;
      else if (lem[count].type == 2)
        i++;
      count++;
    }
  if (i < 2)
    {
      my_putstr("Error missing start or end\n");
      return (-1);
    }
  else if (i > 2)
    {
      my_putstr("Error multiple definition of start or end\n");
      return (-1);
    }
  return (0);
}

char	*init_room(t_lem *lem, int max)
{
  int	i;

  i = 0;
  while (lem[i].name)
    {
      if ((lem[i].pipe = malloc(sizeof(int *) + max)) == NULL)
	return (NULL);
      i++;
    }
  return (0);
}

int	my_lem(int max, char *buffer)
{
  t_lem	*lem;
  char	**tab;
  int	i;
  int	j;

  i = -1;
  j = 0;
  my_putstr(buffer);
  my_putchar('\n');
  if (max > 0)
    {
      if ((lem = malloc(sizeof(t_lem) * max)) == NULL)
	return (-1);
      put_name(lem, buffer);
      if (check_stanend(lem, max) == -1)
	return (-1);
      tab = get_all_elem(lem, buffer);
      init_room(lem, max);
      set_link(lem);
      find_pipe(lem, tab, i, j);
      start_algo(max, lem);
    }
  else
    my_putstr("Error no room\n");
  return (0);
}

char	*read_it()
{
  int	ret;
  char	*buffer;
  char	*str2;
  int	i;

  i = 1;
  if ((buffer = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  if ((str2 = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  while ((ret = read(0, buffer, READ_SIZE)) > 0)
    {
      buffer[ret] = '\0';
      if ((str2 = realloc(str2, READ_SIZE * i + 1)) == NULL)
  	return (NULL);
      (i == 1) ? strcpy(str2, buffer) : strcat(str2, buffer);
      i++;
    }
  return (str2);
}

int	main(void)
{
  char	*str2;

  str2 = read_it();
  if (str2 != NULL)
    {
      str2[my_strlen(str2)] = 0;
      my_lem(find_room(str2), str2);
    }
  else
    my_putstr("Error empty file\n");
  return (0);
}
