/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:32:43 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:51:49 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = (ft_strlen((char *)s1) - 1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] && ft_strrchr(set, s1[j]))
		j--;
	str = ft_substr(s1, i, ((j - i) + 1));
	return (str);
}
