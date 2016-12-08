/*
** list.c for  in /home/planch_j/rendu/PSU/PSU_2015_my_select/test
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Wed Dec  2 14:04:50 2015 Jean PLANCHER
** Last update Wed Dec  9 16:52:40 2015 Jean PLANCHER
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my_list.h"
#include "include/my.h"

void		display_list(t_list *list)
{
  t_element	*element_temp;
  char		c;
  int		e;

  e = 0;
  c = 32;
  element_temp = list->first;
  if (list != NULL)
    {
      while (element_temp != NULL)
        {
          if (element_temp->print == 1 && e == 1)
            {
              write(1, &c, 1);
              write(1, element_temp->data, my_strlen(element_temp->data));
            }
          else if (element_temp->print == 1)
            {
              write(1, element_temp->data, my_strlen(element_temp->data));
              e = 1;
            }
	  element_temp = element_temp->nxt;
        }
    }
}

int	main(int ac, char **av)
{
  t_element	*element;
  t_list	*list;
  int		i;

  if (ac < 2)
    {
      write(2, "Error: Inccorect Number of Parameters.\n", 39);
      return (0);
    }
  i = 0;
  element = NULL;
  list = my_new_list();
  while (++i != ac)
    add_end(list, av[i]);
  element = list->first;
  element->curs = 1;
  i = my_select(ac, list);
  if (i == 1)
    display_list(list);
  delete_list(&list);
  return (0);
}
