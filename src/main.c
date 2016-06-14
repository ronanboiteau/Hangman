/*
** main.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 18:52:15 2016 Ronan Boiteau
** Last update Tue Jun 14 19:08:31 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "tools.h"

int		chk_args(int argc, char **argv)
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
      my_putstr_fd(2, "Too many arguments!\n");
      return (1);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  if (chk_args(argc, argv))
    return (EXIT_FAILURE);
  /* if (get_file(argv[1])) */
  /*   return (EXIT_FAILURE); */
  return (EXIT_SUCCESS);
}
