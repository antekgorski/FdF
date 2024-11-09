/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:22:38 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:51:19 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	char			*find;

	find = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)find[i] == (unsigned char)c)
			return ((void *)&find[i]);
		i++;
	}
	return (0);
}
