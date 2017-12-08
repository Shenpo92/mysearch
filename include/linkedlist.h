/*
** linked_list.h for linked_list in /home/bob/sw_programming
** 
** Made by Bob
** Login   <robert.ta@epitech.eu>
** 
** Started on  Wed Nov  8 03:41:53 2017 Bob
** Last update Tue Nov 21 11:28:53 2017 Bob
*/

typedef struct Elem
{
  char		*name;
  int		nbr;
  struct Elem	*next;  
}s_elem;

typedef s_elem *list;
  
list	insert_list(list list, char *name, int nbr);
list	sort_list(list list);
void	show_list(list list);
list	free_list(list list);
