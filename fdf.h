/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2024/11/09 13:19:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "./libft++/libft.h"
# include "minilibx-linux/mlx.h"

// typedef struct s_color
// {

// }

// typedef struct s_data_game
// {
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	int			total_collectibles;
// 	int			moves_count;
// 	t_map		map;
// 	t_image		collectible_image;
// 	t_image		exit_image;
// 	t_image		wall_image;
// 	t_image		floor_image;
// 	t_player	player;
// }				t_data_game;

typedef struct s_mlx
{
	void *mlx_start; //
	void	*mlx_win;
}			t_mlx;


void		drawLine(t_mlx *data, int x0, int y0, int x1, int y1 /*, float r0, float g0, float b0, float r1, float g1, float b1*/);

#endif
