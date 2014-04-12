#include <stdlib.h>
#include <stdio.h>

char	*my_alloc(int len)
{
  char	*to_alloc;
  int	i;

  if ((to_alloc = (char *) malloc(len * sizeof(char))) == NULL)
    exit(write(1, "malloc failed\n", my_strlen("malloc failed\n")));
  i = 0;
  while (i < len)
    to_alloc[i++] = '\0';
  return (to_alloc);
}

void	string_to_val(char *str, int len)
{
  int	i;

  i = 0;
  while (i < len)
    str[i++] -= '0';
}

void show_result_to_char(char *str, int len)
{
  int	zero;
  int	i;

  zero = 0;
  i = 0;
  while (i < len)
    {
      if (zero || str[i] != 0 || i + 1 == len)
	{
	  my_putchar(str[i] + '0');
	  zero = 1;
	}
      i++;
    }
  free(str);
}

void infin_sub(char *s1, char *s2)
{
  char	*result;
  int	len1;
  int	len2;
  int	pos;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  result = my_alloc(len1);
  string_to_val(s1, len1);
  string_to_val(s2, len2);
  pos = len1 - 1;
  len2--;
  while (pos >= 0)
    {
      result[pos] += (len2 < 0 ? 0 : s2[len2]);
      if (s1[pos] < result[pos])
	{
	  s1[pos] += 10;
	  result[pos - 1] = 1;
	}
      result[pos] = s1[pos] - result[pos];
      pos--;
      len2--;
    }
  show_result_to_char(result, len1);
}

void infin_add(char *s1, char *s2)
{
  char	*result;
  int	save_len;
  int	len1;
  int	len2;
  int	pos;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  result = my_alloc(len1 + 1);
  string_to_val(s1, len1);
  string_to_val(s2, len2);
  save_len = len1;
  pos = len1;
  len1--;
  len2--;
  while (pos > 0)
    {
      result[pos] += s1[len1] + (len2 < 0 ? 0 : s2[len2]);
      result[pos - 1] = result[pos] / 10;
      result[pos] = result[pos] % 10;
      pos--;
      len1--;
      len2--;
    }
  show_result_to_char(result, save_len + 1);
}
