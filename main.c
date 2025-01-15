/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 16:41:22 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_test(t_mlx *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + 1 <= (data->map_height))
	{
		j = 0;
		while ((j + 1) <= (data->map_width))
		{
			ft_printf("[%d,%d] x:%d y:%d alt:%d rgb:%X row_len:%d map_len:%d\n",
				i, j, data->map_table[i][j].x,
				data->map_table[i][j].y, data->map_table[i][j].alt,
				data->map_table[i][j].color, data->map_table[i][j].row_width,
				data->map_width);
			if (j + 1 == data->map_table[i][j].row_width)
				break ;
			j++;
		}
		i++;
	}
}

void	ft_init_data(t_mlx *data, t_point **map_table)
{
	data->mlx_start = NULL;
	data->mlx_win = NULL;
	data->map_table = map_table;
	data->scale = 20;
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
		ft_map_test(&data);
		ft_drow_image(&data);
		mlx_loop(data.mlx_start);
	}
	return (0);
}
