/*
** types.h for types.h in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 19:51:33 2012 sebastien bequignon
** Last update Sun Nov 18 20:43:48 2012 sebastien bequignon
*/

#ifndef TYPES_H_
# define TYPES_H_

#include <stdarg.h>

int	display_nbr(va_list va);
int	display_unsigned_char_of_int(va_list va);
int	display_str(va_list va);
int	display_pointer_hexa(va_list va);
int	display_percent(va_list va);
int	display_binary_unsigned_char(va_list va);
int	convert_octal(va_list va);
int	convert_unsigned_dec(va_list va);
int	convert_hexa_low(va_list va);
int	convert_hexa_up(va_list va);
int	convert_octal_char(va_list va);

#endif /* !TYPES_H_ */
