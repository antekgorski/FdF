/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:55 by agorski           #+#    #+#             */
/*   Updated: 2025/01/10 11:07:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	temp = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (0);
	bytes = 1;
	while (bytes > 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			if (buffer)
				free(buffer);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer = gnl_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

static char	*load_to_line(char *buffer)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char) * (i + 1), sizeof(char));
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i + 1)
		str[i] = buffer[i];
	return (str);
}

char	*update_buffer(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	str = (char *)ft_calloc(sizeof(char) * (gnl_strlen(buffer) - i + 1), 1);
	if (!str)
		return (0);
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

/**
 * @attention <<MALLOC>>
 * @warning <<MALLOC>>
 * @brief Get the next line from a file descriptor.
 * @param fd The file descriptor.
 * @return The next line.
 * @return NULL if there is an error or file is empty or EOF.
 * @return NULL if the buffer size is invalid.
 */
char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer[fd] = read_to_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (0);
	line = load_to_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

//  #include <stdio.h>

// int	main(void)
// {
// 	char *str4 = 0;
// 	int fd = open("test.txt", O_RDONLY);
// 	for (int a = 0; a < 140; a++)
// 	{
// 		str4 = get_next_line(fd);
// 		if (str4 == NULL)
// 		{
// 			printf("	NULL	\n");
// 			break ;
// 		}
// 		printf("%s", str4);
// 		free(str4);
// 	}
// 	close(fd);
// }
