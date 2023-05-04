/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:07:42 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:43:03 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_game(t_game *game,t_status status)
{
	if (game->map_alloc)
		ft_free_map(game->map, game->map_height);
	if (game->collectible)
		mlx_destroy_image(game->mlx_ptr, game->collectible->img);
	if (game->player_up)
		mlx_destroy_image(game->mlx_ptr, game->player_up->img);
	if (game->player_down)
		mlx_destroy_image(game->mlx_ptr, game->player_down->img);
	if (game->player_left)
		mlx_destroy_image(game->mlx_ptr, game->player_left->img);
	if (game->player_right)
		mlx_destroy_image(game->mlx_ptr, game->player_right->img);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall->img);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor->img);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx_ptr, game->exit_closed->img);
	if (game->exit_open)
		mlx_destroy_image(game->mlx_ptr, game->exit_open->img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(status);
}