/*
** write.c for write.c in /home/bequig_s//workspace/systemUnixTek2/my_irc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr 24 12:04:07 2013 sebastien bequignon
** Last update Thu May  2 13:45:55 2013 sebastien bequignon
*/

#include <string.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int	my_putstr_fd(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

int	my_puterr(char *error, int ret)
{
  my_putstr_fd(2, error);
  return (ret);
}

int	my_send(int sock, const void *buff, size_t len)
{
  char	fakebuff[1];

  if (read(sock, fakebuff, 0) <= 0 &&
      (fcntl(sock, F_GETFL) != -1 || errno != EBADF))
    return (send(sock, buff, len, 0) > 0);
  return (-1);
}

int	my_sendstr(int sock, const char *buff)
{
  return (my_send(sock, buff, strlen(buff)));
}
