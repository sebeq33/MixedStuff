/*
** my.h for my.h in /home/bequig_s//piscine/jour9
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 11 10:44:26 2012 sebastien bequignon
** Last update Wed Dec 19 19:03:57 2012 sebastien bequignon
*/

#ifndef MY_H_
# define MY_H_

# define MAX(x, y) ((x) > (y) ? (x) : (y))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define ABS(Value) ((Value) < 0 ? ((Value) * -1) : (Value))

int	check_error(int result, char *error, int exit);
void	my_swap(int *a, int *b);
void	my_swapchar(char *a, char *b);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp_alpha(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
void	my_show_wordtab(char **tab);
int	my_isalphanumeric(char c);
int	my_strlen(char *str);
int	my_intlen(int val);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_putstr_error(char *str);
int	my_printf(char *format, ...);
void	my_put_nbr(long nb);
void	my_put_nbr_base(int val, char *base);
int	my_getnbr(char *str);
int	my_getnbr_base(char *str, char *base);
char	*my_getstr(int val);
char	*my_strdup(char *src);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strlcat(char *dest, char *src, int size);
char	*my_epur_str(char *str);
char	*my_remove_spaces(char *str);
char	*my_getenv(char *searched_var);
char	*get_part_of_string(char *str, int nb_char);
char	*convert_base(char *nbr, char *base_from, char *base_to);
char	*to_base(int nbr, char *base_to, int size_base);
char	**my_str_to_wordtab(char *str);

#endif /* !MY_H_ */
