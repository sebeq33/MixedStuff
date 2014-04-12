/*
** manage_len_m.c for manage_len_m.c in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 23:32:59 2012 sebastien bequignon
** Last update Fri Nov 16 23:33:34 2012 sebastien bequignon
*/

static t_hook           lenght_m[NB_LENGTH_MOD] =
  {
    {'ç', NULL}
  }

int     exec_flag(char *format, va_list *va, int(*func)(char *, va_list *))
{
  return (func(format, va));
}

