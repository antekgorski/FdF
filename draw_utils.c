/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:07:13 by agorski           #+#    #+#             */
/*   Updated: 2025/01/11 18:50:13 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief 	interpolation of color
 * @brief color format 0xRRGGBB
 * @param start start color
 * @param end end color
 * @param i current step
 * @param steps total steps
 * @param | - OR, & - AND, >> - right shift, << - left shift
 * @return color
 */
static int	ft_color_int(int start, int end, int i, int steps)
{
	int	r;
	int	g;
	int	b;

	r = (start >> 16) + i * ((end >> 16) - (start >> 16)) / steps;
	g = (start >> 8 & 0xFF) + i * ((end >> 8 & 0xFF) - (start >> 8 & 0xFF))
		/ steps;
	b = (start & 0xFF) + i * ((end & 0xFF) - (start & 0xFF)) / steps;
	return (r << 16 | g << 8 | b);
}

/**
 * @brief 	drow line between two points
 * @brief 	uses Bresenham's line algorithm
 * @brief 	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * @brief 	https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
 * @brief 	fmax - returns the greater of two floating-point numbers
 * @brief 	round
		- rounds the floating-point number argument to the nearest integer
 * @brief 	abs - returns the absolute value of an integer
 * @brief 	x and y and color. interpolation
 * @param data pointer to struct with mlx data
 */
void	ft_draw_line(t_mlx *data, t_point start, t_point end)
{
	t_l_drw	;

	dx = end.x - start.x;
	dy = end.y - start.y;
	steps = fmax(abs(dx), abs(dy));
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	i = 0;
	while (i <= steps)
	{
		x = round(start.x + i * x_inc);
		y = round(start.y + i * y_inc);
		color = ft_color_int(start.color, end.color, i, steps);
		mlx_pixel_put(data->mlx_start, data->mlx_win, x, y, color);
		i++;
	}
}

// void	draw_map(t_mlx *data)
// {
// 	int		n;
// 	int		x;
// 	int		y;
// 	int		scale;
// 	t_point	**array;

// 	x = 50;
// 	y = 50;
// 	n = 0;
// 	array = data->map->map_table;
// 	scale = data->map->scale;
// 	while (&array[n])
// 	{
// 		if (&array[n + 1] != NULL)
// 			ft_draw_line(x, y, x + (50 * scale), y + (25 + scale));
// 		x += 50 * scale;
// 		y = 25 * scale;
// 		n++;
// 	}
// }
