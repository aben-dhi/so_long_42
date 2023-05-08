/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:00:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 20:40:37 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	full_check(t_game *game, char *filename, int fd)
{
	if (has_extension(filename, ".ber") == 1)
		exit (1);
	get_matrix(fd, game);
	if (comp_check(game) == 1)
	{
		write (2, "Error\ninvalid map\n", 19);
		exit (1);
	}
	p_check(game);
	e_check(game);
	c_check1(game);
	if (check_walls(game) == 0 && check_frame(game) == 0)
	{
		player_pos(game);
		exit_pos(game);
		find_path(game, game->p_x, game->p_y);
		path_check(game);
	}
	else
	{
		write (2, "Error\n", 7);
		exit (1);
	}
}
