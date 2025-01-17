/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:20:39 by agorski           #+#    #+#             */
/*   Updated: 2025/01/17 13:53:36 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	float			scale;
	t_point			**map_table;
	size_t			map_height;
	size_t			map_width;
	int				max_alt;
	int				min_alt;
	void			*img;
	int				mov_ofset;
	int				c_offset_x;
	int				c_offset_y;
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

typedef struct s_center_ofsert
{
	int				i;
	int				j;
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
	int				win_width;
	int				win_height;
}					t_center_ofset;