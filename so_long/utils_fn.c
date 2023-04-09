/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:37:57 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/03/31 23:52:56 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_strrchr(char *s, int c)
// {
// 	char	*a;
// 	size_t	len;

// 	a = (char *)s;
// 	len = ft_strlen(s);
// 	if (c == '\0')
// 		return (a + len);
// 	while (len != 0)
// 	{
// 		if (a[len] == (char)c)
// 			return (a + len);
// 		len--;
// 	}
// 	if (a[0] == (char)c)
// 		return (a);
// 	return (0);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
