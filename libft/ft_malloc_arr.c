/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_arr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:31:28 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/10 15:57:20 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_malloc_arr(int rows, int cols)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * rows + 1);
	arr[rows] = NULL;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols + 1);
		i++;
	}
	return (arr);
}
