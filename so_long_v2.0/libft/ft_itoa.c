/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:14:19 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 13:23:03 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	length(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*convert(long nb, char *str)
{
	int		i;
	int		j;

	i = length(nb);
	j = i;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i - 1] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;
	int		j;

	nb = n;
	i = length(nb);
	j = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
	}
	str = convert(nb, str);
	return (str);
}
