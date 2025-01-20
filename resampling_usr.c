/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling_usr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:07:41 by agorski           #+#    #+#             */
/*   Updated: 2025/01/20 19:47:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_user_resample(t_mlx *data, int keycode)
{
	if (keycode == K_1)
		data->isometric = 1;
	if (keycode == K_2)
		data->isometric = 0;
	if (keycode == K_LEFT)
		data->m_offset_x -= data->mov_ofset;
	if (keycode == K_RIGHT)
		data->m_offset_x += data->mov_ofset;
	if (keycode == K_UP)
		data->m_offset_y -= data->mov_ofset;
	if (keycode == K_DOWN)
		data->m_offset_y += data->mov_ofset;
	if (keycode == K_C)
	{
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
