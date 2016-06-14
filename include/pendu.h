/*
** pendu.h for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:41:56 2016 Ronan Boiteau
** Last update Tue Jun 14 20:16:57 2016 Ronan Boiteau
*/

#ifndef PENDU_H_
# define PENDU_H_

# define NB_TRY (10)
# define CHAR_FOUND '*'

char	*get_file(const char *filepath);
void	run_game(char *word, int try);

#endif /* !PENDU_H_ */
