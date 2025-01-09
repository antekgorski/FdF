/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:44:09 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 17:54:01 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief 	close program
 * @brief destroy window and display also free pointer(mlx_win)
 * @brief free pointer(mlx_start) and exit program
 * @param data pointer to struct with mlx data
 * @return 0
 */
int	close_program(t_mlx *data)
{
	mlx_destroy_window(data->mlx_start, data->mlx_win);
	mlx_destroy_display(data->mlx_start);
	free(data->mlx_start);
	exit(0);
}

/**
 * @brief 	print error message and exit
 * @param s error message
 * @param status exit status
 */
void	ft_panic(char *s, int status)
{
	ft_putstr_fd(s, 2);
	exit(status);
}

/**
 * @brief 	open file
 * @param filename name of file
 * @return file descriptor
 */
int	ft_open(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open a file.\n");
		exit(1);
	}
	return (fd);
}

/**
 * @brief 	read file
 * @param av table of arguments(strings)
 * @param data game data
 */
void	ft_read_file(char **av, t_map *map)
{
	int	fd;

	fd = ft_open(av[1]);
	ft_read(fd, map);
	close(fd);
}

/**
 * @brief 	count number of elements in table
 * @param tab table of strings
 * @return number of lines in table
 */
int	ft_count_tab_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
