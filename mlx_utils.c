/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:49 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 17:56:44 by agorski          ###   ########.fr       */
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
		close_program(data);
	return (0);
}

/**
 * @brief 	handle key press
 * @brief set key hook for window
 * @brief 17 - (is code of x button)
 * @param data pointer to struct with mlx data
 * @return 0
 */
void	ft_event_handle(t_mlx *data)
{
	mlx_key_hook(data->mlx_win, handle_key, &data);
	mlx_hook(data->mlx_win, 17, 0, close_program, &data);
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
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_start, WIDTH, HEIGHT, "FdF"); // init new window
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx_start);
		free(data->mlx_start);
		return (1);
	}
}
