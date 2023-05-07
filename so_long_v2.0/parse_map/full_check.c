/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:00:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 18:16:45 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	full_check(t_game *game, char *filename, int fd)
{
	if (has_extension(filename, ".ber") == 1)
		exit (1);
	get_matrix(fd, game);
	comp_check(game);
	p_check(game);
	e_check(game);
	c_check1(game);
	valid_frame(game);
	find_path(game, 1, 1);
	path_check(game);
}
