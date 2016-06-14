/*
** my_putnbr.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 20:55:13 2016 Ronan Boiteau
** Last update Tue Jun 14 20:58:36 2016 Ronan Boiteau
*/

#include <stdlib.h>
#include "tools.h"

void		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return ;
}
