/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:27 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 22:50:12 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drow_image(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx_start, WIDTH, HEIGHT);
	if (data->img == NULL)
		ft_panic("mlx_new_image failed\n", 1);
	ft_map_center(data);
    ft_map_scale(data);
    ft_draw_map(data);
	mlx_put_image_to_window(data->mlx_start, data->mlx_win, data->img, 0, 0);
}