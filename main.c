/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 19:47:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_data(t_mlx *data, t_point **map_table)
{
	data->mlx_start = NULL;
	data->mlx_win = NULL;
	data->map_table = map_table;
	data->scale = 10;
	data->map_height = 0;
	data->map_width = 0;
	data->max_alt = 0;
	data->min_alt = 0;
	data->img = NULL;
	data->mov_ofset = 10;
	data->c_offset_x = 0;
	data->c_offset_y = 0;
	data->m_offset_x = 0;
	data->m_offset_y = 0;
	data->isometric = 1;
}

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_point	**map_table;

	map_table = NULL;
	ft_init_data(&data, map_table);
	if (argc != 2)
		ft_panic("Usage: ./fdf [map]\n", 1);
	else
	{
		ft_read_file(argv, &data);
		ft_mlx_init(&data);
		ft_event_handle(&data);
		ft_set_look(&data);
		ft_draw_image(&data);
		mlx_loop(data.mlx_start);
	}
	return (0);
}
