/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:56:31 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:27:37 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_load_image(void *mlx_ptr, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
	{
		perror("Error\nFailed to allocate memory for image.");
		return (NULL);
	}
	img->img = mlx_xpm_file_to_image(mlx_ptr, path, &img->width, &img->height);
	if (!img->img)
	{
		perror("Error\nFailed to load image file.");
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	return (img);
}


int	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (MY_EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		return (MY_EXIT_FAILURE);
	}
	return (MY_EXIT_SUCCESS);
}

