/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:54:15 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/19 17:54:17 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str != NULL)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			len++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		len = 6;
	}
	return (len);
}
