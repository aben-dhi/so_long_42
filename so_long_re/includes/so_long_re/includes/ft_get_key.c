/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:53:07 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 18:09:03 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_key(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
	{
		ft_exit_game(game, EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
	else if (key == KEY_W || key == KEY_UP)
		ft_handle_movements(game, KEY_UP);
	else if (key == KEY_S || key == KEY_DOWN)
		ft_handle_movements(game, KEY_DOWN);
	else if (key == KEY_A || key == KEY_LEFT)
		ft_handle_movements(game, KEY_LEFT);
	else if (key == KEY_D || key == KEY_RIGHT)
		ft_handle_movements(game, KEY_RIGHT);
	return (0);
}
