/*
** element.h for  in /home/planch_j/rendu/PSU/PSU_2015_my_select/test/include
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Wed Dec  2 10:41:24 2015 Jean PLANCHER
** Last update Tue Dec  8 02:35:21 2015 Jean PLANCHER
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct		s_element
{
  char			*data;
  int			curs;
  int			print;
  struct s_element	*nxt;
  struct s_element	*prv;
}			t_element;

typedef struct		s_list
{
  int			length;
  struct s_element	*first;
  struct s_element	*last;
}			t_list;

#endif /* !MY_LIST__H_ */

t_list	*my_new_list();
void	add_end(t_list *list, char *data);
void	add_begin(t_list *list, char *data);
void	add_pos(t_list *list, char *data, int position);
void	delete_list(t_list **list);
