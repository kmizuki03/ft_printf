/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:33:43 by kato              #+#    #+#             */
/*   Updated: 2025/05/04 15:27:30 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	if (str == NULL)
		str = "(null)";
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		len++;
		i++;
	}
	return (len);
}

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
