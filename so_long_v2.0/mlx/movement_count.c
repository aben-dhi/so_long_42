/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:41:27 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 14:42:58 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mv_count(t_game *game)
{
	int		i;
	char	*mv;

	game->moves++;
	mv = ft_itoa(game->moves);
	i = 0;
	write (1, "move count: ", 12);
	while (mv[i])
	{
		write(1, &mv[i], 1);
		i++;
	}
	write (1, "\n", 1);
	free(mv);
}