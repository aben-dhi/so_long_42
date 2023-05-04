/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:28:45 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:06:54 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_exit_error(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	if (game)
		ft_free_game(game);
	exit(MY_EXIT_FAILURE);
}
