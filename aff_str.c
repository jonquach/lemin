/*
** aff_str.c for aff_str in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Sun May  4 14:52:27 2014 kauch_j
** Last update Sun May  4 14:52:28 2014 kauch_j
*/

#include "lem.h"

void	aff_str(char *str, int line)
{
  my_putstr("Error : room name -> ");
  my_putstr(str);
  my_putstr(" line -> ");
  my_putnbr(line + 1);
  my_putchar('\n');
}

