/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:07:13 by agorski           #+#    #+#             */
/*   Updated: 2025/01/16 11:19:09 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief 	put pixel to image
 * @param data pointer to struct with mlx data
 * @param x, y coordinate
 * @param color color in HEX format
 * @brief 	bits_per_pixel - number of bits per pixel
 * @brief 	size_line - number of bytes used to store one line of the image in memory
 * @brief 	endian - 0 = sever X is little endian, 1 = big endian
 * @brief 	data_addr - pointer to the image data
 * @brief 	pixel_offset - offset of the pixel in the image data
 * @brief 	*(int *)(data_addr + pixel_offset) - set color to pixel
 */
void	ft_pix_to_img(t_mlx *data, int x, int y, int color)
{
	int		pixel_offset;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data_addr;

	data_addr = mlx_get_data_addr(data->img, &bits_per_pixel, &size_line,
			&endian);
	if (data_addr == NULL)
		ft_panic("mlx_get_data_addr failed\n", 1);
	pixel_offset = (y * size_line) + (x * (bits_per_pixel / 8));
	*(int *)(data_addr + pixel_offset) = color;
}

/**
 * @brief 	interpolation of color
 * @brief color format 0xRRGGBB
 * @param start start color
 * @param end end color
 * @param i current step
 * @param steps total steps
 * @param | - OR, & - AND, >> - right shift, << - left shift
 * @return color in HEX format
 */
static int	ft_color_int(int start, int end, int i, int steps)
{
	int	r;
	int	g;
	int	b;

	if (steps == 0)
		return (start);
		   // ft_printf("Start: 0x%X, End: 0x%X\n", start, end);
    r = ((start >> 16) & 0xFF) + i * (((end >> 16) & 0xFF) - ((start >> 16) & 0xFF)) / steps;
    g = ((start >> 8) & 0xFF) + i * (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / steps;
    b = (start & 0xFF) + i * ((end & 0xFF) - (start & 0xFF)) / steps;
	// ft_printf("Step %d/%d: R=%d, G=%d, B=%d\n", i, steps, r, g, b);
	return (0xFF000000 | r << 16 | g << 8 | b);
}

/**
 * @brief 	drow line between two points with color interpolation.
 * @brief 	uses Bresenham's line algorithm
 * @brief 	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * @brief 	https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
 * @brief 	fmax - returns the greater of two floating-point numbers
 * @brief 	round
		- rounds the floating-point number argument to the nearest integer
 * @brief 	abs - returns the absolute value of an integer
 * @brief 	x and y and color. interpolation
 * @param data pointer to struct with mlx data
 * @param start Starting point of the line.
 * @param end Ending point of the line.
 */
void	ft_draw_line(t_mlx *data, t_point start, t_point end)
{
	t_line_draw	line;

	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	line.steps = fmax(abs(line.dx), abs(line.dy));
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	line.i = 0;
	while (line.i <= line.steps)
	{
		line.x = round(start.x + line.i * line.x_inc);
		line.y = round(start.y + line.i * line.y_inc);
		line.color = ft_color_int(start.color, end.color, line.i, line.steps);
		ft_pix_to_img(data, line.x, line.y, line.color);
		line.i++;
	}
}
