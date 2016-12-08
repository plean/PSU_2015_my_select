/*
** functions.c for  in /home/planch_j/rendu/PSU/PSU_2015_my_select
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Dec  7 13:16:20 2015 Jean PLANCHER
** Last update Mon Dec  7 13:16:59 2015 Jean PLANCHER
*/

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}
