/*
** stuffs.c for  in /home/planch_j/rendu/PSU/PSU_2015_my_select
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Dec  7 17:50:16 2015 Jean PLANCHER
** Last update Tue Dec  8 02:33:39 2015 Jean PLANCHER
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_list.h"
#include "include/my.h"

void	my_test_exit(t_list *list, int ac)
{
  if (ac - 1 >= (LINES * (COLS / get_nxtcols(list))))
    {
      endwin();
      write(2, "Error: Window too small.\n", 25);
      exit(84);
    }
}

void		move_your_body(t_list *list, int i)
{
  t_element	*element_temp;

  element_temp = list->first;
  if (list != NULL)
    while (element_temp->curs == 0)
      element_temp = element_temp->nxt;
  element_temp->curs = 0;
  if (i == 1)
    if (element_temp->prv == NULL)
      while (element_temp->nxt != NULL)
	element_temp = element_temp->nxt;
    else
      element_temp = element_temp->prv;
  else
    if (element_temp->nxt == NULL)
      while (element_temp->prv != NULL)
	element_temp = element_temp->prv;
    else
      element_temp = element_temp->nxt;
  element_temp->curs = 1;
}

void		invertator(t_list *list)
{
  t_element	*element_temp;

  element_temp = list->first;
  if (list != NULL)
    while (element_temp->curs == 0)
      element_temp = element_temp->nxt;
  element_temp->print = (element_temp->print + 1) % 2;
  move_your_body(list, 0);
}

void	sarah_connor(t_list *list, t_element *element_temp)
{
  if (element_temp->nxt == NULL)
    {
      element_temp = element_temp->prv;
      free(element_temp->nxt);
      element_temp->nxt = NULL;
      move_your_body(list, 1);
    }
  else if (element_temp->prv == NULL)
    {
      element_temp = element_temp->nxt;
      free(element_temp->prv);
      element_temp->prv = NULL;
      list->first = element_temp;
    }
  else
    {
      element_temp = element_temp->nxt;
      element_temp->prv = element_temp->prv->prv;
      element_temp = element_temp->prv;
      free(element_temp->nxt);
      element_temp->nxt = element_temp->nxt->nxt;
    }
}

int		terminator(t_list *list)
{
  t_element	*element_temp;

  element_temp = list->first;
  if (list != NULL)
    while (element_temp->curs == 0)
      element_temp = element_temp->nxt;
  move_your_body(list, 0);
  if (element_temp->nxt == NULL && element_temp->prv == NULL)
    {
      free(element_temp);
      return (1);
    }
  sarah_connor(list, element_temp);
  return (0);
}
