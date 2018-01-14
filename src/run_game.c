#include <stdlib.h>
#include "msg.h"
#include "hangman.h"
#include "tools.h"

static int	chk_input(const char *input)
{
  if (!input || !input[0] || input[1])
    {
      my_putstr_fd(2, ERR_LETTER);
      return (1);
    }
  return (0);
}

static int	find_letter(char *word, char *word_disp, char letter)
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
			int try,
			char *input)
{
  int		idx;

  free(input);
  my_putstr("\n");
  my_putstr(word_disp);
  my_putstr("\nTries: ");
  my_putnbr(try);
  my_putstr("\n");
  if (try <= 0)
    {
      my_putstr_fd(2, NO_TRY_LEFT);
      return (1);
    }
  idx = 0;
  while (word[idx])
    {
      if (word[idx] != CHAR_HIDDEN)
	return (-1);
      ++idx;
    }
  my_putstr(MSG_WIN);
  return (0);
}

int		run_game(char *word, char *word_disp, int try)
{
  int		done;
  int		found;
  int		ret;
  char		*input;

  input = NULL;
  done = 0;
  while (!done)
    {
      if ((ret = is_done(word, word_disp, try, input)) != -1)
	return (ret);
      my_putstr("Your letter: ");
      if (!(input = get_next_line(0)))
	return (0);
      if (!chk_input(input))
	{
	  if (!(found = find_letter(word, word_disp, input[0])))
	    {
	      my_putchar_fd(2, input[0]);
	      my_putstr_fd(2, LETTER_NOT_FOUND);
	      --try;
	    }
	}
    }
  return (0);
}
