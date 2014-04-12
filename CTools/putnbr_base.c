#include <stdlib.h>

void	my_putstr(char *str)
{
  int i = 0;

  while (str[i] != '\0')
    write(1, &str[i++], 1);
}

int	my_strlen(char *str)
{
  int i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_revstr(char *str)
{
  int n = my_strlen(str);
  int i = 0;
  char stock;

  while (i <n -1 && str[i] != '\0')
    {
      stock = str[i];
      str[i] = str[n - 1];
      str[n - 1] = stock;
      i++;
      n--;
    }
  return (str);
}

char    *my_putnbr_base(int nbr, char *base)
{
  int   nbr_base;
  char  *result;
  int   i;
  int   neg;

  neg = 0;
  if ((result = (char *)malloc(sizeof(*result) * 35)) == 0)
    {
      return (NULL);
    }
  i = 0;
  if (nbr < 0)
    {
      nbr = -nbr;
      neg = 1;
    }
  nbr_base = my_strlen(base);
  while (nbr >= nbr_base)
    {
     result[i] = base[nbr % nbr_base];
     nbr = nbr / nbr_base;
     i++;
    }
  result[i] = base[nbr];
  if (neg == 1)
    result[i++ + 1] = '-';
  result[i++] = '\0';
  return (my_revstr(result));
}

int main()
{
  my_putstr(my_putnbr_base(42, "01"));
}
