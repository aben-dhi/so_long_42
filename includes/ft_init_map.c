/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:39:32 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:19:57 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		ret;
	char	*s;
 

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(errno);
	}
	while (s == get_next_line(fd))
	{
		ft_check_line(line, game);
		free(line);
	}
	ft_check_line(line, game);
	free(line);
	close(fd);
	if (ret < 0)
	{
		perror("Error");
		exit(errno);
	}
}
