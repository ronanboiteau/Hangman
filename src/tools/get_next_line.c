/*
** get_next_line.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:14:16 2016 Ronan Boiteau
** Last update Tue Jun 14 20:01:36 2016 Ronan Boiteau
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "tools.h"

char		*get_next_line(const int fd)
{
  char		*content;
  int		idx;
  int		ret;
  int		buf;

  idx = 0;
  buf = '\0';
  if (!(content = malloc(sizeof(char) * 2)))
    return (NULL);
  while ((ret = read(fd, &buf, 1)) && buf != '\n')
    {
      if (ret == -1)
	return (NULL);
      content[idx++] = buf;
      content[idx] = '\0';
      buf = '\0';
      if (!(content = my_realloc(content, sizeof(char) * (idx + 2))))
	return (NULL);
    }
  return (content);
}
