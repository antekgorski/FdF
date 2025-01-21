/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:36:03 by agorski           #+#    #+#             */
/*   Updated: 2025/01/21 01:09:41 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_scale(t_mlx *data, t_point *point, size_t i, size_t j)
{
	point->off_x = j * data->scale;
	point->off_y = i * data->scale;
	point->off_z = (point->alt / 10) * data->scale;
}

void	ft_isometric(t_mlx *data, t_point *point, size_t i, size_t j)
{
	float	prev_x;
	float	prev_y;

	(void)i;
	(void)j;
	if (data->isometric == 0)
		return ;
	prev_x = point->off_x;
	prev_y = point->off_y;
	point->off_x = (prev_x - prev_y) * cos(0.523599);
	point->off_y = -point->off_z + (prev_x + prev_y) * sin(0.523599);
}

void	rotate_around_x(t_mlx *data, t_point *point, size_t i, size_t j)
{
	float	old_y;

	(void)i;
	(void)j;
	old_y = point->off_y;
	point->off_y = (point->off_y * cos(data->angle_x)) + (point->off_z
			* sin(data->angle_x));
	point->off_z = (-old_y * sin(data->angle_x)) + (point->off_z
			* cos(data->angle_x));
}

void	rotate_around_y(t_mlx *data, t_point *point, size_t i, size_t j)
{
	float	old_x;

	(void)i;
	(void)j;
	old_x = point->off_x;
	point->off_x = (point->off_x * cos(data->angle_y)) + (point->off_z
			* sin(data->angle_y));
	point->off_z = (-old_x * sin(data->angle_y)) + (point->off_z
			* cos(data->angle_y));
}

void	rotate_around_z(t_mlx *data, t_point *point, size_t i, size_t j)
{
	float	old_x;

	(void)i;
	(void)j;
	old_x = point->off_x;
	point->off_x = (point->off_x * cos(data->angle_z)) - (point->off_y
			* sin(data->angle_z));
	point->off_y = (old_x * sin(data->angle_z)) + (point->off_y
			* cos(data->angle_z));
}
