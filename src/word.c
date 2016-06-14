/*
** word.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 20:40:26 2016 Ronan Boiteau
** Last update Tue Jun 14 21:02:15 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include <unistd.h>
#include "pendu.h"
#include "tools.h"

static  int    	count_words(const char *file)
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

static int	get_word_size(const char *file, const int idx)
{
  int		size;

  size = 0;
  while (file[idx + size] && file[idx + size] != '\n')
    ++size;
  return (size);
}

char		*select_word(const char *file)
{
  char		*word;
  int		idx;
  int		number;
  int		tmp;

  idx = 0;
  tmp = 0;
  number = rand() % ((count_words(file) + 1));
  while (file[idx] && tmp < number)
    {
      if (file[idx] == '\n')
	tmp++;
      idx++;
    }
  if (!(word = malloc(sizeof(char) * (get_word_size(file, idx) + 1))))
    return (NULL);
  tmp = 0;
  while (file[idx + tmp] && file[idx + tmp] != '\n')
    {
      word[tmp] = file[idx + tmp];
      ++tmp;
    }
  word[tmp] = '\0';
  return (word);
}
