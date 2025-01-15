/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:27 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 14:50:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drow_image(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx_start, WIDTH, HEIGHT);
	if (data->img == NULL)
		ft_panic("mlx_new_image failed\n", 1);
	mlx_put_image_to_window(data->mlx_start, data->mlx_win, data->img, 0, 0);
}