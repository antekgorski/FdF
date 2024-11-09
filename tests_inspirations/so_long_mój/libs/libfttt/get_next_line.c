/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:32:31 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 07:54:13 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	line[800];
	int		b;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	b = read(fd, &buffer, 1);
	while (b > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));
}
