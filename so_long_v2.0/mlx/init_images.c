/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:17:31 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/06 19:42:48 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	floor_img(t_game *game, int i, int j)
{
	int		x;
	int		y;

	x = 60;
	y = 60;
	game->image.mlx_img = mlx_xpm_file_to_image(game->image.mlx, FLOOR, &x, &y);
	if (!game->image.mlx_img)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx_put_image_to_window(game->image.mlx, game->image.mlx_win,
		game->image.mlx_img, i * x, j * y);
	mlx_destroy_image(game->image.mlx, game->image.mlx_img);
}

void	wall_img(t_game *game, int i, int j)
{
	int		x;
	int		y;

	x = 60;
	y = 60;
	game->image.mlx_img = mlx_xpm_file_to_image(game->image.mlx, WALL, &x, &y);
	if (!game->image.mlx_img)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx_put_image_to_window(game->image.mlx, game->image.mlx_win,
		game->image.mlx_img, i * x, j * y);
	mlx_destroy_image(game->image.mlx, game->image.mlx_img);
}

void	collectible_img(t_game *game, int i, int j)
{
	int		x;
	int		y;

	x = 60;
	y = 60;
	game->image.mlx_img = mlx_xpm_file_to_image(game->image.mlx, COINS, &x, &y);
	if (!game->image.mlx_img)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx_put_image_to_window(game->image.mlx, game->image.mlx_win,
		game->image.mlx_img, i * x, j * y);
	mlx_destroy_image(game->image.mlx, game->image.mlx_img);
}

void	player_img(t_game *game, int i, int j)
{
	int		x;
	int		y;

	x = 60;
	y = 60;
	game->image.mlx_img = mlx_xpm_file_to_image(game->image.mlx, PLAYER,
			&x, &y);
	if (!game->image.mlx_img)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx_put_image_to_window(game->image.mlx, game->image.mlx_win,
		game->image.mlx_img, i * x, j * y);
	mlx_destroy_image(game->image.mlx, game->image.mlx_img);
}

void	exit_img(t_game *game, int i, int j)
{
	int		x;
	int		y;

	x = 60;
	y = 60;
	game->image.mlx_img = mlx_xpm_file_to_image(game->image.mlx, EXIT, &x, &y);
	if (!game->image.mlx_img)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	mlx_put_image_to_window(game->image.mlx, game->image.mlx_win,
		game->image.mlx_img, i * x, j * y);
	mlx_destroy_image(game->image.mlx, game->image.mlx_img);
}
