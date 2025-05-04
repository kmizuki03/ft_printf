/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:17:17 by kato              #+#    #+#             */
/*   Updated: 2025/05/04 18:41:05 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		len++;
	}
	ft_putchar((n % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		len++;
	}
	ft_putchar((n % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	char	*base;
	int		len;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, format);
		len++;
	}
	ft_putchar(base[n % 16]);
	len++;
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("0x0"));
	len++;
	ft_putstr("0x");
	if (ptr >= 16)
	{
		ft_putnbr_hex(ptr / 16, 'x');
		len++;
	}
	ft_putchar("0123456789abcdef"[ptr % 16]);
	len++;
	return (len);
}
