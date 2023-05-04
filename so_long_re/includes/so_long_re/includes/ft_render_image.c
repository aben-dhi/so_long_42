/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:34:19 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:35:07 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_image(t_game *game, t_image *img, int x, int y)
{
	if (img != NULL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img, x, y);
}
