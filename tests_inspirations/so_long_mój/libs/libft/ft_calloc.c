/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:03 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:50:51 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*buffer;

	if (items > sizeof(size_t) && size > sizeof(size_t))
		return (0);
	buffer = malloc(items * size);
	if (!buffer)
		return (0);
	else
		ft_bzero(buffer, items * size);
	return (buffer);
}
