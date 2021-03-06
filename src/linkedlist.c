/*
** linked_list.c for  in /home/bob/sw_programming/src
** 
** Made by Bob
** Login   <robert.ta@epitech.eu>
** 
** Started on  Tue Nov 21 07:07:04 2017 Bob
** Last update Fri Dec  8 09:51:46 2017 Bob
*/

#include "linkedlist.h"
#include "mysearch.h"

list    insert_list(list list, char *name, int nbr)
{
  s_elem *new = malloc(sizeof(s_elem));
  new->name = name;
  new->nbr = nbr;
  new->next = NULL;
  if (list == NULL)
    return new;
  else
    {
      s_elem *tmp = list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      return (list);
    }
}

void    show_list(list list)
{
  s_elem *tmp = list;
  int	 i = 0;
  
  while (tmp != NULL)
    {
      printf("%s\t found %d time(s) in the file \n", tmp->name, tmp->nbr);
      tmp = tmp->next;
      i++;
    }
  printf("Total file(s): %d\n", i);
}

list	sort_list(list list)
{
  s_elem *x, *y, *e;

  x = list;
  list = NULL;
  while(x != NULL)
    {
      e = x;
      x = x-> next;
      if (list != NULL)
	{
	  if (e->nbr < list->nbr)
	    {
	      y = list;
	      while ((y->next != NULL) && (e->nbr < y->next->nbr))
		{
		  y = y->next;
		}
	      e->next = y->next;
	      y->next = e;
	    }
	  else
	    {
	      e->next = list;
	      list = e;
	    }
	}
      else
	{
	  e->next = NULL;
	  list = e;
	}
    }
  return (list);
}

list	free_list(list list)
{
  if (list == NULL)
    return (NULL);
  else
    {
      s_elem *tmp;
      tmp = list->next;
      free(list);
      return free_list(tmp);
    }
}
