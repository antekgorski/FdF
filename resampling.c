/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:16 by agorski           #+#    #+#             */
/*   Updated: 2025/01/17 14:35:33 by agorski          ###   ########.fr       */
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
			v_point(data, &data->map_table[i][j]);
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
	ft_center_offset(data);
	ft_map_resampler(data, ft_map_center);
}

void	ft_user_resample(t_mlx *data, int keycode)
{
	if (keycode == 65361)
		ft_map_resampler(data, map_move_left);
	else if (keycode == 65363)
		ft_map_resampler(data, map_move_right);
	else if (keycode == 65362)
		ft_map_resampler(data, map_move_up);
	else if (keycode == 65364)
		ft_map_resampler(data, map_move_down);
	else if (keycode == 99)
	{
		ft_center_offset(data);
		ft_map_resampler(data, ft_map_center);
	}
	else if (keycode == 61)
	{
		data->scale = 1.1;
		ft_center_offset(data);
		ft_map_resampler(data, ft_map_center);
		ft_map_resampler(data, ft_map_scale);
		ft_map_resampler(data, ft_map_recenter);
	}
	else if (keycode == 45)
	{
		data->scale = -1.1;
		ft_center_offset(data);
		ft_map_resampler(data, ft_map_center);
		ft_map_resampler(data, ft_map_scale);
		ft_map_resampler(data, ft_map_recenter);
	}
	ft_redraw(data);
}
