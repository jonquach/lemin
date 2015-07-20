/*
** functions.c for function in /home/quach_a/Dropbox/EPITECH PROJET/kauch_j/lem-in/v1
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Sat May  3 02:37:15 2014 quach_a
** Last update Sat May  3 19:47:11 2014 frayss_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "lem.h"

void	my_putnbr(int i)
{
  int	div;

  div = 1;
  while ((i/div) >= 10)
    div *= 10;
  while (div > 0)
    {
      my_putchar((i/div) % 10 + '0');
      div /= 10;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	j;

  i = 0;
  res = 0;
  j = 1;
  if (str == NULL)
    return (0);
  while (str[i] < '0' || (str[i] > '9' && str[i] != '\0'))
    {
      if (str[i] == '-')
        {
          my_putstr("Error: number of ants must be positive\n");
          exit(EXIT_FAILURE);
        }
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
    {
      res = ((str[i] - '0') + (res * 10));
      i++;
    }
  res = res * j;
  return (res);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
