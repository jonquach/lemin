/*
** define_name.c for define_name in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by frayss_c
** Login   <frayss_c@epitech.net>
** 
** Started on  Wed Apr 30 15:44:56 2014 frayss_c
** Last update Sun May  4 14:55:38 2014 kauch_j
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lem.h"

int		get_stanend(char *buffer, t_lem *lem, int i, int count)
{
  int		tmp;
  char		str[6];

  while (buffer[i - 1] != '\n' && buffer[i - 1] != '\0')
    i--;
  if (buffer[i] == '#' && buffer[++i] == '#')
    {
      tmp = 0;
      i++;
      while (buffer[i] != '\n' && tmp < 5 && buffer[i] != '\0')
        str[tmp++] = buffer[i++];
      str[tmp] = '\0';
      if (strcmp(str, "start") == 0)
	lem[count].type = 1;
      else if (strcmp(str, "end") == 0)
	lem[count].type = 2;
      get_ants(buffer, lem, count);
      if (buffer[i] != '\n')
        while (buffer[i - 1] != '\n' && buffer[i] != '\0')
          i++;
      else
        i++;
    }
  return (i);
}

int		define_name(char *buffer, int i, int count, t_lem *lem)
{
  int		j;

  j = 0;
  while (buffer[i] != '\n' && buffer[i - 1] != '\0')
    i--;
  i--;
  if (buffer[i] == 't' || buffer[i] == 'd')
    i = get_stanend(buffer, lem, i, count);
  else
    {
      lem[count].type = 0;
      i = i + 2;
    }
  while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
    lem[count].name[j++] = buffer[i++];
  lem[count].name[j] = 0;
  return (i);
}

int		find_name(char *buffer, int i, int count, t_lem *lem)
{
  int		len;

  while (buffer[i] != '\0')
    {
      len = 0;
      if (buffer[i - 1] == '\n')
        {
          len = count_len(i, len, buffer);
          while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
            i++;
          if (buffer[i++] == ' ' && buffer[i] >= '0' && buffer[i] <= '9')
            {
              while (buffer[i] >= '0' && buffer[i] <= '9')
                i++;
              if (buffer[i++] == ' ' && buffer[i] >= '0' && buffer[i] <= '9')
                {
                  lem[count].name = xmalloc(lem[count].name, len);
                  define_name(buffer, i, count++, lem);
                }
            }
        }
      while (buffer[i - 1] != '\n' && buffer[i] != '\0')
        i++;
    }
  return (count);
}

void		put_name(t_lem *lem, char *buffer)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  count = find_name(buffer, i, count, lem);
  lem[count].name = NULL;
  lem[count].type = -1;
  lem[count].ant = -1;
  lem[count].pipe = 0;
}

int		find_room(char *buffer)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i - 1] == '\n')
        {
          while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
            i++;
          if (buffer[i++] == ' ' && buffer[i] >= '0' && buffer[i] <= '9')
            {
              while (buffer[i] >= '0' && buffer[i] <= '9')
                i++;
              if (buffer[i++] == ' ' && buffer[i] >= '0' && buffer[i] <= '9')
                count++;
            }
        }
      while (buffer[i - 1] != '\n' && buffer[i] != '\0')
        i++;
    }
  return (count);
}
