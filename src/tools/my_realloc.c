/*
** my_realloc.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:15:10 2016 Ronan Boiteau
** Last update Tue Jun 14 19:31:29 2016 Ronan Boiteau
*/

#include <stdlib.h>

char		*my_realloc(char *old_str, const size_t size)
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
