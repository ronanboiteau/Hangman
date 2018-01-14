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
  return (idx == 0 ? NULL : content);
}
