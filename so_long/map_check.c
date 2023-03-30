/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:28:52 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/03/26 18:45:24 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int has_extension(char *filename,  char *extension)
{
    char *dot ;
    
    dot = ft_strchr(filename, '.');
    if (dot && ft_strcmp(dot, extension) == 0) 
        return 1;
    else
        return 0;
}

char *map_to_string(int fd)
{
    char    *line;
    char    *res;
    int     i;

    line = get_next_line(fd);
    res = 0;
    if (!line)
        return (NULL);
    while (1)
    {
        res = ft_strjoin(line, get_next_line(fd));
        free (line);
        line = get_next_line(fd);
    }
}