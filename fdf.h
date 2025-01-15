/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 23:52:13 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <errno.h>  // perror
# include <fcntl.h>  // open
# include <math.h>   // fmax, abs
# include <string.h> // strerror
# include <unistd.h> // close

# define WIDTH 10
# define HEIGHT 10

/**
 * @brief Structure that contains the point data.
 * @param alt The altitude of the point.
 * @param color The color of the point.
 * @param x The x coordinate of the point.
 * @param y The y coordinate of the point.
 */
typedef struct s_point
{
	int				alt;
	unsigned int	color;
	int				x;
	int				y;
	size_t			row_width;
}					t_point;

/**
 * @brief Structure that contains the mlx data.
 * @param mlx_start The pointer to the mlx data.
 * @param mlx_win The pointer to the window.
 * @param map The pointer to the map data.
 */
typedef struct s_mlx
{
	void			*mlx_start;
	void			*mlx_win;
	int				scale;
	t_point			**map_table;
	size_t			map_height;
	size_t			map_width;
	void			*img;
}					t_mlx;

/**
 * @brief Structure that contains the read data.
 * @param 	char		*line;
 * @param	char		**point;
 * @param	char		**color_p;
 * @param	t_point	*row;
 * @param	t_point	**tab;
 * @param	int			i;
 * @param	int			j;
 */
typedef struct s_read
{
	char			*line;
	char			**point;
	char			**color_p;
	t_point			*row;
	t_point			**tab;
	int				i;
	int				j;
}					t_read;

/**
 * @brief Structure that contains the data for drow line.
 * @param	int		dx;
 * @param	int		dy;
 * @param	float	x_inc;
 * @param	float	y_inc;
 * @param	float	x;
 * @param	float	y;
 * @param	int		steps;
 * @param	int		i;
 * @param	int		color;
 */
typedef struct s_line_draw
{
	int				dx;
	int				dy;
	float			x_inc;
	float			y_inc;
	int				x;
	int				y;
	int				steps;
	int				i;
	int				color;
}					t_line_draw;

// drow functions

void				ft_draw_line(t_mlx *data, t_point start, t_point end);
void				ft_drow_image(t_mlx *data);
void				ft_pix_to_img(t_mlx *data, int x, int y, int color);
void				ft_draw_map(t_mlx *data);
void				ft_map_scale(t_mlx *data);
void				ft_map_center(t_mlx *data);

// utils functions

void				ft_panic(char *s, int status);
int					ft_open(const char *filename);
void				ft_read_file(char **av, t_mlx *data);
int					ft_count_line(char **tab);
int					ft_close_program(t_mlx *data);
void				ft_read(int fd, t_mlx *data);

// mlx utils functions

void				ft_event_handle(t_mlx *data);
void				ft_mlx_init(t_mlx *data);
int					handle_key(int keycode, t_mlx *data);

// free functions

void				ft_free_tab(void ***table);
void				ft_free_map(t_mlx *data);

#endif
