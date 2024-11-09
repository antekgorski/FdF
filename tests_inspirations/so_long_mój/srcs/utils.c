/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:49:24 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 14:01:02 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *path, t_data_game *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game(game, "Map not found", 1);
	return (fd);
}

char	*split_line(char *line)
{
	char	*new_line;
	int		i;

	new_line = malloc(ft_strlen(line) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	display_moves_and_collectibles(t_data_game *game)
{
	char	*moves;
	char	*collectibles;

	moves = ft_itoa(game->moves_count);
	collectibles = ft_itoa(game->total_collectibles);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 10, 0x00FFFFFF, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 25, 0x00FFFFFF,
		"Collectibles: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 25, 0x00FFFFFF,
		collectibles);
	free(moves);
	free(collectibles);
}
