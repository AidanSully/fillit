/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:41:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/13 22:24:57 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_fill(char **valid)
{
	ft_strcpy(valid[0], "#...#...#...#");
	ft_strcpy(valid[1], ".#..###");
	ft_strcpy(valid[2], ".##.##");
	ft_strcpy(valid[3], "#...##...#");
	ft_strcpy(valid[4], "##...##");
	ft_strcpy(valid[5], ".#..##..#");
	ft_strcpy(valid[6], "#...##..#");
	ft_strcpy(valid[7], "###.#");
	ft_strcpy(valid[8], "##...#...#");
	ft_strcpy(valid[9], "..#.###");
	ft_strcpy(valid[10], "#...#...##");
	ft_strcpy(valid[11], ".#...#..##");
	ft_strcpy(valid[12], "#...###");
	ft_strcpy(valid[13], "##..#...#");
	ft_strcpy(valid[14], "###...#");
	ft_strcpy(valid[15], "###..#");
	ft_strcpy(valid[16], ".#..##...#");
	ft_strcpy(valid[17], "##..##");
	ft_strcpy(valid[18], "####");
}

int					init(char *str)
{
	int		i;
	int		x;
	int		flag;

	i = 0;
	x = -1;
	flag = check_tetri(str, i, x);
	return (flag);
}

int					check_tetri(char *s, int i, int x)
{
	while (s[i])
	{
		(H(s[i]) && H(s[i + 5]) && H(s[i + 10]) && H(s[i + 15])) ? x = 0 : 0;
		(H(s[i]) && H(s[i + 4]) && H(s[i + 5]) && H(s[i + 6])) ? x = 1 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 4]) && H(s[i + 5])) ? x = 2 : 0;
		(H(s[i]) && H(s[i + 5]) && H(s[i + 6]) && H(s[i + 11])) ? x = 3 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 6]) && H(s[i + 7])) ? x = 4 : 0;
		(H(s[i]) && H(s[i + 4]) && H(s[i + 5]) && H(s[i + 9])) ? x = 5 : 0;
		(H(s[i]) && H(s[i + 5]) && H(s[i + 6]) && H(s[i + 10])) ? x = 6 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 2]) && H(s[i + 5])) ? x = 7 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 6]) && H(s[i + 11])) ? x = 8 : 0;
		(H(s[i]) && H(s[i + 3]) && H(s[i + 4]) && H(s[i + 5])) ? x = 9 : 0;
		(H(s[i]) && H(s[i + 5]) && H(s[i + 10]) && H(s[i + 11])) ? x = 10 : 0;
		(H(s[i]) && H(s[i + 5]) && H(s[i + 9]) && H(s[i + 10])) ? x = 11 : 0;
		(H(s[i]) && H(s[i + 5]) && H(s[i + 6]) && H(s[i + 7])) ? x = 12 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 5]) && H(s[i + 10])) ? x = 13 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 2]) && H(s[i + 7])) ? x = 14 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 2]) && H(s[i + 6])) ? x = 15 : 0;
		(H(s[i]) && H(s[i + 4]) && H(s[i + 5]) && H(s[i + 10])) ? x = 16 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 5]) && H(s[i + 6])) ? x = 17 : 0;
		(H(s[i]) && H(s[i + 1]) && H(s[i + 2]) && H(s[i + 3])) ? x = 18 : 0;
		i++;
	}
	return (x);
}

t_bool				ft_valid(char **src, size_t bytes)
{
	size_t	i;
	size_t	blocks;
	int		flag;
	char	**valid;

	i = 0;
	valid = ft_malloc_arr(19, 14);
	ft_fill(valid);
	blocks = (bytes + 1) / 21;
	while (i < blocks)
	{
		flag = init(src[i]);
		if (flag == -1)
			return (false);
		else
		{
			ft_strclr(src[i]);
			ft_strcpy(src[i], valid[flag]);
		}
		i++;
	}
	ft_free_arr(valid);
	return (true);
}
