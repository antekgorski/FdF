/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:28:00 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:51:31 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(const char *str, char c)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 1;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (str[i] == '\0')
			break ;
		words++;
		i++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char			**arr;
	size_t			len;
	unsigned int	i;

	i = 0;
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c))
				len = ft_strchr(s, c) - s;
			else
				len = ft_strlen(s);
			arr[i++] = ft_substr(s, 0, len);
			s = s + len;
		}
	}
	arr[i] = 0;
	return (arr);
}
