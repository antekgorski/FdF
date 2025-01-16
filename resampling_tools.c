/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/16 12:11:34 by agorski          ###   ########.fr       */
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
		while (i + 1 <= (data->map_height))
		{
			j = 0;
			while ((j + 1) <= (data->map_width))
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
		while (i + 1 <= (data->map_height))
		{
			j = 0;
			while ((j + 1) <= (data->map_width))
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
	while (i + 1 <= (data->map_height))
	{
		j = 0;
		while ((j + 1) <= (data->map_width))
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
