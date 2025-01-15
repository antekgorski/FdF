/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 14:52:46 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_mlx *data)
{
	int		n;
	int		x;
	int		y;
	int		scale;
	t_point	**array;

	x = 50;
	y = 50;
	n = 0;
	array = data->map->map_table;
	scale = data->map->scale;
	while (&array[n])
	{
		if (&array[n + 1] != NULL)
			ft_draw_line(x, y, x + (50 * scale), y + (25 + scale));
		x += 50 * scale;
		y = 25 * scale;
		n++;
	}
}
