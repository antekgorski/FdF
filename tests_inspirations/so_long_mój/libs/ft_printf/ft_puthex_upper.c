/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:39:05 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/22 13:39:06 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_upper(unsigned long long n)
{
	char	digit;
	int		count;

	count = 1;
	if (n >= 16)
	{
		count += ft_puthex_upper(n / 16);
		ft_puthex_upper(n % 16);
	}
	else
	{
		if (n < 10)
			digit = n + '0';
		else
			digit = (n - 10) + 'A';
		write(1, &digit, 1);
	}
	return (count);
}
