/*
** main.c for main.c in /home/bequig_s/
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Feb 11 20:03:38 2013 sebastien bequignon
** Last update Mon Feb 11 20:05:20 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/cdrom.h>

#define CDDEVICE "/dev/cdrom"

int main(int argc,char **argv)
{
  int cdrom;

  if ((cdrom = open(CDDEVICE, O_RDONLY | O_NONBLOCK)) < 0) {
    perror("open");
    exit(1);
  }

  if (ioctl(cdrom, CDROMEJECT, 0) < 0) {
    perror("ioctl");
    exit(1);
  }

  close(cdrom);
}
