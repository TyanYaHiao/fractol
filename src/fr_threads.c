/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:17:18 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 19:14:33 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void*		fr_thread_julia(void* thread_data)
{
	t_tdata *data;
	int		x;
	int		y;
	t_point	n;

	data = (t_tdata*) thread_data;
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		n.r = (x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			n.i = (y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y,
				fr_color_calc_mandelbrot(*data->frc->clr,
				n, data->frc->ctrl->c));
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
	t_point	n;
	t_point	c;

	data = (t_tdata*) thread_data;	//получаем структуру с данными
	//	Проход внутри сектора окна в рамках потока
	x = data->start_x;
	n.r = 0;
	n.i = 0;
	while (x < data->end_x)
	{
		y = 0;

		//	Преобразование координат пикселя в число на комплексной плоскости
		c.r = (double)(x + data->frc->offset_x) / data->frc->scale;

		//	Проход по всей высоте окна
		while (y < WINDOW_H)
		{
			c.i = (double)(y + data->frc->offset_y) / data->frc->scale;

			/*
			**	Последовательное исследование каждой точки на
			**	вхождение в множество Мандельброта
			**	Задание цвета точкам в зависимости от нестабильности
			*/
			fr_set_pixel(*data->frc, x, y,
				fr_color_calc_mandelbrot(*data->frc->clr, n, c));
			y++;
		}
		x++;
	}
	return NULL;
}

int 	fr_color_calc_mandelbrot(t_color color, t_point n, t_point c)
{
	int	i;
	t_point temp;

	i = 0;

	//	Исследование точки на стабильность
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
		temp.r = n.r * n.r - n.i * n.i + c.r;
		temp.i = 2 * n.r * n.i + c.i;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return(color.stable);
	else
		return(color.unstable[i]);
}

void*		fr_thread_burning_ship(void* thread_data)
{
	t_tdata	*data;
	int		x;
	int 	y;	// координаты пикселей на экране
	t_point	n;
	t_point	c;

	c.r = 0;
	c.i = 0;
	data = (t_tdata*) thread_data;	//получаем структуру с данными
	//	Проход внутри сектора окна в рамках потока
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;

		//	Преобразование координат пикселя в число на комплексной плоскости
		n.r = (double)(x + data->frc->offset_x) / data->frc->scale;

		//	Проход по всей высоте окна
		while (y < WINDOW_H)
		{
			n.i = (double)(y + data->frc->offset_y) / data->frc->scale;

			/*
			**	Последовательное исследование каждой точки на
			**	вхождение в множество Мандельброта
			**	Задание цвета точкам в зависимости от нестабильности
			*/
			fr_set_pixel(*data->frc, x, y,
				fr_color_calc_burning_ship(*data->frc->clr,
				n, c));
			y++;
		}
		x++;
	}
	return NULL;
}

int 	fr_color_calc_burning_ship(t_color color, t_point n, t_point c)
{
	int	i;
	t_point temp;

	i = 0;

	//	Исследование точки на стабильность
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
//		temp_r = n_r * n_r - n_i * n_i + c_r;
//		temp_i = 2 * n_r * n_i + c_i;
		temp.r = sqrt(n.r) - sqrt(n.i) + c.r;
		temp.i = 2 * ft_abs_double(n.r * n.i) + c.i;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return(color.stable);
	else
		return(color.unstable[i]);
}