/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:49:38 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 13:54:35 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_data_game *game, char *path)
{
	int		fd;
	int		rec_check;
	char	*line;

	rec_check = 0;
	fd = open_map(path, game);
	line = get_next_line(fd);
	if (!line)
		end_game(game, "Not find map", 1);
	if (ft_strchr(line, '\n') != 0)
		line = split_line(line);
	game->map.map_width = ft_strlen(line);
	while (line)
	{
		if ((int)ft_strlen(line) != game->map.map_width)
			rec_check = 1;
		game->map.map_height++;
		free(line);
		line = get_next_line(fd);
		if (ft_strchr(line, '\n') != 0)
			line = split_line(line);
	}
	close(fd);
	if (rec_check == 1)
		end_game(game, "Map not rectangular", 1);
}

void	fill_map(t_data_game *game, char *path)
{
	int		fd;
	char	*line;
	int		i;

	if (game->map.map_height <= 3 || game->map.map_width <= 3)
		end_game(game, "Map too small", 1);
	fd = open_map(path, game);
	game->map.map = malloc(game->map.map_height * sizeof(char *));
	if (!game->map.map)
		end_game(game, "Malloc error", 1);
	i = 0;
	while (i < game->map.map_height)
	{
		line = get_next_line(fd);
		game->map.map[i] = malloc((game->map.map_width + 1) * sizeof(char));
		if (!game->map.map[i])
			end_game(game, "Malloc error", 1);
		ft_strlcpy(game->map.map[i], line, game->map.map_width + 1);
		free(line);
		i++;
	}
	close(fd);
}

void	validate_elements(t_data_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < game->map.map_width)
		{
			if (ft_strchr("01CEP", game->map.map[i][j]) == NULL)
				end_game(game, "Invalid element on the map", 1);
			j++;
		}
		i++;
	}
}

void	check_walls(t_data_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < game->map.map_width)
		{
			if (i == 0 || i == game->map.map_height)
			{
				if (game->map.map[i][j] != '1')
					end_game(game, "Invalid wall", 1);
			}
			if (j == 0 || j == game->map.map_width - 1)
			{
				if (game->map.map[i][j] != '1')
					end_game(game, "Invalid wall", 1);
			}
			j++;
		}
		i++;
	}
}

void	count_elements(t_data_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < game->map.map_width)
		{
			if (game->map.map[i][j] == 'C')
				game->total_collectibles++;
			if (game->map.map[i][j] == 'P')
				player++;
			if (game->map.map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (game->total_collectibles == 0 || player != 1 || exit != 1)
		end_game(game, "Wrong number of elements on the map", 1);
}
