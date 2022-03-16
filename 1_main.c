/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/16 21:40:40 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_open_file(int fd, t_tetri **pieces, t_solution *solution)
{
	char	buf[547];
	int		ret;

	ret = read(fd, buf, 546);
	if (ret <= 0 || (ret + 1) % 21 != 0)
		ft_error("error", pieces, solution);
	buf[ret] = '\n';
	buf[ret + 1] = '\0';
	ft_validate_tetri(buf, pieces, solution);
}

int	main(int argc, char **argv)
{
	t_tetri		*pieces[27];
	t_solution	*solution;
	int			fd;

	ft_bzero(pieces, sizeof(t_tetri *) * 27);
	solution = (t_solution *)malloc(sizeof(t_solution));
	if (!solution)
		ft_error("error", pieces, solution);
	if (argc != 2)
		ft_error("usage: ./fillit input_file", pieces, solution);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("error", pieces, solution);
	ft_open_file(fd, pieces, solution);
	close(fd);
	ft_get_min_grid_size(solution);
	ft_translate_pieces(pieces, solution);
	ft_solve(pieces, solution);
	return (0);
}
