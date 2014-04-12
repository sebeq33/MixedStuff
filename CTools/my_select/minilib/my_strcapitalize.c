/*
** my_strcapitalize.c for my_strcapitalize in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Oct  9 00:10:10 2012 sebastien bequignon
** Last update Fri Nov 16 09:43:01 2012 sebastien bequignon
*/

char    *my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i - 1] == ' ' || str[i - 1] == '-' ||
	  str[i - 1] == '+' || i <= 0)
	{
	  if (str[i] >= 'a' && str[i] <= 'z')
	    str[i] = str[i] - 32;
	}
      else if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
