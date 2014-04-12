/*
** my_isalphanumeric.c for my_isalphanumeric in /home/bequig_s//piscine/libmy
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Wed Oct 17 16:42:40 2012 sebastien bequignon
** Last update Wed Oct 17 18:42:55 2012 sebastien bequignon
*/

int     my_isalphanumeric(char c)
{
  return ((c >= 'a' && c <= 'z') || (c > 'A' && c < 'Z')
          || (c >= '0' && c < '9'));
}
