/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:37:52 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:39:41 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_movements(t_game *game)
{
	char	*moves_str;
	char	*moves_val_str;
	char	*moves_val;

	moves_str = "Movements: ";
	moves_val = ft_itoa(game->movements);
	if (!moves_val)
		return ;
	moves_val_str = ft_strjoin(moves_str, moves_val);
	if (!moves_val_str)
	{
		free(moves_val);
		return ;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 20, 0xFFFFFF, moves_val_str);
	free(moves_val);
	free(moves_val_str);
}
