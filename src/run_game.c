/*
** run_game.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:41:36 2016 Ronan Boiteau
** Last update Tue Jun 14 21:01:10 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "msg.h"
#include "pendu.h"
#include "tools.h"

static int	chk_input(const char *input)
{
  if (!input || !input[0])
    {
      my_putstr_fd(2, ERR_NO_LETTER);
      return (1);
    }
  if (input[1])
    {
      my_putstr_fd(2, TOO_MANY_LETTERS);
      return (1);
    }
  return (0);
}

static int	find_letter(char *word, char *word_disp, const char letter)
{
  int		idx;
  int		found;

  found = 0;
  idx = 0;
  while (word[idx])
    {
      if (word[idx] == letter)
	{
	  found = 1;
	  word[idx] = CHAR_HIDDEN;
	  word_disp[idx] = letter;
	}
      ++idx;
    }
  return (found);
}

static int	is_done(const char *word,
			const char *word_disp,
			const int try,
			char *input)
{
  int		idx;

  free(input);
  my_putstr(word_disp);
  my_putchar('\n');
  my_putnbr(try);
  my_putstr("\n\n");
  if (try <= 0)
    {
      my_putstr_fd(2, NO_TRY_LEFT);
      return (1);
    }
  idx = 0;
  while (word[idx])
    {
      if (word[idx] != CHAR_HIDDEN)
	return (0);
      ++idx;
    }  
  my_putstr(MSG_WIN);
  return (1);
}

void		run_game(char *word, char *word_disp, int try)
{
  int		done;
  int		found;
  char		*input;

  done = 0;
  while (!done)
    {
      if (is_done(word, word_disp, try, input))
	return ;
      input = get_next_line(0);
      if (!chk_input(input))
	{
	  my_putstr("Votre caractere: ");
	  my_putchar(input[0]);
	  my_putchar('\n');
	  if (!(found = find_letter(word, word_disp, input[0])))
	    {
	      my_putchar_fd(2, input[0]);
	      my_putstr_fd(2, LETTER_NOT_FOUND);
	      --try;
	    }
	}
    }
}
