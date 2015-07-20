/*
** count_lem.c for count_lem.c in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Created by kauch_j
** Login   <@epitech.eu>
** 
** Started on  Wed Apr 30 21:04:53 2014 kauch_j
** Last update Sun May  4 14:55:02 2014 kauch_j
*/

#include "lem.h"

int     count_len(int i, int len, char *buffer)
{
  while (buffer[i] != ' ' && buffer[i] != '\0' && buffer[i] != '\n')
    {
      i++;
      len++;
    }
  return (len);
}
