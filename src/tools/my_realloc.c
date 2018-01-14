#include <stdlib.h>

char		*my_realloc(char *old_str, size_t size)
{
  char		*str;
  int		idx;

  if (!(str = malloc(size)))
    return (NULL);
  idx = 0;
  while (old_str[idx])
    {
      str[idx] = old_str[idx];
      ++idx;
    }
  str[idx] = '\0';
  free(old_str);
  return (str);
}
