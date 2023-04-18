/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:24:51 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/18 01:22:43 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// #include "parse_line.c"

int count_lines(char *str)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while(str[i])
    {
        if (str[i] == '\n')
            j++;
        i++;    
    }
    return (j);
}

int first_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n')
        i++;
    return(i);       
}

int check_shape(char *str)
{
    int i;
    int j;
    int c;
    int len;
    
    i = 0;
    j = 0;
    c = 1;
    len = first_len(str);
    while (str[j] != '\n' && c <= count_lines(str))
    {
        j++;
        i++;
        if (i == len)
        {
            j++;
            c++;
            i = 0;
        }
        else 
            break;
    }
    if (c == count_lines(str))
        return(1);
    else
        return(0);

}


//   int main ()
// {
//     int fd;
//     char *str; 
    
//     fd = open("map.ber", O_RDONLY);
//     str = map_to_string(fd);
//     printf("%s\n", str);
//     // str = map_to_string(fd);
//     // printf("%d\n", check_line(str));
//     close(fd);
//     printf("%zu\n", ft_strlen(str));
//     // printf("%d\n", check_repetitions(str));
//     printf("%d\n", count_lines(str));
//     printf("%d\n", check_shape(str));
//     return 0;
// }
