/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:36:30 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 12:49:39 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_alpha(int nb)
{
	if (nb == 10)
		ft_putchar('a');
	if (nb == 11)
		ft_putchar('b');
	if (nb == 12)
		ft_putchar('c');
	if (nb == 13)
		ft_putchar('d');
	if (nb == 14)
		ft_putchar('e');
	if (nb == 15)
		ft_putchar('f');
	return (1);
}

static int	ft_puthexa_low(unsigned long long val)
{
	int	count;

	count = 0;
	if (val >= 16)
	{
		count += ft_puthexa_low(val / 16);
		count += ft_puthexa_low(val % 16);
	}
	if (val >= 0 && val <= 9)
		count += ft_putbase_u(val);
	if (val >= 10 && val <= 15)
		count += ft_alpha(val);
	return (count);
}

int	ft_putptr(void *arg)
{
	int	count;

	count = 2;
	ft_putchar('0');
	ft_putchar('x');
	count += ft_puthexa_low((unsigned long long)arg);
	return (count);
}
