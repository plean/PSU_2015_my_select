/*
** bonus.c for  in /home/planch_j/rendu/PSU/PSU_2015_my_select
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Tue Dec  8 00:56:21 2015 Jean PLANCHER
** Last update Wed Dec  9 16:53:27 2015 Jean PLANCHER
*/

#include <stdlib.h>
#include <ncurses.h>
#include "include/my.h"

void	my_konami_final(t_list *list, int i, int e)
{
  if (i == 'b')
    {
      if (e == 0)
	{
	  i = getch();
	  my_konami_final(list, i, 1);
	}
    }
  else if (i == 'a')
    if (e == 1)
      {
	erase();
	attron(A_REVERSE | A_BLINK);
	mvprintw((LINES - 1) / 2, (COLS - 6) / 2, "KONAMI");
	while (getch() != 27)
	  {
	    erase();
	    mvprintw((LINES - 1) / 2, (COLS - 6) / 2, "KONAMI");
	  }
	attroff(A_REVERSE | A_BLINK);
	endwin();
	delete_list(&list);
	exit(84);
      }
}

void	my_konami(t_list *list, int i, int e, int k)
{
  if (i == KEY_LEFT)
    {
      i = getch();
      if (e == 0 && k == 0)
	my_konami(list, i, 1, 0);
      else if (e == 0 && k == 1)
	my_konami(list, i, 1, 1);
    }
  else if (i == KEY_RIGHT)
    {
      i = getch();
      if (e == 1 && k == 0)
	my_konami(list, i, 0, 1);
      else if (e == 1 && k == 1)
	my_konami_final(list, i, 0);
    }
}

void	my_konami_code(t_list *list, int i, int e, int k)
{
  if (i == KEY_UP)
    {
      i = getch();
      my_konami_code(list, i, 1, 0);
    }
  else if (i == KEY_DOWN)
    {
      if (e == 1 && k == 0)
	{
	  i = getch();
	  my_konami_code(list, i, 0, 1);
	}
      else if (e == 0 && k == 1)
	{
	  i = getch();
	  my_konami(list, i, 0, 0);
	}
    }
}

void	my_bonus(t_list *list, int i)
{
  if (i == 'b')
    {
      i = getch();
      if (i == KEY_UP)
	{
	  i = getch();
	  my_konami_code(list, i, 0, 0);
	}
    }
}
