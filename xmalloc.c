/*
** xmalloc.c for  in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by kauch_j
** Login   <kauch_j@epitech.net>
** 
** Started on  Wed Apr 16 14:55:38 2014 kauch_j
** Last update Sun May  4 15:01:43 2014 kauch_j
*/

#include <stdlib.h>
#include "lem.h"

char	*xmalloc(char *str, int size)
{
  if ((str = malloc(size)) != NULL)
    return (str);
  return (NULL);
}
