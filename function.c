/*
** function.c for  in/home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Mon Apr 14 17:14:43 2014 kauch_j
** Last update Sun May  4 15:02:21 2014 kauch_j
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

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
