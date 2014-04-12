/*
** list.h for list.h in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 12:17:21 2013 sebastien bequignon
** Last update Mon Apr 29 19:28:22 2013 sebastien bequignon
*/

#ifndef LIST_H_
# define LIST_H_

/*
** for size_t
*/
#include <stddef.h>

typedef enum
  {
    NODE_CHAR,
    NODE_STRING,
    NODE_INT,
    NODE_ADRESSES,
    NODE_STRUCT,
    NODE_CUSTOM,
    NODE_UNKNOWN,
    NODE_EMPTY
  } e_node_type;

typedef struct	s_node
{
  e_node_type	type;
  size_t	size;
  void		*data;
  struct s_node	*next;
  struct s_node	*prev;
}		t_node;

typedef struct	s_list
{
  t_node	*head;
  t_node	*tail;
  t_node	*current;
  size_t	nb_elem;
}		t_list;

/* ########## CREATE_DESTROY */

t_list	*create_list();
t_list	*list_clean(t_list *list);
void	list_destroy(t_list **list);
void	list_destroy_free_data(t_list **list);

/* ########## PUSH */

int	list_push_back(t_list *list, void *data);
int	list_push_front(t_list *list, void *data);
int	list_push_front_node(t_list *list, t_node *elem);
int	list_push_back_node(t_list *list, t_node *elem);
t_list	*list_push_sort(t_list *list, t_node *elem,
				int (*comp)(t_node *, t_node *));

/* ########## PULL */

t_list	*list_delete_node(t_list *list, t_node *to_delete);
t_list	*list_pop_back(t_list *list);
t_list	*list_pop_front(t_list *list);
t_list	*list_pop_current(t_list *list);
t_list	*list_check_pop_node(t_list *list, t_node *to_delete);

/* ########## LIST_APPLY */

void	swap_with_next(t_list *list, t_node *current);
int	list_forall(t_list *list, int (*func)(t_node *));
t_list	*list_iter(t_list *list, void (*func)(t_node *));
t_list	*list_iter2(t_list *list, void (*func)(t_node *, void *), void *param);
t_list	*list_sort(t_list *list, int (*func)(t_node *, t_node *));

/* ########## TRANSFORM */

void	list_reverse(t_list *list);
t_list	*list_partition(t_list *src, t_list **accept, t_list **other,
			       int (*check)(t_node *));
t_list	*list_transform(t_list *list, t_node *(*func)(t_node *));

/* ########## PREV_NEXT */

t_node	*list_next_loop(t_list *list);
t_node	*list_prev_loop(t_list *list);
t_node	*list_next(t_list *list);
t_node	*list_prev(t_list *list);

/* ########## POSITION */

t_node	*list_start(t_list *list);
t_node	*list_end(t_list *list);
t_node	*list_index(t_list *list, size_t i);

/* ########## SEARCH */

t_node	*list_search(t_list *list, void *data);
t_node	*list_search_node(t_list *list, t_node *to_search);
t_node	*list_search_node_func(t_list *list, t_node *node,
			  int (*comp)(t_node *, t_node *));
t_node	*list_search_data(t_list *list, void *data,
			  int (*comp)(void *, void *));

/* ########## DEFAULT FUNC */

int	default_node_comparison(t_node *first, t_node *second);
int	default_data_comparison(void *first, void *second);
int	strcmp_node(t_node *node, t_node *node2);
void	free_node_data(t_node *node);
void	list_dump(t_list *list);

/* ########## DEFAULT FUNC */

int	list_is_empty(t_list *list);
size_t	list_size(t_list *list);

/* ########## NODE */

t_node		*empty_node();
t_node		*default_node(void *data);
t_node		*custom_node(void *data, e_node_type type, size_t size);

/* ################################# */
/* #				   # */
/* #	      TO_DO		   # */
/* #				   # */
/* ################################# */

/* LIST_NEXT_PREV -------------------*/

//list_next_loop_for
//list_prev_loop_for

/* LIST_PULL ------------------------*/

//list_remove_if
//list_remove_if_free

/* LIST_TRANSFORM -------------------*/

//filter
//concat_list

#endif /* !LIST_H_ */
