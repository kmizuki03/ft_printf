/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:33:43 by kato              #+#    #+#             */
/*   Updated: 2025/05/04 18:23:30 by kato             ###   ########.fr       */
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
