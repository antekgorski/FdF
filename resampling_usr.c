/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling_usr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:07:41 by agorski           #+#    #+#             */
/*   Updated: 2025/01/21 01:39:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_user_angle(t_mlx *data, int keycode)
{
	if (keycode == K_W)
		data->angle_x += 0.1;
	if (keycode == K_A)
		data->angle_y += 0.1;
	if (keycode == K_S)
		data->angle_x -= 0.1;
	if (keycode == K_D)
		data->angle_y -= 0.1;
}

static void	ft_user_move(t_mlx *data, int keycode)
{
	if (keycode == K_LEFT)
		data->m_offset_x -= data->mov_ofset;
	if (keycode == K_RIGHT)
		data->m_offset_x += data->mov_ofset;
	if (keycode == K_UP)
		data->m_offset_y -= data->mov_ofset;
	if (keycode == K_DOWN)
		data->m_offset_y += data->mov_ofset;
}

static void	ft_reset_angle(t_mlx *data)
{
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
}

static void	ft_change_view(t_mlx *data, int keycode)
{
	if (keycode == K_1)
	{
		ft_reset_angle(data);
		data->isometric = 1;
	}
	if (keycode == K_2)
	{
		ft_reset_angle(data);
		data->isometric = 0;
	}
}

void	ft_user_resample(t_mlx *data, int keycode)
{
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		ft_user_angle(data, keycode);
	if (keycode == K_1 || keycode == K_2)
		ft_change_view(data, keycode);
	if (keycode == K_LEFT || keycode == K_RIGHT || keycode == K_UP
		|| keycode == K_DOWN)
		ft_user_move(data, keycode);
	if (keycode == K_C)
	{
		ft_reset_angle(data);
		data->m_offset_x = 0;
		data->m_offset_y = 0;
	}
	if (keycode == K_PLUS)
		data->scale *= 1.1;
	if (keycode == K_MINUS)
		data->scale *= 0.9;
	ft_set_look(data);
	ft_redraw(data);
}
