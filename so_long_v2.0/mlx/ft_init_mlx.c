/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:47:00 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 15:48:50 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	put_img(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->rows)
	{
		i = 0;
		while (i < (game->columns - 1))
		{
			floor_img(game, i, j);
			if (game->map[j][i] == '1')
				wall_img(game, i, j);
			if (game->map[j][i] == 'C')
				collectible_img(game, i, j);
			if (game->map[j][i] == 'P')
				player_img(game, i, j);
			if (game->map[j][i] == 'E')
				exit_img(game, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

void	init_game(t_game *game)
{
	game->image.len = (game->columns - 1) * 32;
	game->image.wid = game->rows * 32;
	game->moves = 0;
	game->image.mlx = mlx_init();
	game->image.mlx_win = mlx_new_window(game->image.mlx, game->image.len,
			game->image.wid, "so_long");
	put_img(game);
	mlx_hook(game->image.mlx_win, 2, 0, handle_key_press, game);
	mlx_hook(game->image.mlx_win, 17, 0, exit_game, game);
	mlx_loop(game->image.mlx);
}
