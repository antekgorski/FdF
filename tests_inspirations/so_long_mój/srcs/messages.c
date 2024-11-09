/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:49:29 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 09:08:43 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_message(t_data_game *game, char *message, int code)
{
	if (message)
	{
		ft_printf("%s\n", message);
		exit(code);
	}
	ft_printf("You finished the game in %d moves!\n", game->moves_count);
	exit(code);
}

void	destroy_images(t_data_game *game)
{
	if (game->collectible_image.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible_image.texture_ptr);
	if (game->exit_image.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit_image.texture_ptr);
	if (game->wall_image.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall_image.texture_ptr);
	if (game->floor_image.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor_image.texture_ptr);
	if (game->player.player_r.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_r.texture_ptr);
	if (game->player.player_l.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_l.texture_ptr);
	if (game->player.player_u.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_u.texture_ptr);
	if (game->player.player_d.texture_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_d.texture_ptr);
}

int	end_game(t_data_game *game, char *message, int code)
{
	if (game->map.map)
	{
		while (game->map.map_height--)
			free(game->map.map[game->map.map_height]);
		free(game->map.map);
	}
	destroy_images(game);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_loop_end(game->mlx_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit_message(game, message, code);
	return (0);
}
