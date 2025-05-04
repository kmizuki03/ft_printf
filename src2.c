/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:17:17 by kato              #+#    #+#             */
/*   Updated: 2025/05/04 19:05:00 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		return (1 + ft_putnbr(-n));
	}
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		return (ft_putnbr_unsigned(n / 10) + ft_putchar((n % 10) + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	char	*base;

	base = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (n >= 16)
		return (ft_putnbr_hex(n / 16, format) + ft_putchar(base[n % 16]));
	return (ft_putchar(base[n % 16]));
}

int	ft_putptr(unsigned long ptr)
{
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_hex(ptr, 'x'));
}
