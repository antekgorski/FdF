/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:27 by agorski           #+#    #+#             */
/*   Updated: 2025/01/16 12:11:28 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drow_image(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx_start, WIDTH, HEIGHT);
	if (data->img == NULL)
		ft_panic("mlx_new_image failed\n", 1);
	ft_draw_map(data);
	mlx_put_image_to_window(data->mlx_start, data->mlx_win, data->img, 0, 0);
}

void	ft_draw_map(t_mlx *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + 1 <= (data->map_height))
	{
		j = 0;
		while ((j + 1) <= (data->map_width))
		{
			if (j + 1 != data->map_table[i][j].row_width)
				ft_draw_line(data, data->map_table[i][j], data->map_table[i][j
					+ 1]);
			if (i + 1 != data->map_height)
				ft_draw_line(data, data->map_table[i][j], data->map_table[i
					+ 1][j]);
			if (j + 1 == data->map_table[i][j].row_width)
				break ;
			j++;
		}
		i++;
	}
}
