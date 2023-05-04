/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_collectibles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:26:26 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:26:57 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_collectibles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->collectible->img, y * TILE_SIZE,
					x * TILE_SIZE);
			y++;
		}
		x++;
	}
}