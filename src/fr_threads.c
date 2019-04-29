/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:17:18 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/29 20:59:13 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void*		fr_thread_julia(void* thread_data)
{
	//получаем структуру с данными
	t_tdata *data = (t_tdata*) thread_data;

	int		x, y, temp_x, temp_y;
	int		i, color;
	double 	n_r, n_i, c_r, c_i, temp_r, temp_i;

	c_r = (double)(data->frc->coeff_x - WINDOW_W / 2) / data->frc->scale;
	c_i = (double)(data->frc->coeff_y - WINDOW_H / 2) / data->frc->scale;
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			i = 0;
			n_r = (double)(x - WINDOW_W / 2) / data->frc->scale;
			n_i = (double)(y - WINDOW_H / 2) / data->frc->scale;
			temp_x = x;
			temp_y = y;
			while (i < MAX_ITERATIONS && temp_x >= 0 && temp_y >= 0
				   && temp_x <= WINDOW_W && temp_y <= WINDOW_H)
			{
				temp_r = n_r * n_r - n_i * n_i + c_r;
				temp_i = 2 * n_r * n_i + c_i;
				n_r = temp_r;
				n_i = temp_i;
				temp_x = (int) n_r * START_SCALE + WINDOW_W / 2;
				temp_y = (int) n_i * START_SCALE + WINDOW_H / 2;
				i++;
			}
			if (i == MAX_ITERATIONS)
				color = 0x000000;
			else
				color = (0x0000FF / 16 * i) << 16;
			fr_set_pixel2(*data->frc, x, y, color);
			y++;
		}
		x++;
	}
	return NULL;
}

void*		fr_thread_mandelbrot(void* thread_data)
{
	t_tdata *data = (t_tdata*) thread_data;

	int		x, y, temp_x, temp_y;
	int		i, color;
	double 	n_r, n_i, c_r, c_i, temp_r, temp_i;

	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			i = 0;
			n_r = 0;
			n_i = 0;
			c_r = (double)(x - WINDOW_W / 2 + data->frc->offset_x)
					/ data->frc->scale;
			c_i = (double)(y - WINDOW_H / 2 + data->frc->offset_y)
					/ data->frc->scale;
			temp_x = x;
			temp_y = y;
//			while (i < MAX_ITERATIONS && temp_x >= -WINDOW_W && temp_y >= -WINDOW_H
//				   && temp_x <= WINDOW_W && temp_y <= WINDOW_H)
			while (i < MAX_ITERATIONS && (n_r * n_r + c_i * c_i) <= 4)
			{
				temp_r = n_r * n_r - n_i * n_i + c_r;
				temp_i = 2 * n_r * n_i + c_i;
				n_r = temp_r;
				n_i = temp_i;
				temp_x = (int) n_r * START_SCALE + WINDOW_W / 2 + data->frc->offset_x;
				temp_y = (int) n_i * START_SCALE + WINDOW_H / 2 + data->frc->offset_y;
				i++;
			}
			if (i == MAX_ITERATIONS)
				color = 0x000000;
			else
				color = (0x0000FF / 16 * i) << 16;
			fr_set_pixel2(*data->frc, x, y, color);
			y++;
		}
		x++;
	}
	return NULL;
}