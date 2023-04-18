/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:36:46 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 12:08:12 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr_u(unsigned int val)
{
	if (val > 9)
	{
		ft_putnbr_u(val / 10);
		ft_putnbr_u(val % 10);
	}
	else
		ft_putchar(val + '0');
}

int	ft_putbase_u(unsigned int arg)
{
	ft_putnbr_u(arg);
	return (length_u(arg));
}
