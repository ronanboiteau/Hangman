/*
** main.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 18:52:15 2016 Ronan Boiteau
** Last update Tue Jun 14 21:00:09 2016 Ronan Boiteau
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

/* static int	check_file(const char *file) */
/* { */
/*   int		idx; */

/*   idx = 0; */
/*   while (file[idx]) */
/*     { */
/*       if (file[idx] == CHAR_HIDDEN) */
/* 	return (1); */
/*       idx++; */
/*     } */
/*   return (0); */
/* } */

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

int		main(int argc, char **argv)
{
  char		*file_content;
  char		*word;
  char		*word_disp;

  srand(time(0));
  if (chk_args(argc, argv))
    return (EXIT_FAILURE);
  if (!(file_content = get_file(argv[1]))
      || !(word = select_word(file_content))
      || !(word_disp = init_word_disp(my_strlen(word))))
    {
      my_putstr_fd(2, ERR_DICTIONARY);
      return (EXIT_FAILURE);
    }
  free(file_content);
  run_game(word, word_disp, NB_TRY);
  free(word_disp);
  free(word);
  return (EXIT_SUCCESS);
}
