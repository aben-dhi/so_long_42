/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:57:45 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/06 20:05:33 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] == 'r' && filename[i - 1] == 'e' && filename[i - 2] == 'b'
		&& filename[i - 3] == '.')
		return (1);
	return (0);

}
