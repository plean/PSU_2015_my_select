/*
** operation_list.c for  in 
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Thu Dec  3 14:50:45 2015 Jean PLANCHER
** Last update Tue Dec  8 02:32:30 2015 Jean PLANCHER
*/

#include <ncurses.h>
#include <stdlib.h>
#include "include/my_list.h"

void	my_exit()
{
  endwin();
  exit(84);
}

t_list		*my_new_list()
{
  t_list	*list;

  list = malloc(sizeof(t_list*));
  if (list != NULL)
    {
      list->length = 0;
      list->first = NULL;
      list->last = NULL;
    }
  return (list);
}

void		add_end(t_list *list, char *data)
{
  t_element	*new_element;

  new_element = malloc(sizeof(t_element));
  if (new_element == NULL || list == NULL)
    return ;
  new_element->data = data;
  new_element->curs = 0;
  new_element->print = 0;
  new_element->nxt = NULL;
  if (list->last == NULL)
    {
      new_element->prv = NULL;
      list->first = new_element;
      list->last = new_element;
    }
  else
    {
      list->last->nxt = new_element;
      new_element->prv = list->last;
      list->last = new_element;
    }
  list->length++;
}

void	delete_list(t_list **list)
{
  t_element	*element_temp;
  t_element	*element_del;

  if (*list != NULL)
    {
      element_temp = (*list)->first;
      while (element_temp != NULL)
        {
	  element_del = element_temp;
	  element_temp = element_temp->nxt;
	  free(element_del);
        }
      free(*list);
      *list = NULL;
    }
}
