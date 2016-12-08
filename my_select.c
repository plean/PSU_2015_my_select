/*
** my_select.c for  in /home/planch_j/rendu/PSU/PSU_2015_my_select
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Thu Dec  3 17:27:32 2015 Jean PLANCHER
** Last update Tue Dec  8 17:18:23 2015 Jean PLANCHER
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_list.h"
#include "include/my.h"

int		get_nxtcols(t_list *list)
{
  t_element	*element_temp;
  int		i;
  int		k;

  i = 0;
  element_temp = list->first;
  if (list != NULL)
    while (element_temp != NULL)
      {
	k = my_strlen(element_temp->data) + 1;
	if (k > i)
	  i = k;
	element_temp = element_temp->nxt;
      }
  return (i);
}

void		print_elem(t_list *list)
{
  t_element	*element_temp;
  int		pos_x;
  int		pos_y;

  pos_x = pos_y = 0;
  element_temp = list->first;
  if (list != NULL)
    while (element_temp != NULL)
      {
	if (element_temp->print == 1)
	  attron(A_REVERSE);
	if (element_temp->curs == 1)
	  attron(A_UNDERLINE);
	mvprintw(pos_y, pos_x, element_temp->data);
	attroff(A_UNDERLINE | A_REVERSE);
	pos_y = pos_y + 1;
	if (pos_y >= LINES)
	  {
	    pos_x = pos_x + get_nxtcols(list);
	    pos_y = 0;
	  }
	element_temp = element_temp->nxt;
      }
}

void	my_init_screen()
{
  initscr();
  curs_set(0);
  raw();
  noecho();
  keypad(stdscr, TRUE);
}

void	my_select_suite(t_list *list, int i)
{
  if (i == ' ')
    invertator(list);
  else if (i == KEY_UP)
    move_your_body(list, 1);
  else if (i == KEY_DOWN)
    move_your_body(list, 0);
}

int	my_select(int ac, t_list *list)
{
  int	i;

  i = 0;
  my_init_screen();
  print_elem(list);
  my_test_exit(list, ac);
  while(i != 27)
    {
      i = getch();
      my_test_exit(list, ac);
      my_select_suite(list, i);
      my_bonus(list, i);
      if (i == 10)
	{
	  endwin();
	  return (1);
	}
      else if (i == KEY_BACKSPACE || i == KEY_DC)
	if (terminator(list) == 1)
	  my_exit();
      erase();
      print_elem(list);
    }
  my_exit();
  return (0);
}
