/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:46:32 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:10:00 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_arguments(argc, argv, &game);
	ft_init_map(&game, argv[1]);
	ft_init_vars(&game);
	ft_check_map(&game);
	ft_verify_map(&game);
	ft_init_mlx(&game);
	ft_init_sprites(&game);
	ft_render_map(&game);

	while (game.status == IN_PROGRESS)
	{
		ft_handle_movements(&game, ft_get_input(&game));
		ft_check_for_collectible(&game);
		ft_check_for_exit(&game);
		ft_render_movements(&game);
	}

	ft_render_game_over(&game, game.status);
	ft_exit_game(&game, game.status);
	return (0);
}
