/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/05 21:49:54 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_matrix(int fd, t_game *game)
{
	int	i;
	char	*short_s;
	char	*long_s;

	short_s = get_next_line(fd);
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
	free (long_s);
	i = valid_frame(game);
	printf("%d", i);
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
	return (0);
}
