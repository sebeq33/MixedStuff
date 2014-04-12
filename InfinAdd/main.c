void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

int	manage_sign(char **s1, char **s2)
{
  int	neg1;
  int	neg2;
  int	res;
  char	*tmp;

  neg1 = **s1 == '-' ? 1 : 0;
  neg2 = **s2 == '-' ? 1 : 0;
  *s1 = &((*s1)[neg1]);
  *s2 = &((*s2)[neg2]);
  if ((res = my_strcmp(*s1, *s2)) == 0)
    return (neg1 == neg2);
  if (res < 0)
    {
      tmp = *s1;
      *s1 = *s2;
      *s2 = tmp;
      if (neg2)
	my_putchar('-');
    }
  else if (neg1)
    my_putchar('-');
  return (neg1 == neg2);
}

int	main(int ac, char **av)
{
  char	*result;

  if (ac > 2)
    {
      if (manage_sign(&av[1], &av[2]))
	infin_add(av[1], av[2]);
      else
	infin_sub(av[1], av[2]);
    }
  my_putchar('\n');
  return (0);
}
