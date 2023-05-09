/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:57:45 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/09 13:50:16 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	has_extension(char *filename, char *extension)
{
	char	*dot ;

	dot = ft_strchr(filename, '.');
	if (dot && ft_strcmp(dot, extension) == 0)
		return (0);
	else
	{
		write(2, "Error\nExtension not .ber\n", 26);
		return (1);
	}
}
