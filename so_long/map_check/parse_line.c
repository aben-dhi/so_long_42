/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:00:49 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/09 03:47:55 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *map_to_string(int fd)
{
    char    *line;
    char    *res;
    int     i;

    line = get_next_line(fd);
    if (!line)
        return (NULL);
    
    res = malloc(1 * sizeof(char));
    if (!res)
    {
        return (NULL);
    }
    free(res);
    res = 0;
    while (1)
    {
        res = ft_strjoin(res, line);
        free(line);
        line = get_next_line(fd);
        if (!line)
            break;
    }
    free(line);
    return(res);
}

int check_line(char *str)
{
    int i;
    int len;
    
    i = 0;
    // len = ft_strlen(str);
    while (str[i] == '1' || str[i] == '0' || str[i] == 'E' || 
    str[i] == 'P' || str[i] == 'C'|| str[i] == '\n')
        i++;
    if (ft_strlen(str) - i != 0)
        return(1);
    else
        return (0);
}

// int check_line(char *str)
// {
//     char *p = str;
//     while (*p) {
//         if (*p != '1' && *p != '0' && *p != 'E' &&
//             *p != 'P' && *p != 'C' && *p != '\n') {
//             return 1;
//         }
//         p++;
//     }
//     return 0;
// }


int main ()
{
    int fd;
    char *str; 
    
    fd = open("map.ber", O_RDONLY);
    str = map_to_string(fd);
    printf("%s\n", str);
    // str = map_to_string(fd);
    printf("%d\n", check_line(str));
    close(fd);
    printf("%zu\n", ft_strlen(str));
    return 0;
}