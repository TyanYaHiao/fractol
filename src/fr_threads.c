/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:17:18 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/07 19:28:38 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void*		fr_thread_julia(void* thread_data)
{
//	//получаем структуру с данными
//	t_tdata *data = (t_tdata*) thread_data;
//
//	int		x, y, temp_x, temp_y;
//	int		i, color;
//	double 	n_r, n_i, c_r, c_i, temp_r, temp_i;
//
//	c_r = (double)(data->frc->coeff_x - WINDOW_W / 2) / data->frc->scale;
//	c_i = (double)(data->frc->coeff_y - WINDOW_H / 2) / data->frc->scale;
//	x = data->start_x;
//	while (x < data->end_x)
//	{
//		y = 0;
//		while (y < WINDOW_H)
//		{
//			i = 0;
//			n_r = (double)(x - WINDOW_W / 2) / data->frc->scale;
//			n_i = (double)(y - WINDOW_H / 2) / data->frc->scale;
//			temp_x = x;
//			temp_y = y;
//			while (i < MAX_ITERATIONS && temp_x >= 0 && temp_y >= 0
//				   && temp_x <= WINDOW_W && temp_y <= WINDOW_H)
//			{
//				temp_r = n_r * n_r - n_i * n_i + c_r;
//				temp_i = 2 * n_r * n_i + c_i;
//				n_r = temp_r;
//				n_i = temp_i;
//				temp_x = (int) n_r * START_SCALE + WINDOW_W / 2;
//				temp_y = (int) n_i * START_SCALE + WINDOW_H / 2;
//				i++;
//			}
//			if (i == MAX_ITERATIONS)
//				color = 0x000000;
//			else
//				color = (0x0000FF / 16 * i) << 16;
//			fr_set_pixel(*data->frc, x, y, color);
//			y++;
//		}
//		x++;
//	}
	return NULL;
}

void*		fr_thread_mandelbrot(void* thread_data)
{
	t_tdata *data = (t_tdata*) thread_data;
	int		x, y;	// координаты пикселей на экране
	double 	c_r, c_i;	// числа на комплексной плоскости

	//	Проход внутри сектора окна в рамках потока
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;

		//	Преобразование координат пикселя в число на комплексной плоскости
		c_r = (double)(x + data->frc->offset_x)
			/ data->frc->scale;

		//	Проход по всей высоте окна
		while (y < WINDOW_H)
		{
			c_i = (double)(y + data->frc->offset_y)
				/ data->frc->scale;

			/*
			**	Последовательное исследование каждой точки на
			**	вхождение в множество Мандельброта
			**	Задание цвета точкам в зависимости от нестабильности
			*/
			fr_set_pixel(*data->frc, x, y, fr_color_calc_mandelbrot(0, 0, c_r, c_i));
			y++;
		}
		x++;
	}
	return NULL;
}

int 	fr_color_calc_mandelbrot(double n_r, double n_i, double c_r, double c_i)
{
	int	i;
	double temp_r;
	double temp_i;

	i = 0;

	//	Исследование точки на стабильность
	while (i < MAX_ITERATIONS && (n_r * n_r * 0.95 + n_i * n_i) <= 4)
	{
		temp_r = n_r * n_r - n_i * n_i + c_r;
		temp_i = 2 * n_r * n_i + c_i;
		n_r = temp_r;
		n_i = temp_i;
		i++;
	}
	//	Цвет стабильной точки
	if (i == MAX_ITERATIONS)
		return(0x000000);

	//	Цвет нестабильной точки зависит от величины ее нестабильности
	else
		return((0x0000FF / 16 * i) << 16);
}