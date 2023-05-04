/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:23:39 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/27 05:30:40 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_cell(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (y > 0 && game->map[y - 1][x] == '1')
		ft_exit_error(game, "Invalid map file: wall is not surrounded");
	if (y < game->map_height - 1 && game->map[y + 1][x] == '1')
		ft_exit_error(game, "Invalid map file: wall is not surrounded");
	if (x > 0 && game->map[y][x - 1] == '1')
		ft_exit_error(game, "Invalid map file: wall is not surrounded");
	if (x < game->map_width - 1 && game->map[y][x + 1] == '1')
		ft_exit_error(game, "Invalid map file: wall is not surrounded");
}

void	ft_check_columns(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				game->player_found = true;
			if (game->map[y][x] == 'C')
				game->collectible++;
			if (game->map[y][x] == 'E')
				game->exit_found = true;
			ft_check_cell(game, x, y);
			x++;
		}
		y++;
	}
	if (!game->player_found || !game->exit_found || game->collectible == 0)
		ft_exit_error(game, "Invalid map file: missing player, exit or collectible");
}
