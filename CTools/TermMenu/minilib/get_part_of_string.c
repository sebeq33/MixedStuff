/*
** get_part_of_string.c for get_part_of_string.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 12 12:13:09 2012 sebastien bequignon
** Last update Fri Nov 16 09:41:30 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

char	*get_part_of_string(char *str, int nb_char)
{
  char	*new_str;

  new_str = malloc(nb_char + 1);
  if (new_str == NULL)
    return (NULL);
  new_str[nb_char] = '\0';
  my_strncat(new_str, str, nb_char);
  return (new_str);
}
