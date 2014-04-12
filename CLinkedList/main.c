/*
** main.c for main.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr 10 14:58:43 2013 sebastien bequignon
** Last update Mon Apr 29 19:33:52 2013 sebastien bequignon
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void		my_putstr(t_node *param)
{
  char		*str;

  if (param == NULL || param->data == NULL)
    {
      printf("NULL\n");
      return ;
    }
  str = (char *) param->data;
  printf("%s\n", str);
}

int		strcmp_data(void *one, void *two)
{
  return (strcmp((char *) one, (char *) two) == 0);
}

void		test1()
{
  t_list	*list;

  if ((list = create_list()) == NULL)
    exit(0);
  list_push_sort(list, default_node(strdup("YZ")), &strcmp_node);
  list_push_sort(list, default_node(strdup("GHIJKL")), &strcmp_node);
  list_push_sort(list, default_node(strdup("MNOPQR")), &strcmp_node);
  list_push_sort(list, default_node(strdup("ABCDEF")), &strcmp_node);
  list_push_sort(list, default_node(strdup("STUVWX")), &strcmp_node);
  list_iter(list, &my_putstr);

  printf("size_list [%d]\n", list_size(list));

  puts("------------ search ----------");

  my_putstr(list_search_data(list, "jkl", &strcmp_data));
  my_putstr(list_search_data(list, "GHIJKL", &strcmp_data));

  puts("------------------------------");

  free(list->head->data);
  free(list->tail->data);
  list_pop_front(list);
  list_pop_back(list);
  list_iter(list, &my_putstr);

  printf("size_list [%d]\n", list_size(list));

  puts("------------------------------");

  list_iter(list, &free_node_data);
  list_clean(list);
  list_iter(list, &my_putstr);

  puts("------------------------------");

  printf("size_list [%d]\n", list_size(list));
  list_destroy_free_data(&list);
  printf("size_list [%d]\n", list_size(list));
}

void		test2()
{
  t_list	*list;
  t_node	*node;
  void		*data;

  if ((list = create_list()) == NULL)
    exit(0);
  list_push_front(list, strdup("AAA"));
  list_push_front(list, strdup("BBB"));
  list_push_front(list, strdup("CCC"));
  list_push_front(list, strdup("DDD"));
  list_push_front(list, strdup("EEE"));
  data = strdup("FFF");
  list_push_front(list, data);
  list_iter(list, &my_putstr);
  printf("size_list [%d]\n", list_size(list));

  puts("------------------------------");

  node = list_search(list, data);
  printf("search data : [%s]\n", node->data);

  puts("------------------------------");

  list_reverse(list);
  list_iter(list, &my_putstr);
  printf("size_list [%d]\n", list_size(list));

  puts("------------------------------");

  node = list_end(list);
  while (node != NULL)
    {
      printf("%s\n", node ? node->data : "{NULL}");
      node = list_prev(list);
    }

  puts("------------------------------");

  free(list->head->data);
  list_pop_front(list);
  list_reverse(list);
  list_iter(list, &my_putstr);
  printf("size_list [%d]\n", list_size(list));

  puts("------------------------------");

  node = list_index(list, 3);
  printf("%s\n", node ? node->data : "{NULL}");
  node = list_index(list, 1);
  printf("%s\n", node ? node->data : "{NULL}");
  node = list_index(list, 5);
  printf("%s\n", node ? node->data : "{NULL}");
  node = list_index(list, 0);
  printf("%s\n", node ? node->data : "{NULL}");

  puts("------------------------------");
  printf("size_list [%d]\n", list_size(list));
  list_destroy_free_data(&list);
  printf("size_list [%d]\n", list_size(list));
}

void		test3()
{
    t_list	*list;
  t_node	*node;
  void		*data;

  if ((list = create_list()) == NULL)
    exit(0);
  list_push_front(list, strdup("AAA"));
  list_push_front(list, strdup("BBB"));
  list_push_front(list, strdup("CCC"));
  list_push_front(list, strdup("DDD"));
  list_push_front(list, strdup("EEE"));
  list_push_sort(list, default_node(strdup("YZ")), &strcmp_node);
  list_push_sort(list, default_node(strdup("GHIJKL")), &strcmp_node);
  list_push_sort(list, default_node(strdup("MNOPQR")), &strcmp_node);
  list_push_sort(list, default_node(strdup("ABCDEF")), &strcmp_node);
  list_push_sort(list, default_node(strdup("STUVWX")), &strcmp_node);
  list_dump(list);
  printf("size_list [%d]\n", list_size(list));

  list_destroy_free_data(&list);
}

int		main(int ac, char **av)
{
  test1();
  puts("\n##########################################\n");
  test2();
  puts("\n##########################################\n");
  test3();
  putchar('\n');
  return (0);
}
