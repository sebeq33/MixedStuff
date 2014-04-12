/*
** manage_list_dir.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 09:33:09 2012 sebastien bequignon
** Last update Sun Nov  4 22:02:18 2012 sebastien bequignon
*/

#include "headers/my_ls.h"
#include "headers/file.h"
#include "headers/func_prototype.h"
#include "minilib/my.h"
#include <stdlib.h>

void	insert_file_reverse_time_sort(t_file **list, t_file *to_add)
{
  t_file	*current;

  current = *list;
  if ((int) current->time > (int) to_add->time)
    {
      to_add->next = current;
      *list = to_add;
    }
  else
    {
      while (current->next != NULL && (int) current->next->time < (int) to_add->time)
      current = current->next;
      to_add->next = current->next;
      current->next = to_add;
    }
}

void	insert_file_time_sort(t_file **list, t_file *to_add)
{
  t_file	*current;

  current = *list;
  if ((int) current->time < (int) to_add->time)
    {
      to_add->next = current;
      *list = to_add;
    }
  else
    {
      while (current->next != NULL && (int) current->next->time > (int) to_add->time)
      current = current->next;
      to_add->next = current->next;
      current->next = to_add;
    }
}

void	insert_file_reverse_sort(t_file **list, t_file *to_add)
{
  t_file	*current;

  current = *list;
  if (my_strcmp_ls(current->f_name, to_add->f_name) < 0)
    {
      to_add->next = current;
      *list = to_add;
    }
  else
    {
      while (current->next != NULL &&
             my_strcmp_ls(current->next->f_name, to_add->f_name) > 0)
        current = current->next;
      to_add->next = current->next;
      current->next = to_add;
    }
}

void	insert_file_sort(t_file **list, t_file *to_add)
{
  t_file	*current;

  current = *list;
  if (my_strcmp_ls(current->f_name, to_add->f_name) > 0)
    {
      to_add->next = current;
      *list = to_add;
    }
  else
    {
      while (current->next != NULL &&
             my_strcmp_ls(current->next->f_name, to_add->f_name) < 0)
	current = current->next;
      to_add->next = current->next;
      current->next = to_add;
    }
}

void		add_file_to_list(t_file **list, t_file *file, t_param *param)
{
  if (*list == NULL)
    *list = file;
  else
    {
      if (param->U)
	add_file_to_list_end(list, file);
      else if (param->r && param->t)
	insert_file_reverse_time_sort(list, file);
      else if (param->t)
	insert_file_time_sort(list, file);
      else if (param->r)
	insert_file_reverse_sort(list, file);
      else
	insert_file_sort(list, file);
    }
}
