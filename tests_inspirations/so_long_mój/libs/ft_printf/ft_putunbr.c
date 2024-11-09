/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:48:13 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/22 13:48:14 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	digit;
	int		count;

	count = 1;
	if (n >= 10)
	{
		count += ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
	return (count);
}
