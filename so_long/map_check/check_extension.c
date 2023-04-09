/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:59:57 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/08 00:19:44 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int has_extension(char *filename,  char *extension)
{
    char *dot ;
    
    dot = ft_strchr(filename, '.');
    if (dot && ft_strcmp(dot, extension) == 0) 
        return 1;
    else
        return 0;
}