/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:43:21 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/04 17:24:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int fd, char *str)
{
	int		z;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	z = 1;
	while (z)
	{
		z = read(fd, buf, BUFF_SIZE);
		buf[z] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
	}
	return (str);
}
