/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:17:18 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/10 21:21:40 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void*		fr_thread_julia(void* thread_data)
{
	t_tdata *data;
	int		x;
	int		y;
	double 	n_r;
	double 	n_i;

	data = (t_tdata*) thread_data;
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		n_r = (x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			n_i = (y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y, fr_color_calc_mandelbrot(*data->frc->clr, n_r, n_i,
				data->frc->ctrl->c_r, data->frc->ctrl->c_i));
			y++;
		}
		x++;
	}
	return NULL;
}

void*		fr_thread_mandelbrot(void* thread_data)
{
	t_tdata	*data;
	int		x;
	int 	y;	// координаты пикселей на экране
	double 	c_r;
	double 	c_i;

	data = (t_tdata*) thread_data;	//получаем структуру с данными
	//	Проход внутри сектора окна в рамках потока
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;

		//	Преобразование координат пикселя в число на комплексной плоскости
		c_r = (double)(x + data->frc->offset_x) / data->frc->scale;

		//	Проход по всей высоте окна
		while (y < WINDOW_H)
		{
			c_i = (double)(y + data->frc->offset_y) / data->frc->scale;

			/*
			**	Последовательное исследование каждой точки на
			**	вхождение в множество Мандельброта
			**	Задание цвета точкам в зависимости от нестабильности
			*/
			fr_set_pixel(*data->frc, x, y, fr_color_calc_mandelbrot(*data->frc->clr, 0, 0, c_r, c_i));
			y++;
		}
		x++;
	}
	return NULL;
}

void*		fr_thread_burning_ship(void* thread_data)
{
	t_tdata	*data;
	int		x;
	int 	y;	// координаты пикселей на экране

	data = (t_tdata*) thread_data;	//получаем структуру с данными
	//	Проход внутри сектора окна в рамках потока
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;

		//	Преобразование координат пикселя в число на комплексной плоскости
		data->frc->ctrl->c_r = (double)(x + data->frc->offset_x) / data->frc->scale;

		//	Проход по всей высоте окна
		while (y < WINDOW_H)
		{
			data->frc->ctrl->c_i = (double)(y + data->frc->offset_y) / data->frc->scale;

			/*
			**	Последовательное исследование каждой точки на
			**	вхождение в множество Мандельброта
			**	Задание цвета точкам в зависимости от нестабильности
			*/
			fr_set_pixel(*data->frc, x, y, fr_color_calc_mandelbrot(*data->frc->clr, 0, 0, data->frc->ctrl->c_r, data->frc->ctrl->c_i));
			y++;
		}
		x++;
	}
	return NULL;
}

int 	fr_color_calc_mandelbrot(t_color color, double n_r, double n_i, double c_r, double c_i)
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
		return(color.stable);

		//	Цвет нестабильной точки зависит от величины ее нестабильности
	else
//		return((0x0000FF / 16 * i) << 16);
//		return((color.unstable / 16 * i) << color.shift);
		return(color.direct[i]);
}