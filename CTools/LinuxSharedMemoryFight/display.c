/*
** display.c for lemipc  in /home/bagnos_c//Tek2/System_Unix/Lemipc/lemipc
**
** Made by caroline bagnost
** Login   <bagnos_c@epitech.net>
**
** Started on  Fri Mar 29 16:19:06 2013 caroline bagnost
** Last update Sun Mar 31 21:39:54 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "curses.h"

void		set_color(WINDOW *ptr, int c)
{
  wbkgd(ptr, COLOR_PAIR(c));
  wrefresh(ptr);
}

int		background(t_win *lemi)
{
  lemi->bkgd = subwin(stdscr, MAP_Y + 2, MAP_X + 2, 0, 0);
  if (lemi->bkgd == NULL)
    return (my_puterr("Background subwin failure\n"));
  box(lemi->bkgd, 0, 0);
  set_color(lemi->bkgd, 0);
  return (0);
}

int		info(t_win *lemi)
{
  int		i;

  lemi->info = subwin(stdscr, 9, MAP_X + 2, MAP_Y + 3, 0);
  if (lemi->info == NULL)
    return (my_puterr("Info subwin failure\n"));
  set_color(lemi->info, 0);
  lemi->color = (WINDOW **)malloc(6 * sizeof(WINDOW *));
  if (lemi->color == NULL)
    return (my_puterr("Malloc failure\n"));
  i = 0;
  while (i < 6)
    {
      lemi->color[i] = subwin(stdscr, 1, 1, i + MAP_Y + 4, 2);
      if (lemi->color[i] == NULL)
	return (my_puterr("Color subwin failure\n"));
      i++;
    }
  box(lemi->info, 0, 0);
  wrefresh(lemi->info);
  return (0);
}

int		create_subwin(t_win *lemi)
{
  int		l;
  int		n;

  l = 0;
  while (l < MAP_Y)
    {
      n = 0;
      while (n < MAP_X)
        {
          lemi->win[l][n] = subwin(lemi->bkgd, 1, 1, l + 1, n + 1);
	  if (lemi->win[l][n] == NULL)
	    return (my_puterr("Subwin failure\n"));
	  set_color(lemi->win[l][n], 0);
          n++;
        }
      l++;
    }
  return (0);
}

int		create_game(t_win *lemi)
{
  int		n;

  lemi->win = (WINDOW ***)malloc(MAP_Y * sizeof(WINDOW **));
  if (lemi->win == NULL)
    return (my_puterr("Malloc failure\n"));
  n = 0;
  while (n < MAP_Y)
    {
      lemi->win[n] = (WINDOW **)malloc(MAP_X * sizeof(WINDOW *));
      if (lemi->win[n++] == NULL)
	return (my_puterr("Malloc failure\n"));
    }
  if (create_subwin(lemi) == 1)
    return (my_puterr("Subwin failure\n"));
  return (0);
}
