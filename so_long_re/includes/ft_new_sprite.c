/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:30:09 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 16:44:16 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_new_sprite(void *mlx_ptr, char *path)
{
	t_image	*sprite;

	sprite = (t_image *)malloc(sizeof(t_image));
	if (!sprite)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(mlx_ptr, path, \
	&sprite->width, &sprite->height);
	if (!sprite->img)
	{
		free(sprite);
		return (NULL);
	}
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp, \
	&sprite->line_len, &sprite->endian);
	return (sprite);
}
