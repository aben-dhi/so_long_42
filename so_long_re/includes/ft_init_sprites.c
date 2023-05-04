/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:20:52 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 16:59:07 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_sprites(t_game *game)
{
	game->collectible = ft_new_sprite(game->mlx_ptr, game->collectible_path);
	if (!game->collectible)
		return (0);
	game->player_up = ft_new_sprite(game->mlx_ptr, game->player_up_path);
	if (!game->player_up)
		return (0);
	game->player_down = ft_new_sprite(game->mlx_ptr, game->player_down_path);
	if (!game->player_down)
		return (0);
	game->player_left = ft_new_sprite(game->mlx_ptr, game->player_left_path);
	if (!game->player_left)
		return (0);
	game->player_right = ft_new_sprite(game->mlx_ptr, game->player_right_path);
	if (!game->player_right)
		return (0);
	game->wall = ft_new_sprite(game->mlx_ptr, game->wall_path);
	if (!game->wall)
		return (0);
	game->floor = ft_new_sprite(game->mlx_ptr, game->floor_path);
	if (!game->floor)
		return (0);
	game->exit_closed = ft_new_sprite(game->mlx_ptr, game->exit_closed_path);
	if (!game->exit_closed)
		return (0);
	game->exit_open = ft_new_sprite(game->mlx_ptr, game->exit_open_path);
	if (!game->exit_open)
		return (0);
	return (1);
}

