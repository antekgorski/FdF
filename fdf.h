/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/10 17:24:08 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>  // open
# include <math.h>   // fmax, abs
# include <errno.h>  // perror
# include <unistd.h> // close
# include <string.h> // strerror

# define WIDTH 800
# define HEIGHT 600

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
	int			scale;
	t_point	**map_table;
}				t_mlx;

/**
 * @brief Structure that contains the read data.
 * @param line The line read.
 * @param point The point read.
 * @param color_p The color of the point.
 * @param row The row of the map.
 * @param tab The table of points that make up the map.
 * @param i The index of the point.
 * @param j The index of the row.
 */
typedef struct s_read
{
	char		*line;
	char		**point;
	char		**color_p;
	t_point	*row;
	t_point	**tab;
	int			i;
	int			j;
}				t_read;

// drow functions

void			ft_draw_line(t_mlx *data, t_point start, t_point end);

// utils functions

void			ft_panic(char *s, int status);
int				ft_open(const char *filename);
void			ft_read_file(char **av, t_mlx *data);
int				ft_count_line(char **tab);
int				ft_close_program(t_mlx *data);
void			ft_read(int fd, t_mlx *data);

// mlx utils functions

void			ft_event_handle(t_mlx *data);
void			ft_mlx_init(t_mlx *data);
int				handle_key(int keycode, t_mlx *data);

// free functions

void			ft_free_tab(void ***table);

#endif
