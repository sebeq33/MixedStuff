/*
** my_select.h for my_select.h in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 17:25:10 2012 sebastien bequignon
** Last update Fri Nov 23 13:42:01 2012 sebastien bequignon
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# define NB_SPACES (3)
# define TOO_SMALL "Please resize the window, too small for all elements\n"
typedef struct s_node
{
  int	y;
  int	x;
  char	*value;
  int	size;
  int	selected;
  int	underline;
  struct s_node *next;
  struct s_node *prev;
} t_node;

extern t_node	*g_list;

#endif /* !MY_SELECT_H_ */
