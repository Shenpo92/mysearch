/*
** mysearch.c for mysearch in /home/bob/sw_programming
** 
** Made by Bob
** Login   <robert.ta@epitech.eu>
** 
** Started on  Fri Oct 27 08:14:42 2017 Bob
** Last update Fri Dec  8 09:08:26 2017 Bob
*/

#define _GNU_SOURCE
#include "mysearch.h"
#include "linkedlist.h"

int	main(int ac, char **av){
  char		*word;
  char		*line = NULL;
  DIR		*dir;
  struct dirent	*r_file;
  char		*filename;
  FILE		*file;
  list		list = NULL;
  size_t	len = 0;
  ssize_t	read;
  int		nbr;

  if (av[1] == NULL || ac <= 1)
    {
      printf("%s\n", "You must enter the word you want to research\nUsage: ./mysearch searchword");
      return (1);
    }
  word = av[1];
  if ((dir = opendir(".")) == NULL)
    {
      printf("%s\n", "Error: Could not open current directory");
      return (-1);
    }
  while ((r_file = readdir(dir)) != NULL)
    {
      filename = r_file->d_name;
      if(strstr(filename, ".txt") != NULL)
	{
	  file = fopen(filename, "r");
	  nbr = 0;
	  while ((read = getline(&line, &len, file))!= -1)
	    {
	      //Loop to find the number of occurences in the line
	      while ((line = strcasestr(line, word)) != NULL)
		{
		  nbr++;
		  line++;
		}
	    }
	  fclose(file);
	  if (nbr > 0)
	    list = insert_list(list, filename, nbr);
	}
    }
  if (list != NULL)
    {
      list = sort_list(list);
      show_list(list);
      free_list(list);
    }
  else
    printf("Did not find the word: '%s' in any file\n", word);
  return(0);
}
