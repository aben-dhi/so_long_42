/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:43:44 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:49 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verify_map(t_game *game)
{
	if (!game->map_alloc || game->map_height == 0 || game->map_width == 0)
		ft_exit_error(game, "Invalid map file: empty or missing map");

	if (game->player.x < 0 || game->player.x >= game->map_width || game->player.y < 0 || game->player.y >= game->map_height)
		ft_exit_error(game, "Invalid map file: player not placed within map boundaries");

	if (game->collectible == 0 || game->collectible == NULL)
		ft_exit_error(game, "Invalid map file: missing collectible sprite");

	if (game->floor == NULL || game->wall == NULL || game->player_up == NULL ||
		game->player_down == NULL || game->player_left == NULL || game->player_right == NULL ||
		game->exit_closed == NULL || game->exit_open == NULL)
		ft_exit_error(game, "Invalid map file: missing sprite(s)");
}
