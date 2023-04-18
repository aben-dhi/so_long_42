/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:20:01 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 14:34:31 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_annexe(const char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (spec == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_putbase(va_arg(args, int));
	else if (spec == 'u')
		count += ft_putbase_u(va_arg(args, unsigned int));
	else if (spec == 'x')
		count += ft_puthexa_l(va_arg(args, unsigned int));
	else if (spec == 'X')
		count += ft_puthexa_u(va_arg(args, unsigned int));
	else if (spec == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			i;
	int			wd_count;

	va_start(args, fmt);
	i = 0;
	wd_count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			wd_count += ft_annexe(fmt[++i], args);
		else
		{
			wd_count += ft_putchar(fmt[i]);
		}
		i++;
	}
	va_end(args);
	return (wd_count);
}
