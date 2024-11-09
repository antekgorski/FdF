/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:58:57 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/19 17:58:58 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_aux(int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		count++;
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		count += 2;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		count++;
	}
	count += ft_putnbr_aux(n);
	return (count);
}
