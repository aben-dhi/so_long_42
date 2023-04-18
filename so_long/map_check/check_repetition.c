/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repetition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:59:56 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/09 18:14:30 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_repetitions(char* str) 
{
    int count_p;
    int count_c;
    int count_e;
    int i;

    i = 0;
    count_p = 0;
    count_c = 0;
    count_e = 0;
    while (str[i])
    {
        if (str[i] == '1' || str[i] == '0' || str[i] == '\n')
            i++;
        if (str[i] == 'P')
            count_p++;
        if (str[i] == 'C')
            count_c++;
        if (str[i] == 'E')
            count_e++;
        i++;
    }
    if (count_c >= 1 && count_p == 1 && count_e == 1)
        return (0);
    else 
        return (1);  
}
