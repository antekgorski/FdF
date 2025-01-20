/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 01:38:54 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// external libraries

# include <errno.h>  // perror
# include <fcntl.h>  // open
# include <limits.h> // INT_MAX ect.
# include <math.h>   // fmax, abs
# include <string.h> // strerror
# include <unistd.h> // close

// mlx library, libft library, my own header file

# include "libft.h"
# include "mlx.h"
# include "structs.h"

// window size

# define WIDTH 800
# define HEIGHT 600

// base colors

# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000

// defining the function pointer to the resampling function
typedef void	(*point_resampler_t)(t_mlx *data, t_point *point, size_t i,
		size_t j);

// drow functions

void			ft_draw_line(t_mlx *data, t_point start, t_point end);
void			ft_draw_image(t_mlx *data);
void			ft_pix_to_img(t_mlx *data, int x, int y, int color);
void			ft_draw_map(t_mlx *data);
void			ft_redraw(t_mlx *data);

// resaampling functions

void			ft_first_look(t_mlx *data);
void			ft_map_scale(t_mlx *data, t_point *point, size_t i, size_t j);
void			ft_map_resampler(t_mlx *data, point_resampler_t v_point);
void			ft_user_resample(t_mlx *data, int keycode);
void			map_move_left(t_mlx *data);
void			map_move_right(t_mlx *data);
void			map_move_up(t_mlx *data);
void			map_move_down(t_mlx *data);
void			ft_map_center(t_mlx *data);
void			ft_apply_map_offset(t_mlx *data, t_point *point, size_t i,
					size_t j);
void			ft_isometric(t_mlx *data, t_point *point, size_t i, size_t j);

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
void			ft_map_test(t_mlx *data);

// free functions

void			ft_free_tab(void ***table);
void			ft_free_map(t_mlx *data);

#endif
