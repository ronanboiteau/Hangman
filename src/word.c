/*
** word.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 20:40:26 2016 Ronan Boiteau
** Last update Tue Jun 14 22:19:27 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include <unistd.h>
#include "pendu.h"
#include "msg.h"
#include "tools.h"

static  int	count_words(const char *file)
{
  int		nb_words;
  int		idx;

  nb_words = 0;
  idx = 0;
  while (file[idx])
    {
      if (file[idx] == '\n')
	nb_words++;
      idx++;
    }
  return (nb_words);
}

static char	*get_word(const char *file, int idx)
{
  int		size;
  int		tmp;
  char		*word;

  size = 0;
  while (file[idx + size] && file[idx + size] != '\n')
    ++size;
  if (!(word = malloc(sizeof(char) * (size + 1))))
    {
      my_putstr_fd(2, ERR_MALLOC);
      return (NULL);
    }
  tmp = 0;
  while (file[idx + tmp] && file[idx + tmp] != '\n')
    {
      word[tmp] = file[idx + tmp];
      ++tmp;
    }
  word[tmp] = '\0';
  return (word);
}

char		*select_word(const char *file)
{
  char		*word;
  int		idx;
  int		number;
  int		line;

  idx = 0;
  line = 0;
  if (count_words(file) <= 0)
    {
      my_putstr_fd(2, ERR_DIC_EMPTY);
      return (NULL);
    }
  number = rand() % (count_words(file));
  while (file[idx] && line < number)
    {
      if (file[idx] == '\n')
	line++;
      idx++;
    }
  return (!(word = get_word(file, idx)) ? NULL : word);
}
