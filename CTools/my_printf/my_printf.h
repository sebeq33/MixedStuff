/*
** my_printf.h for my_printf.h in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov 15 10:51:33 2012 sebastien bequignon
** Last update Sun Nov 18 20:42:51 2012 sebastien bequignon
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# define NB_CONVERTER 10
# define BASE_OCTAL "01234567"
# define BASE_HEXA_UP "0123456789ABCDEF"
# define BASE_HEXA_LOW "0123456789abcdef"
# define BASE_BIN "01"

typedef struct s_hook
{
  char	hook;
  int	(*func)(char *str, va_list *va);
} t_hook;

int	display_nbr(char *str, va_list *va);
int	convert_octal(char *str, va_list *va);
int	convert_unsigned_dec(char *str, va_list *va);
int	convert_hexa_low(char *str, va_list *va);
int	convert_hexa_up(char *str, va_list *va);
int	display_unsigned_char_of_int(char *str, va_list *va);
int	display_str(char *str, va_list *va);
int	print_pointer_hexa(char *str, va_list *va);
int	display_percent(char *str, va_list *va);

#endif /* !MY_PRINTF_H_ */
