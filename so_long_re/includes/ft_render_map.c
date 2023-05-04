/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:41:46 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:41 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void	ft_render_map(t_game *game)
{
	int x;
	int y;
	int img_x;
	int img_y;

	y = 0;
	img_y = 0;
	while (y < game->map_height)
	{
		x = 0;
		img_x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				ft_render_image(game->wall, img_x, img_y, game);
			else if (game->map[y][x] == 'C')
				ft_render_image(game->collectible, img_x, img_y, game);
			else if (game->map[y][x] == 'E')
			{
				if (game->exit_found)
					ft_render_image(game->exit_open, img_x, img_y, game);
				else
					ft_render_image(game->exit_closed, img_x, img_y, game);
			}
			else if (game->map[y][x] == 'P')
			{
				ft_render_player(game);
			}
			else
				ft_render_image(game);
			x++;
			img_x += TILE_SIZE;
		}
		y++;
		img_y += TILE_SIZE;
	}
}

