/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:16 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 19:47:17 by agorski          ###   ########.fr       */
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

void	ft_set_look(t_mlx *data)
{
	ft_map_resampler(data, ft_map_scale);
	ft_map_resampler(data, ft_isometric);
	ft_map_center(data);
	ft_map_resampler(data, ft_apply_cent_offset);
	data->c_offset_x = 0;
	data->c_offset_y = 0;
	ft_map_resampler(data, ft_apply_m_offset);
}
