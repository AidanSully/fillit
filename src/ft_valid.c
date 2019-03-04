/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:41:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/10 15:58:42 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool		ft_strsearch(char *src, char *needle)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = 0;
	while (needle[len] != '\0')
		len++;
	while (src[i])
	{
		while (needle[j] == src[i + j])
		{
			if (j == len - 1)
				return (true);
			j++;
		}
		j = 0;
		i++;
	}
	return (false);
}

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
	ft_strcpy(valid[18], "####............");
	ft_strcpy(valid[19], "....####........");
	ft_strcpy(valid[20], "........####....");
	ft_strcpy(valid[21], "............####");
}

t_bool				ft_fill_deze_shit(char *src, char **valid)
{
	int		i;

	i = 0;
	while (i < 22)
	{
		if (ft_strsearch(src, valid[i]) == true)
		{
			ft_strclr(src);
			if (i < 18)
				ft_strcpy(src, valid[i]);
			if (i > 17)
				ft_strcpy(src, "####");
			return (true);
		}
		i++;
	}
	return (false);
}

t_bool				ft_valid(char **src, size_t bytes)
{
	size_t	i;
	size_t	blocks;
	t_bool	flag;
	char	**valid;

	i = 0;
	valid = ft_malloc_arr(22, 16);
	ft_fill(valid);
	blocks = (bytes + 1) / 21;
	while (i < blocks)
	{
		flag = ft_fill_deze_shit(src[i], valid);
		if (flag == false)
			return (false);
		i++;
	}
	ft_free_arr(valid);
	return (true);
}
