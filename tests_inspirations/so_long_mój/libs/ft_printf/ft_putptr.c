/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:41:59 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/22 13:42:00 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putptr_chars(unsigned long n)
{
	char	digit;
	int		count;

	count = 1;
	if (n >= 16)
	{
		count += ft_putptr_chars(n / 16);
		ft_putptr_chars(n % 16);
	}
	else
	{
		if (n < 10)
			digit = n + '0';
		else
			digit = (n - 10) + 'a';
		write(1, &digit, 1);
	}
	return (count);
}

int	ft_putptr(unsigned long n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putptr_chars(n));
}
