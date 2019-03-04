/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_matrix.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 17:14:29 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/04 17:24:12 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i] != '\0')
		{
			ft_putchar(arr[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
