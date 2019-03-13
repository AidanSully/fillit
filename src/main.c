/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:43:00 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/13 22:16:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(void)
{
	ft_putstr("error\n");
	exit(1);
}

static void		ft_check_call(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit source_file\n");
		exit(1);
	}
	return ;
}

int				main(int argc, char **argv)
{
	int		fd;
	size_t	bytes;
	char	*str;
	char	**input;

	str = ft_strnew(0);
	if (argc != 2)
		ft_check_call(argc);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error();
	str = ft_read(fd, str);
	close(fd);
	bytes = ft_strlen(str);
	if (check(str, bytes) == false)
		error();
	input = ft_split_clean(str, bytes);
	free(str);
	if (ft_valid(input, bytes) == false)
		error();
	letter_change(input);
	solve(input, bytes);
	ft_free_arr(input);
	return (0);
}
