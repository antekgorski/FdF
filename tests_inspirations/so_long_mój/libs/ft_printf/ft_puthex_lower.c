/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:32:02 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/22 13:32:04 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_lower(unsigned long long n)
{
	char	digit;
	int		count;

	count = 1;
	if (n >= 16)
	{
		count += ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
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
