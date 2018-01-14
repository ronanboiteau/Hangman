#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "tools.h"

char		*get_next_line(int fd)
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
  return (buf != '\n' && idx == 0 ? NULL : content);
}
