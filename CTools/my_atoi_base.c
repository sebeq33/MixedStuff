/*
** my_atoi_base.c for bequig_s in /exam//rendu/ex_3
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Wed Mar 20 18:32:57 2013 sebastien bequignon
** Last update Wed Mar 20 19:25:08 2013 sebastien bequignon
*/

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

static int	getplace(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

/* static int	getnbr_base(char *str, char *base, int lenbase, int lenstr) */
/* { */
/*   int		value; */
/*   int		result; */

/*   lenstr--; */
/*   value = getplace(*str, base); */
/*   printf("char : %c |||| len : %d |||| place : %d\n", *str, lenstr, value); */
/*   if (*(str + 1) == '\0') */
/*     return (value); */
/*   result = (value * lenbase * lenstr); */
/*   printf("result : %d * %d * %d = %d\n", value, lenbase, lenstr, result); */
/*   return (result + getnbr_base(str + 1, base, lenbase, lenstr - 1)); */
/* } */

/* int	my_atoi_base(char *str, char *base) */
/* { */
/*   if (!str || !*str || (*str == '-' && *(str + 1) == '\0')) */
/*     return (0); */
/*   if (*str == '-') */
/*     return ((getnbr_base(&str[1], base, my_strlen(base), my_strlen(&str[1]))) * -1); */
/*   return (getnbr_base(str, base, my_strlen(base), my_strlen(str))); */
/* } */

int	my_atoi_base(char *str, char *base)
{
  int	i;
  int	len;
  int	mul;
  int	neg;
  int	res;

  if (!str || !*str || (*str == '-' && *(str + 1) == '\0'))
    return (0);
  len = my_strlen(base);
  mul = 1;
  res = 0;
  i = my_strlen(str) - 1;
  neg = (*str == '-') ? 1 : 0;
  while (i >= 0 && str[i] != '-')
    {
      res += getplace(str[i], base) * mul;
      mul *= len;
      i--;
    }
  return (neg ? res * -1 : res);
}
