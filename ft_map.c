/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:55:11 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/11 17:47:55 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	fills the 2d array with '.'
*/

char			**ft_fill_arr(char **arr, size_t dimensions)
{
	size_t		i;
	size_t		j;

	j = 0;
	while (j < dimensions)
	{
		i = 0;
		while (i < dimensions)
		{
			arr[j][i] = '.';
			i++;
		}
		j++;
	}
	return (arr);
}

/*
**	calculates dimensions for 2d array by calculating square root
*/

size_t			ft_calc_sqrt(size_t bytes)
{
	size_t min_root;
	size_t amount_tetri;
	size_t blocks;

	min_root = 2;
	amount_tetri = (bytes + 1) / 21;
	blocks = amount_tetri * 4;
	if (amount_tetri < 1 || amount_tetri > 26)
		error();
	while (min_root < blocks)
	{
		if (min_root * min_root == blocks)
			return (min_root);
		if (min_root * min_root > blocks)
			return (min_root);
		min_root++;
	}
	return (0);
}

/*
**	Generates new 2d array
*/

char			**ft_generate_map(size_t map_size)
{
	char		**arr;

	arr = ft_malloc_arr(map_size, map_size);
	arr = ft_fill_arr(arr, map_size);
	return (arr);
}

void			letter_change(char **tetri)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 'A';
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (!DOT(tetri[i][j]))
				tetri[i][j] = c;
			j++;
		}
		c++;
		i++;
	}
}

char			get_letter(char *str)
{
	while (DOT(*str))
		str++;
	return (*str);
}
