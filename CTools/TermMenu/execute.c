/*
** execute.c for execute.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov 20 20:48:03 2012 sebastien bequignon
** Last update Fri Nov 23 17:07:10 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "terminal.h"
#include "my_select.h"

static int well_sized;

void	resize()
{
  if (!reset_getent() || !clean_term())
    return ;
  if (update_list(g_list))
    {
      display_list(g_list);
      well_sized = 1;
    }
  else
    {
      my_putstr_fd(TOO_SMALL);
      well_sized = 0;
    }
}

void	execute()
{
  int	again;
  int	ret;
  char	buffer[6];

  again = 1;
  g_list->underline = 1;
  resize();
  while (again && g_list->value != NULL)
    {
      if ((ret = read(0, buffer, 5)) == -1)
	{
	  my_putstr_error("Read error\n");
	  return ;
	}
      buffer[ret] = '\0';
      again = manage_actions(buffer, well_sized);
    }
  again = 0;
  clean_term();
  while (g_list->value != NULL)
    {
      if (g_list->selected)
	my_printf("%s ", g_list->value);
      delete_node(&g_list, &g_list);
    }
}
