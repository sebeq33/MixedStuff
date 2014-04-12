/*
** my.h for my.h in /home/bequig_s//piscine/jour9
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 11 10:44:26 2012 sebastien bequignon
** Last update Thu Nov 29 17:59:40 2012 sebastien bequignon
*/

#ifndef MY_H_
# define MY_H_

void    my_putchar(char c);
void    my_put_nbr(int nb);
void    my_putstr(char *str);
int     my_strlen(char *str);
char    *my_strcpy(char *dest, char *src);
char    *my_strncpy(char *dest, char *src, int nb);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strcat(char *dest, char *src);
char    *my_epur_str(char *str);

#endif /* !MY_H_ */
