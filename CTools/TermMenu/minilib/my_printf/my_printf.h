/*
** my_printf.h for my_printf.h in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 09:30:21 2012 sebastien bequignon
** Last update Sun Nov 18 21:39:33 2012 sebastien bequignon
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

# define NB_FLAGS (5)
# define NB_TYPES (12)
# define BASE_OCTAL "01234567"
# define BASE_HEXA_UP "0123456789ABCDEF"
# define BASE_HEXA_LOW "0123456789abcdef"
# define BASE_BIN "01"

typedef struct s_query
{
  int	nb_param;
  int	display_sign;
  int	space;
  int	align;
  int	alternate_form;
  int	zero_padded;
  int	width;
  int	precision;
  char	type;
  int	(*func)(va_list);
} t_query;

typedef struct s_hook_type
{
  char	hook;
  int	(*func)(va_list);
} t_hook_type;

typedef struct s_hook
{
  char	hook;
  int  (*func)(t_query *);
} t_hook;

typedef enum
{
  left,
  right,
} align;

#endif /* !MY_PRINTF_H_ */
