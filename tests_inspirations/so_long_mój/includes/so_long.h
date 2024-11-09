/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:03 by prutkows          #+#    #+#             */
/*   Updated: 2024/11/08 08:53:52 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "key_linux.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define SPRITE_SIZE 32

# define COLLECTIBLE "sprites/coin.xpm"
# define EXIT "sprites/door.xpm"
# define WALL "sprites/wall.xpm"
# define FLOOR "sprites/dirt.xpm"
# define PLAYER_R "sprites/player_right.xpm"
# define PLAYER_L "sprites/player_left.xpm"
# define PLAYER_U "sprites/player_up.xpm"
# define PLAYER_D "sprites/player_down.xpm"

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x_position;
	int			player_y_position;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_image
{
	void		*texture_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_player
{
	t_image		player_r;
	t_image		player_l;
	t_image		player_u;
	t_image		player_d;
	char		direction;
}				t_player;

typedef struct s_data_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			total_collectibles;
	int			moves_count;
	t_map		map;
	t_image		collectible_image;
	t_image		exit_image;
	t_image		wall_image;
	t_image		floor_image;
	t_player	player;
}				t_data_game;

// init possition E and P, and move player
void			init_positions(t_data_game *game);
void			move_player_up(t_data_game *game);
void			move_player_down(t_data_game *game);
void			move_player_left(t_data_game *game);
void			move_player_right(t_data_game *game);

// init sprites and render sprites and map
void			init_sprites(t_data_game *game);
t_image			create_sprite(t_data_game *game, char *path);
void			render_sprite(t_data_game *game, t_image *sprite, int line,
					int column);
void			render_player(t_data_game *game, int line, int column);
int				render_map(t_data_game *game);

// read map with file and fill map and check expections
void			read_map(t_data_game *game, char *path);
void			fill_map(t_data_game *game, char *path);
void			validate_elements(t_data_game *game);
void			check_walls(t_data_game *game);
void			count_elements(t_data_game *game);

// Utils
int				open_map(char *path, t_data_game *game);
char			*split_line(char *line);
void			display_moves_and_collectibles(t_data_game *game);

// Messages
int				end_game(t_data_game *game, char *message, int code);
void			destroy_images(t_data_game *game);
void			exit_message(t_data_game *game, char *message, int code);

#endif
