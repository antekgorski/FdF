/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 16:54:55 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(t_mlx *data)
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

void	ft_draw_map(t_mlx *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + 1 < (data->map_height))
	{
		j = 0;
		while ((j + 1) < (data->map_width))
		{
			ft_draw_line(data, data->map_table[i][j], data->map_table[i][j
				+ 1]);
            ft_draw_line(data, data->map_table[i][j], data->map_table[i + 1][j]);
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
