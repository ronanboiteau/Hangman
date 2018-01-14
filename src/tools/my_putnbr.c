#include <stdlib.h>
#include "tools.h"

void		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return ;
}
