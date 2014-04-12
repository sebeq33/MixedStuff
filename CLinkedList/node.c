/*
** node.c for node.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 13:33:35 2013 sebastien bequignon
** Last update Mon Apr 29 18:44:57 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

t_node		*empty_node()
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->type = NODE_EMPTY;
  node->size = 0;
  node->data = NULL;
  node->next = NULL;
  node->prev = NULL;
  return (node);

}

t_node		*default_node(void *data)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->type = NODE_UNKNOWN;
  node->size = 0;
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

t_node		*custom_node(void *data, e_node_type type, size_t size)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->type = type;
  node->size = size;
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}
