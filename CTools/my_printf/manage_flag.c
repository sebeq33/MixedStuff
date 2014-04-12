/*
** manage_flag.c for manage_flag.c in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov 15 14:22:16 2012 sebastien bequignon
** Last update Fri Nov 16 23:36:19 2012 sebastien bequignon
*/

#include "my_printf.h"

static t_hook           flags[NB_FLAGS] =
  {
    {'%', conversion},
    {'#', alternate_form},
    {'0', zero_padded},
    {'-', manage_minus}, // left_ajusted_or_minus_operands
    {' ', keep_space},
    {'+', add_operands},
    {'.', presision}
  }

int(*)(char *, va_list *)	get_flag_func(char c)
{
  int				i;

  i = 0;
  while (i < nb_func)
    {
      if (flags[i]->hook == c)
	return (flags[i]->func);
      i++;
    }
  return (NULL);
}

int	exec_flag(char *format, va_list *va, int(*func)(char *, va_list *))
{

  return (func(format, va));
}

int	procede(char *format, va_list *va)
{
  int	(*func)(char *, va_list *);
  int	t_wrote;
  int	wrote;
  int	pos;

  while (format[pos] != '\0')
    {
      if ((func = get_flag_func(format[i])) != NULL)
	wrote = exec_func(&format[i], va_list, func);
      else
	{
	  my_putchar(format[i]);
	  wrote = 1;
	}
      t_wrote = t_wrote + wrote;
    }
  return (t_wrote);
}
