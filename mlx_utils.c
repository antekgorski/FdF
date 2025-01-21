/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:49 by agorski           #+#    #+#             */
/*   Updated: 2025/01/21 02:07:20 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief 	handle key press
 * @param keycode key code (65307 = escape key)
 * @param data pointer to struct with mlx data
 * @return 0
 */
int	handle_key(int keycode, t_mlx *data)
{
	if (keycode == 65307)
		ft_close_program(data);
	else
		ft_user_resample(data, keycode);
	ft_printf("keycode: %d\n", keycode);
	return (0);
}

/**
 * @brief 	handle event for close window
 * @brief set hook for window
 * @brief 17 - (is code of x button)
 * @param data pointer to struct with mlx data
 * @return 0
 */
void	ft_event_handle(t_mlx *data)
{
	mlx_key_hook(data->mlx_win, handle_key, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close_program, data);
}

/**
 * @brief 	init mlx
 * @brief create new window
 * @brief if failed to create window destroy display and free pointer
 * @param data pointer to struct with mlx data
 */
void	ft_mlx_init(t_mlx *data)
{
	data->mlx_start = mlx_init();
	if (data->mlx_start == NULL)
		ft_panic("mlx_init failed\n", 1);
	data->mlx_win = mlx_new_window(data->mlx_start, WIDTH, HEIGHT, "FdF");
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx_start);
		free(data->mlx_start);
		ft_panic("mlx_new_window failed\n", 1);
	}
}
