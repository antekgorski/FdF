/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:05:45 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 20:15:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		*sign = 1;
		str++;
	}
	return (*sign);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	ft_set_sign(str, &sign);
	if (base == 16 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		if (ft_isdigit(*str))
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	return (result * sign);
}
