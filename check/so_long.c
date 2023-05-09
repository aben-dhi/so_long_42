/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/09 14:02:53 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nl(char	*str)
{
	if (str[0] == '\n')
	{
		write(2, "Error\nNewline(s)\n", 18);
		exit (1);
	}	
}

void	get_matrix(int fd, t_game *game)
{
	char	*short_s;
	char	*long_s;

	short_s = get_next_line(fd);
	game->columns = ft_strlen(short_s) - 1;
	if (!short_s)
		exit (1);
	long_s = malloc(1 * sizeof(char));
	if (!long_s)
		exit (1);
	while (short_s != NULL)
	{
		long_s = ft_strjoin(long_s, short_s);
		nl(short_s);
		free (short_s);
		short_s = get_next_line(fd);
	}
	free(short_s);
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
		write (2, "Error\nmap not found\n", 21);
		return (1);
	}
	full_check(&game, av[1], fd);
	close (fd);
	init_game(&game);
	return (0);
}
