/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 20:25:39 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>  // open
# include <math.h>   // fmax, abs
# include <stdio.h>  // perror
# include <unistd.h> // close

# define WIDTH 800
# define HEIGHT 600

/**
 * @brief Structure that contains the data needed to display the map.
 * @param alt The altitude of the point.
 * @param color The color of the point.
 */
typedef struct s_tab_point
{
	int			alt;
	int			color;
}				t_tab_point;

/**
 * @brief Structure that contains the map data.
 * @param scale The scale of the map.
 * @param map_table The table of points that make up the map.
 */
typedef struct s_map
{
	int			scale;
	t_tab_point	**map_table;
}				t_map;

/**
 * @brief Structure that contains the mlx data.
 * @param mlx_start The pointer to the mlx data.
 * @param mlx_win The pointer to the window.
 * @param map The pointer to the map data.
 */
typedef struct s_mlx
{
	void		*mlx_start;
	void		*mlx_win;
	t_map		*map;
}				t_mlx;

/**
 * @brief Structure that contains the point data.
 * @param alt The altitude of the point.
 * @param color The color of the point.
 * @param x The x coordinate of the point.
 * @param y The y coordinate of the point.
 */
typedef struct s_point
{
	int			alt;
	int			color;
	int			x;
	int			y;
}				t_point;

typedef struct s_read
{
	char		*line;
	char		**point;
	char		**color_p;
	t_tab_point	*row;
	t_tab_point	**tab;
	int			i;
}				t_read;

// drow functions

void			drawLine(t_mlx *data, t_point start, t_point end);

// utils functions

void			ft_panic(char *s, int status);
int				ft_open(const char *filename);
void			ft_read_file(char **av, t_map *map);
int				ft_count(char **tab);
int				ft_close_program(t_mlx *data);
void			ft_read(int fd, t_map *data);

// mlx utils functions

void			ft_event_handle(t_mlx *data);
void			ft_mlx_init(t_mlx *data);
int				handle_key(int keycode, t_mlx *data);

// free functions

void			ft_free_tab(void **table);

#endif
