/*
** manage_list_dir.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 09:33:09 2012 sebastien bequignon
** Last update Sun Nov  4 15:43:19 2012 sebastien bequignon
*/

#include "headers/my_ls.h"
#include "headers/func_prototype.h"
#include <stdlib.h>

/* void		insert_sort(t_list **list, t_list *to_add) */
/* { */
/*   t_list	*current; */

/*   current = *list; */
/*   if (my_strcmp(current->data, to_add->data) > 0) */
/*     { */
/*       to_add->next = current; */
/*       *list = to_add; */
/*     } */
/*   else */
/*     { */
/*       while (current->next != NULL && */
/*              my_strcmp(current->data, to_add->data) > 0) */
/*         current = current->next; */
/*       to_add->next = current->next; */
/*       current->next = to_add; */
/*     } */
/* } */

/* void		insert_reverse_sort(t_list **list, t_list *to_add) */
/* { */
/*   t_list	*current; */

/*   current = *list; */
/*   if (my_strcmp(current->data, to_add->data) < 0) */
/*     { */
/*       to_add->next = current; */
/*       *list = to_add; */
/*     } */
/*   else */
/*     { */
/*       while (current->next != NULL && */
/*              my_strcmp(current->next->data, to_add->data) > 0) */
/*         current = current->next; */
/*       to_add->next = current->next; */
/*       current->next = to_add; */
/*     } */
/* } */

/* void		add_dir_to_list(t_list **list, void *data, t_param *param) */
/* { */
/*   t_list	*current; */
/*   t_list	*to_add; */

/*   to_add = create_dir_node(data); */
/*   if (*list == NULL) */
/*     *list = to_add; */
/*   else */
/*     { */
/*       current = *list; */
/*       if (param->U) */
/* 	add_dir_to_list_end(list, to_add); */
/*       else if (param->r) */
/* 	insert_reverse_sort(list, to_add); */
/*       else */
/* 	insert_sort(list, to_add); */
/*     } */
/* } */
