/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:32:54 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:51:51 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc((sizeof(char) * len) + 1);
	if (!sub)
		return (0);
	while (i < len && s[start + i] != '\0' && start < ft_strlen((char *)s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
