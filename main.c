/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2024/11/08 20:11:25 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 800
#define HEIGHT 800

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
	
	drawLine(&data, 100, 100, 100, 700);// | po lewej
	drawLine(&data, 100, 100, 700, 100);// - na gorze
	drawLine(&data, 100, 100, 700, 700);/*  \      */ 
	drawLine(&data, 100, 700, 700, 100);//  /    
	drawLine(&data, 700, 100, 700, 700);// | po prawej
	drawLine(&data, 100, 700, 700, 700);// _ na dole
	
	
	
	
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 410, 110, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 220, 200, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 130, 230, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 40, 400, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 550, 50, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 60, 460, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 270, 70, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 80, 580, 0xFFFFFF);
	// mlx_pixel_put(data.mlx_start, data.mlx_win, 90, 290, 0xFFFFFF);
	mlx_loop(data.mlx_start);
	//close_program(data.mlx_start, data.mlx_win);
}
