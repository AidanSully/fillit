/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 14:53:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/10 15:59:11 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
**	Sets a delimiter '/' for string split
*/

static void		ft_set_delim(char *src, int bytes)
{
	int		i;

	i = 21;
	while (i < bytes)
	{
		src[i - 1] = '/';
		i += 21;
	}
	return ;
}

/*
**	Trims the newline character
*/

static void		ft_trim_nline(char **src)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 0;
	temp = ft_strnew(16);
	while (src[i])
	{
		j = 0;
		k = 0;
		while (src[i][j])
		{
			if (src[i][j] == '\n')
				j++;
			temp[k] = src[i][j];
			j++;
			k++;
		}
		ft_strcpy(src[i], temp);
		i++;
	}
	free(temp);
}

/*
**	Calls all the functions for setting a delimiter, splitting on the delimiter
**	and trims the newlines.
*/

char			**ft_split_clean(char *str, int bytes)
{
	char **arr;

	ft_set_delim(str, bytes);
	arr = ft_strsplit(str, '/');
	ft_trim_nline(arr);
	return (arr);
}
