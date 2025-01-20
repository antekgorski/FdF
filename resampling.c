/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:16 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 02:09:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_resampler(t_mlx *data, point_resampler_t v_point)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (data->map_height))
	{
		j = 0;
		while (j < (data->map_width))
		{
			v_point(data, &data->map_table[i][j], i, j);
			if (j + 1 == data->map_table[i][j].row_width)
				break ;
			j++;
		}
		i++;
	}
}

void	ft_first_look(t_mlx *data)
{
	ft_map_resampler(data, ft_map_scale);
	ft_map_resampler(data, ft_isometric);
	ft_map_center(data);
	ft_map_resampler(data, ft_apply_map_offset);
	data->c_offset_x = 0;
	data->c_offset_y = 0;
}

void	ft_move_map(t_mlx *data, int key)
{
	if (key == 65361)
		map_move_left(data);
	else if (key == 65363)
		map_move_right(data);
	else if (key == 65362)
		map_move_up(data);
	else if (key == 65364)
		map_move_down(data);
	else if (key == 99)
		ft_map_center(data);
}

void	ft_user_resample(t_mlx *data, int keycode)
{
	if (keycode == 65361 || keycode == 65363 || keycode == 65362
		|| keycode == 65364 || keycode == 99)
		ft_move_map(data, keycode);
	else if (keycode == 61)
	{
		data->scale *= 1.1;
		ft_map_resampler(data, ft_map_scale);
		ft_map_center(data);
	}
	else if (keycode == 45)
	{
		data->scale *= 0.9;
		ft_map_resampler(data, ft_map_scale);
		ft_map_center(data);
	}
	ft_map_resampler(data, ft_apply_map_offset);
	data->c_offset_x = 0;
	data->c_offset_y = 0;
	ft_redraw(data);
}
