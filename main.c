/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2025/01/10 17:08:19 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_test(t_point **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].alt)
		{
			ft_printf("x: %d, y: %d, alt: %d, color: %d\n", map[i][j].x,
				map[i][j].y, map[i][j].alt, map[i][j].color);
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
	data->scale = 0;
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
		ft_map_test(data.map_table);
		mlx_loop(data.mlx_start);
	}
	return (0);
}
