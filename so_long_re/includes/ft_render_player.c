/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:00:19 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:32:34 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_player(t_game *game)
{
	int		x;
	int		y;
	t_image	*player_img;

	player_img = NULL;
	if (game->player.y >= 0 && game->player.y < game->map_height &&
		game->player.x >= 0 && game->player.x < game->map_width)
	{
		y = game->player.y * TILE_SIZE;
		x = game->player.x * TILE_SIZE;
		if (game->player_dir == UP)
			player_img = game->player_up;
		else if (game->player_dir == DOWN)
			player_img = game->player_down;
		else if (game->player_dir == LEFT)
			player_img = game->player_left;
		else if (game->player_dir == RIGHT)
			player_img = game->player_right;
		if (player_img != NULL)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, player_img->img, x, y);;
	}
}

