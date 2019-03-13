/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:58:59 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/13 22:09:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 400
# define DH(x) (x == '#' || x == '.')
# define H(x) (x == '#')
# define NL(x) (x == '\n')
# define DOT(x) (x == '.')
# define ALLCH(x) (x == '#' || x == '.' || x == '\n')

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum		e_bool
{
	false,
	true
}					t_bool;

/*
** size_t functions
*/

size_t		ft_calc_sqrt(size_t bytes);
int			solve(char **tetri, size_t bytes);
int			check_tetri(char *str, int i, int x);

/*
** char functions
*/

char		**ft_generate_map(size_t map_size);
char		**ft_fill_arr(char **arr, size_t dimensions);
char		*ft_read(int fd, char *str);
char		**ft_split_clean(char *str, int bytes);
char		**ft_generate_map(size_t bytes);
char		get_letter(char *str);

/*
** void functions
*/

void		ft_free_arr(char **arr);
void		error(void);
void		letter_change(char **tetri);
void		ft_trim_nline(char **src);

/*
** t_bool functions
*/

t_bool		check(char *str, size_t bytes);
t_bool		ft_valid(char **src, size_t bytes);

#endif
