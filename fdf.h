/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 19:17:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h> // fmax, abs
# include <stdio.h> // perror
# include <fcntl.h> // open
# include <unistd.h> // close

# define WIDTH 800
# define HEIGHT 600

typedef struct s_tab_point
{
	int			alt;
	int			color;
}				t_tab_point;

typedef struct s_map
{
	int			scale;
	t_tab_point	**map_table;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_start;
	void		*mlx_win;
	t_map		*map;
}				t_mlx;

typedef struct s_point
{
	int			alt;
	int			color;
	int			x;
	int			y;
}				t_point;

// drow functions

void			drawLine(t_mlx *data, t_point start, t_point end);

// utils functions

void			ft_panic(char *s, int status);
int				ft_open(const char *filename);
void			ft_read_file(char **av, t_map *map);
int				ft_count(char **tab);
int				ft_close_program(t_mlx *data);

// mlx utils functions

void			ft_event_handle(t_mlx *data);
void			ft_mlx_init(t_mlx *data);
int				handle_key(int keycode, t_mlx *data);

#endif
