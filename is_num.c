/*
** is_num.c for  in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Wed Apr 30 21:06:09 2014 kauch_j
** Last update Sun May  4 14:59:01 2014 kauch_j
*/

#include "lem.h"

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  else
    return (1);
}
