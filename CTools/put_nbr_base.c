void	my_putchar(char c)
{
  write(1, &c, 1);
}

void    put_zero(int n)
{
  my_putchar('\\');
  if (n < 8)
    my_putchar('0');
  if (n < 63)
    my_putchar('0');
}

unsigned int    octal_with_zero(int n)
{
  put_zero(n);
  put_nbr_base(n, base8);
  return (n);
}

void    put_nbr_base(unsigned int nb, char *base)
{
  unsigned int  len_base;

  len_base = my_strlen(base);
  if (nb >= len_base)
    put_nbr_base(nb / len_base, base);
  my_putchar(base[nb % len_base]);
}
