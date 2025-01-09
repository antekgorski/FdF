/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:07:13 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 18:44:56 by agorski          ###   ########.fr       */
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
int ft_color_int(int start, int end, int i, int steps)
{
	int r;
	int g;
	int b;

	r = (start >> 16) + i * ((end >> 16) - (start >> 16)) / steps;
	g = (start >> 8 & 0xFF) + i * ((end >> 8 & 0xFF) - (start >> 8 & 0xFF)) / steps;
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
void	drawLine(t_mlx *data, t_point start, t_point end)
{
	int		dx;
	int		dy;
	float	xIncrement;
	float	yIncrement;
	float	x;
	float	y;
	int		steps;
	int		i;
	int color;

	dx = end.x - start.x;
	dy = end.y - start.y;
	steps = fmax(abs(dx), abs(dy));
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	i = 0;
	while (i <= steps)
	{
		x = round(start.x + i * xIncrement);
		y = round(start.y + i * yIncrement);
		color = ft_color_int(start.color, end.color, i, steps);
		mlx_pixel_put(data->mlx_start, data->mlx_win, x, y, color);
		i++;
	}
}
