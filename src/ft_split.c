/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 14:53:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/13 22:11:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
**	Calls all the functions for setting a delimiter, splitting on the delimiter
**	and trims the newlines.
*/

char			**ft_split_clean(char *str, int bytes)
{
	char **arr;

	ft_set_delim(str, bytes);
	arr = ft_strsplit(str, '/');
	return (arr);
}
