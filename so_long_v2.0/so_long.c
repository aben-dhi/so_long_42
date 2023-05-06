/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/06 20:09:19 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_matrix(int fd, t_game *game)
{
	char	*short_s;
	char	*long_s;

	short_s = get_next_line(fd);
	game->columns = ft_strlen(short_s);
	if (!short_s)
		exit (1);
	long_s = malloc(1 * sizeof(char));
	if (!long_s)
		exit (1);
	long_s = 0;
	while (short_s != NULL)
	{
		long_s = ft_strjoin(long_s, short_s);
		free (short_s);
		short_s = get_next_line(fd);
	}
	free (short_s);
	game->map = ft_split(long_s, '\n');
	game->tmp = ft_split(long_s, '\n');
	free (long_s);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	get_matrix(fd, &game);
	comp_check(&game);
	p_check(&game);
	e_check(&game);
	c_check1(&game);
	valid_frame(&game);
	find_path(&game, 1, 1);
	path_check(&game);
	init_game(&game);
	put_img(&game);
	return (0);
}
