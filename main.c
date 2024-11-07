/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 20:05:18 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 800
#define HEIGHT 600

int	close_program(t_mlx *data)
{
	mlx_destroy_window(data->mlx_start, data->mlx_win); // also free pointer:free(mlx_win);
	mlx_destroy_display(data->mlx_start);         // clenup mlx conection
	free(data->mlx_start);                    // free *ptr
	exit(0);							//close program imadetly
}

int handle_key(int keycode, t_mlx *data)
{
	if(keycode == 65307) // escape key
	{
		close_program(data);
	}
	//ft_printf("hello from keycode %d\n", keycode);
	return(0);
}

int	main(void)
{
	t_mlx	data;

	data.mlx_start = mlx_init(); // init conecction to serwer
	if (data.mlx_start == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_start, WIDTH, HEIGHT, "FdF"); // init new window
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx_start);
		free(data.mlx_start);
		return (1);
	}
	mlx_key_hook(data.mlx_win, handle_key, &data);  //specyfi for eath window
	mlx_hook(data.mlx_win, 17, 0, close_program, &data);
	mlx_loop(data.mlx_start);
	//close_program(data.mlx_start, data.mlx_win);
}
