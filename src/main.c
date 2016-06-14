/*
** main.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 18:52:15 2016 Ronan Boiteau
** Last update Tue Jun 14 20:19:39 2016 Ronan Boiteau
*/

#include <stdlib.h>
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

int		main(int argc, char **argv)
{
  char		*file_content;
  char		*word;

  word = malloc(4 * 8);
  word[0] = 't';
  word[1] = 'e';
  word[2] = 's';
  word[3] = 't';
  word[4] = '\0';
  if (chk_args(argc, argv))
    return (EXIT_FAILURE);
  if (!(file_content = get_file(argv[1])))
    {
      my_putstr_fd(2, ERR_DICTIONARY);
      return (EXIT_FAILURE);
    }
  run_game(word, NB_TRY);
  free(file_content);
  return (EXIT_SUCCESS);
}
