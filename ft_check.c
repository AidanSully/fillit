/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 15:05:00 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/10 13:50:15 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function checks if there are only 4 # and 12 .
** making it a possible valid tetrimino
*/

static t_bool		check01(char *str, size_t bytes)
{
	size_t		i;
	size_t		n;
	size_t		counthash;
	size_t		countdot;

	n = 0;
	while (n < bytes)
	{
		i = 0;
		counthash = 0;
		countdot = 0;
		while (i < 19)
		{
			if (str[n + i] == '#')
				counthash++;
			if (str[n + i] == '.')
				countdot++;
			i++;
		}
		if (counthash != 4 || countdot != 12)
			return (false);
		n += 21;
	}
	return (true);
}

/*
** This function checks if the rows are actually 4 long
** and checks if it ends with newline
*/

static t_bool		check02(char *str, size_t bytes)
{
	size_t		i;
	size_t		j;
	size_t		n;

	n = 0;
	while (n < bytes)
	{
		i = 0;
		while (i < 16)
		{
			j = n + i;
			if (j != bytes - 4)
				if (!DH(str[j]) || !DH(str[j + 1])
				|| !DH(str[j + 2]) || !DH(str[j + 3])
				|| !NL(str[j + 4]))
					return (false);
			i += 5;
		}
		n += 21;
	}
	return (true);
}

/*
** one function to call both checks
*/

t_bool				check(char *str, size_t bytes)
{
	int		i;

	i = 0;
	if (!DH(str[0]))
		return (false);
	if (!NL(str[bytes - 1]) || !DH(str[bytes - 2]))
		return (false);
	if (check01(str, bytes) == false)
		return (false);
	if (check02(str, bytes) == false)
		return (false);
	while (str[i])
	{
		if (!ALLCH(str[i]))
			return (false);
		i++;
	}
	return (true);
}
