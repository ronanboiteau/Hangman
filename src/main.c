/*
** main.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 18:52:15 2016 Ronan Boiteau
** Last update Tue Jun 14 21:48:15 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include <time.h>
#include "msg.h"
#include "pendu.h"
#include "tools.h"

static int	chk_args(int argc, char **argv)
{
  if (argc < 2)
    {
      my_putstr_fd(2, "Usage: ");
      my_putstr_fd(2, argv[0]);
      my_putstr_fd(2, " dictionary\n");
      return (1);
    }
  if (argc > 2)
    {
      my_putstr_fd(2, TOO_MANY_ARGS);
      return (1);
    }
  return (0);
}

static char	*init_word_disp(int size)
{
  char		*word_disp;
  int		idx;

  if (!(word_disp = malloc(sizeof(char) * (size + 1))))
    return (NULL);
  idx = 0;
  while (idx < size)
    word_disp[idx++] = CHAR_HIDDEN;
  word_disp[idx] = '\0';
  return (word_disp);
}

static int	chk_file(const char *file)
{
  int		idx;

  idx = 0;
  while (file[idx])
    {
      if (file[idx] == CHAR_HIDDEN)
	{
	  my_putstr_fd(2, ERR_FORBID_CHAR);
	  return (1);
	}
      idx++;
    }
  return (0);
}

static int	free_and_leave(char *file_content,
			       char *word_disp,
			       char *word,
			       int ret)
{
  free(file_content);
  free(word_disp);
  free(word);
  return (ret);
}

int		main(int argc, char **argv)
{
  int		ret;
  char		*file_content;
  char		*word;
  char		*word_disp;

  srand(time(0));
  if (chk_args(argc, argv))
    return (1);
  if (!(file_content = get_file(argv[1])))
    {
      my_putstr_fd(2, ERR_DIC_EMPTY);
      return (1);
    }
  if (chk_file(file_content) || !(word = select_word(file_content)))
    return (1);
  if (!(word_disp = init_word_disp(my_strlen(word))))
    {
      my_putstr_fd(2, ERR_MALLOC);
      return (1);
    }
  ret = run_game(word, word_disp, NB_TRY);
  return (free_and_leave(file_content, word_disp, word, ret));
}
