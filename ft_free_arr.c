/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_arr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 13:21:44 by nvreeke        #+#    #+#                */
/*   Updated: 2019/02/10 15:47:06 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_arr(char **arr)
{
	int		j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}
