/*
** my.h for  in /home/planch_j/rendu/PSU/PSU_2015_my_select
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Dec  7 12:50:56 2015 Jean PLANCHER
** Last update Tue Dec  8 02:11:01 2015 Jean PLANCHER
*/

#ifndef MY_H_
# define MY_H_

# include "my_list.h"

int	my_select(int ac, t_list *list);
int	my_strlen(char *str);
void	invertator(t_list *list);
void	move_your_body(t_list *list, int i);
int	terminator(t_list *list);
void	my_exit();
void	my_test_exit(t_list *list, int ac);
int	get_nxtcols(t_list *list);
void	my_bonus(t_list *list, int i);

#endif /* !MY_H_ */
