/*
** get_next_read.c for get next read in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Jan 14 15:12:38 2016 Frederic ODDOU
** Last update	Sun Mar 20 14:35:16 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*get_next_read(const int fd)
{
  char		buffer[READ_SIZE + 1];
  char		*str;
  int		size;

  size = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = '\0';
  buffer[0] = '\0';
  while ((size = read(fd, buffer, READ_SIZE)) > 0 && size != -1 && size > 0)
    {
      buffer[size] = '\0';
      if ((str = my_strcat_dyn(str, buffer)) == NULL)
	return (NULL);
      if (size > 0 && buffer[size - 1] == '\n')
	{
	  str[my_strlen(str) - 1] = '\0';
	  return (str);
	}
  }
  if (size == 0 && str[0] != '\0')
    return (str);
  free(str);
  return (NULL);
}
