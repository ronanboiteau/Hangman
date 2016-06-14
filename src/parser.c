/*
** parser.c for parser in /home/jamet_a/colle/CPE_colle_semaine8/CPE_colle_semaine8
** 
** Made by jamet alexis
** Login   <jamet_a@epitech.net>
** 
** Started on  Tue Jun 14 19:20:04 2016 jamet alexis
** Last update Tue Jun 14 20:17:09 2016 jamet alexis
*/

#include "pendu.h"
#include "tools.h"

int	check_line(const char *file)
{
  int	i;

  i = 0;
  while (file[i])
    {
      if (file[i] < 'A' || (file[i] > 'Z' && file[i] < 'a')
	  || file[i] > 'z')
	{
	  my_putstr_error(FALSE_WORD);
	  return (1);
	}
      i++;
    }
  return (0);
}

int    	count_word(const char *file)
{
  int	number_words;
  int	idx;

  number_words = 0;
  idx = 0;
  while (file[i])
    {
      if (file[i] == '\n')
	idx++;
      i++;
    }
  return (number_words);
}

char	*select_word(const char *file)
{
  const char	*word;
  int		i;
  int		number;
  int		idx;
  int		lettre;

  i = 0;
  idx = 0;
  lettre = 0;
  number = rand()%(count_word(file));
  while (file[i] && idx <= number)
    {
      if (file[i] == '\n')
	idx++;
      i++;
    }
  i--;
  while (file[i] != '\n')
    i--;
  word[lettre++] = file[i++];
  return (word);
}

void	display_stars(const char *word)
{
  int	i;

  i = 0;
  while (i != my_strlen(word))
    {
      my_putchar('*');
      i++;
    }
}
