/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:27 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 14:06:23 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_close(void *param)
{
	t_data_game	*game;

	game = (t_data_game *)param;
	end_game(game, "Exit game", 0);
	return (0);
}

static int	key_hook(int keycode, t_data_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		end_game(game, "Exit game!", 0);
	else if (keycode == KEY_W || keycode == KEY_AR_U)
	{
		move_player_up(game);
	}
	else if (keycode == KEY_S || keycode == KEY_AR_D)
	{
		move_player_down(game);
	}
	else if (keycode == KEY_A || keycode == KEY_AR_L)
	{
		move_player_left(game);
	}
	else if (keycode == KEY_D || keycode == KEY_AR_R)
	{
		move_player_right(game);
	}
	return (0);
}

static void	init_game(t_data_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->total_collectibles = 0;
	game->moves_count = 0;
	game->map.map = NULL;
	game->map.map_width = 0;
	game->map.map_height = 0;
	game->map.player_x_position = 0;
	game->map.player_y_position = 0;
	game->map.exit_x = 0;
	game->map.exit_y = 0;
	game->collectible_image.texture_ptr = NULL;
	game->exit_image.texture_ptr = NULL;
	game->wall_image.texture_ptr = NULL;
	game->floor_image.texture_ptr = NULL;
	game->player.direction = 'R';
	game->player.player_r.texture_ptr = NULL;
	game->player.player_l.texture_ptr = NULL;
	game->player.player_u.texture_ptr = NULL;
	game->player.player_d.texture_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_data_game	game;

	if (argc <= 1)
		return (1);
	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	init_sprites(&game);
	read_map(&game, argv[1]);
	fill_map(&game, argv[1]);
	validate_elements(&game);
	check_walls(&game);
	count_elements(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.map_width
			* SPRITE_SIZE, game.map.map_height * SPRITE_SIZE, "So Long");
	if (!game.win_ptr)
		return (1);
	init_positions(&game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, CLOSE_BTN, 0, handle_close, &game);
	mlx_hook(game.win_ptr, EXPOSE, EXPOSURE_MASK, render_map, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
