void	my_putchar(char c)
{
  write(1, &c, 1);
}

int    my_put_nbr(int n)
{
  int unit = 1;

  if (n < 0)
    {
      n = -n;
      my_putchar('-');
    }
  while ((n/unit) > 9)
    unit *= 10;
  while (unit > 0)
    {
      my_putchar('0' + (n/unit) % 10);
      unit /= 10;
    }
}
