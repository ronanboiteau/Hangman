/*
** get_file.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:16:38 2016 Ronan Boiteau
** Last update Tue Jun 14 19:29:16 2016 Ronan Boiteau
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "tools.h"

static char	*failure(const int fd)
{
  close(fd);
  return (NULL);
}

char		*get_file(const char *filepath)
{
  char		*content;
  int		idx;
  int		fd;
  char		buf;
  int		ret;

  idx = 0;
  buf = '\0';
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (NULL);
  if (!(content = malloc(sizeof(char) * 2)))
    return (failure(fd));
  while ((ret = read(fd, &buf, 1)))
    {
      if (ret == -1)
	return (failure(fd));
      content[idx++] = buf;
      content[idx] = '\0';
      buf = '\0';
      if (!(content = my_realloc(content, sizeof(char) * (idx + 2))))
	return (failure(fd));
    }
  close(fd);
  return (content);
}
