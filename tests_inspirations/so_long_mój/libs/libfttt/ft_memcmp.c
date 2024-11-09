/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:33 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:51:21 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)str1)[i] > ((unsigned char *)str2)[i])
			return (1);
		else if (((unsigned char *)str1)[i] < ((unsigned char *)str2)[i])
			return (-1);
		else
			i++;
	}
	return (0);
}
