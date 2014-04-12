/*
** main.c for my_putchar in /home/bequig_s//piscine/jour4
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct  4 09:46:14 2012 sebastien bequignon
** Last update Fri Oct 26 11:21:42 2012 sebastien bequignon
*/

#include <unistd.h>

void  my_putchar(char c)
{
  write (1, &c, 1);
}
