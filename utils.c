/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:07:13 by agorski           #+#    #+#             */
/*   Updated: 2024/11/08 19:49:23 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Funkcja symulująca rysowanie piksela z kolorem (R, G, B)
// void	putPixelWithColor(int x, int y,/* float r, float g, float b*/)
// {
// 	printf("Rysuję piksel na: (%d, %d)) //z kolorem R=%.2f, G=%.2f, B=%.2f\n",x,
// 		y, r, g, b);
// }
// Kolor jest przekazywany jako liczba całkowita 32-bitowa w formacie ARGB (Alpha,Red, Green, Blue).
// A - przezroczystość (0 - pełna przezroczystość, 255- pełna nieprzezroczystość),
// R - czerwony (0-255),
// G - zielony (0-255),
// B - niebieski (0-255).
// int color = (255 << 24) | (0 << 16) | (255 << 8) | 0;  // 0xFF00FF00

void	drawLine(t_mlx *data, int x0, int y0, int x1, int y1/*float r0, float g0, float b0, float r1, float g1, float b1*/)
{
	int		dx;
	int		dy;
	float	xIncrement; //liczba zmiennoprzecinkowa
	float	yIncrement;
	float	x;
	float	y;

	dx = x1 - x0;
	dy = y1 - y0;
	int steps = fmax(fabs(dx), fabs(dy)); // Maksymalna różnica między x i y
	// fabs zwraca wartość bezwzględną liczby zmiennoprzecinkowej(odleglosc).
	//Funkcja fmax zwraca większą z dwóch liczb zmiennoprzecinkowych.
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	// float rIncrement = (r1 - r0) / steps;
	// float gIncrement = (g1 - g0) / steps;
	// float bIncrement = (b1 - b0) / steps;
	int i = 0; // Inicjalizacja zmiennej kontrolującej pętlę
	while (i <= steps)
	{ // Obliczanie współrzędnych i kolorów na podstawie interpolacji
		x = round(x0 + i * xIncrement);//Funkcja round() zaokrągla podaną wartość do najbliższej liczby całkowitej.
		y = round(y0 + i * yIncrement);
		// float r = r0 + i * rIncrement;
		// float g = g0 + i * gIncrement;
		// float b = b0 + i * bIncrement;
		mlx_pixel_put(data->mlx_start, data->mlx_win, x, y, 0xFFFFFFFF /* r, g, b*/);
		i++;
	}
}
