/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solve.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 12:53:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/02/11 18:30:50 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Removes tetri
*/

void		remove_tetri(char **map, char *tetri, int row, int col)
{
	int		temp;
	char	ch;

	temp = col;
	ch = get_letter(tetri);
	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] == ch)
				map[row][col] = '.';
			col++;
		}
		row++;
		col = 0;
	}
}

/*
**	Puts a tetri in the map char by char
*/

void		put_tetri(char **map, char *tetri, int row, int col)
{
	int		i;
	int		temp;

	i = 0;
	temp = col;
	while (tetri[i])
	{
		if (DOT(map[row][col]) && !DOT(tetri[i]))
			map[row][col] = tetri[i];
		col++;
		i++;
		if (i % 4 == 0)
		{
			row++;
			col = temp;
		}
	}
}

/*
**	Check if it's safe to put tetri in map
*/

t_bool		safety(char **map, char *tetri, int row, int col)
{
	int		counter;
	int		temp;
	int		i;

	counter = 0;
	i = 0;
	temp = col;
	if (!map)
		return (false);
	while (tetri[i] && map[row])
	{
		if (DOT(map[row][col]) && !DOT(tetri[i]) && map[row][col])
			counter++;
		col++;
		i++;
		if (i % 4 == 0)
		{
			row++;
			col = temp;
		}
		if (counter == 4)
			return (true);
	}
	return (false);
}

/*
**	recursive backtracking
*/

int			solve_recur(char **map, char **tetri)
{
	int row;
	int col;

	row = 0;
	col = 0;
	if (!*tetri)
		return (1);
	while (map[row])
	{
		if (safety(map, *tetri, row, col) == true)
		{
			put_tetri(map, *tetri, row, col);
			if (solve_recur(map, tetri + 1) == 1)
				return (1);
			else
				remove_tetri(map, *tetri, row, col);
		}
		col++;
		if (map[row][col] == '\0')
		{
			col = 0;
			row++;
		}
	}
	return (0);
}

int			solve(char **tetri, size_t bytes)
{
	size_t		map_size;
	char		**map;
	t_bool		check;

	map_size = ft_calc_sqrt(bytes);
	map = ft_generate_map(map_size);
	check = false;
	while (solve_recur(map, tetri) == 0)
	{
		map_size++;
		map = ft_generate_map(map_size);
	}
	ft_print_matrix(map);
	ft_free_arr(map);
	return (0);
}
