/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/17 01:55:09 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_center_y(t_mlx *data)
{
	size_t	i;
	size_t	j;
	int		h;

	h = HEIGHT;
	while ((data->map_table[0][0].y) < (h - data->map_table[data->map_height
			- 1][0].y))
	{
		i = 0;
		while (i < (data->map_height))
		{
			j = 0;
			while (j < (data->map_width))
			{
				data->map_table[i][j].y++;
				if (j + 1 == data->map_table[i][j].row_width)
					break ;
				j++;
			}
			i++;
		}
	}
}

static void	ft_center_x(t_mlx *data)
{
	size_t	i;
	size_t	j;
	int		w;

	w = WIDTH;
	while ((data->map_table[0][0].x) < (w - data->map_table[0][data->map_width
			- 1].x))
	{
		i = 0;
		while (i < (data->map_height))
		{
			j = 0;
			while (j < (data->map_width))
			{
				data->map_table[i][j].x++;
				if (j + 1 == data->map_table[i][j].row_width)
					break ;
				j++;
			}
			i++;
		}
	}
}

void	ft_map_center(t_mlx *data)
{
	ft_center_y(data);
	ft_center_x(data);
}

void	ft_map_scale(t_mlx *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (data->map_height))
	{
		j = 0;
		while (j < (data->map_width))
		{
			data->map_table[i][j].x *= data->scale;
			data->map_table[i][j].y *= data->scale;
			if (j + 1 == data->map_table[i][j].row_width)
				break ;
			j++;
		}
		i++;
	}
}
// // Examples of different pointer casts:

// // 1. Function pointer cast
// void (*func)(t_point*) = (void (*)(t_point*))void_ptr;

// // 2. Data pointer cast
// int *number = (int*)void_ptr;

// // 3. Structure pointer cast
// t_point *point = (t_point*)void_ptr;
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
