/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:17:18 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/20 20:10:09 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		*fr_thread_julia(void *thread_data)
{
	t_tdata *data;
	int		x;
	int		y;
	t_point	n;

	data = (t_tdata*)thread_data;
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
	return (NULL);
}

void		*fr_thread_mandelbrot(void *thread_data)
{
	t_tdata	*data;
	int		x;
	int		y;
	t_point	n;
	t_point	c;

	data = (t_tdata*)thread_data;
	x = data->start_x;
	n.r = 0;
	n.i = 0;
	while (x < data->end_x)
	{
		y = 0;
		c.r = (double)(x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			c.i = (double)(y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y,
				fr_color_calc_mandelbrot(*data->frc->clr, n, c));
			y++;
		}
		x++;
	}
	return (NULL);
}

void		*fr_thread_burning_ship(void *thread_data)
{
	t_tdata	*data;
	int		x;
	int		y;
	t_point	n;
	t_point	c;

	data = (t_tdata*)thread_data;
	x = data->start_x;
	n.r = 0;
	n.i = 0;
	while (x < data->end_x)
	{
		y = 0;
		c.i = (double)(x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			c.r = (double)(y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y,
				fr_color_calc_burning_ship(*data->frc->clr, n, c));
			y++;
		}
		x++;
	}
	return (NULL);
}

void		*fr_thread_butterfly(void *thread_data)
{
	t_tdata *data;
	int		x;
	int		y;
	t_point	n;

	data = (t_tdata*)thread_data;
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		n.r = (x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			n.i = (y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y,
						fr_color_calc_burning_ship(*data->frc->clr,
						n, data->frc->ctrl->c));
			y++;
		}
		x++;
	}
	return (NULL);
}

void		*fr_thread_random(void *thread_data)
{
	t_tdata *data;
	int		x;
	int		y;
	t_point	n;

	data = (t_tdata*)thread_data;
	x = data->start_x;
	while (x < data->end_x)
	{
		y = 0;
		n.r = (x + data->frc->offset_x) / data->frc->scale;
		while (y < WINDOW_H)
		{
			n.i = (y + data->frc->offset_y) / data->frc->scale;
			fr_set_pixel(*data->frc, x, y,
					fr_color_calc_random_fractol(*data->frc->cff,
					*data->frc->clr, n, data->frc->ctrl->c));
			y++;
		}
		x++;
	}
	return (NULL);
}
