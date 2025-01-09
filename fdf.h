/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 18:21:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_mlx
{
	void	*mlx_start;
	void	*mlx_win;
	t_map	*map;
}			t_mlx;

typedef struct s_point
{
	int		alt;
	int		color;
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	int		scale;
	t_point	**map_table;
}			t_map;

// drow functions

void	drawLine(t_mlx *data, int x0, int y0, int x1, int y1 /*, float r0,
				float g0, float b0, float r1, float g1, float b1*/);

// utils functions

void		ft_panic(char *s, int status);
int			ft_open(const char *filename);
void		ft_read_file(char **av, t_map *map);
int			ft_count(char **tab);
int			ft_close_program(t_mlx *data);

// mlx utils functions

void		ft_event_handle(t_mlx *data);
void		ft_mlx_init(t_mlx *data);
int			handle_key(int keycode, t_mlx *data);

#endif
