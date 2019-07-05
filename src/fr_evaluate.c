/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/05 22:02:09 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
	int 	i;

	pthread_t* threads = (pthread_t*) malloc(sizeof(pthread_t) * THREADS);
	t_tdata *data = (t_tdata*)malloc(sizeof(t_tdata) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		data[i].start_x = WINDOW_W / THREADS * i;
		data[i].end_x = WINDOW_W / THREADS * (i + 1);
		data[i].frc = frc;

		/*
		**	Многопоточные вычисления джулии
		*/
		if (frc->type == JULIA)
			pthread_create(&(threads[i]), NULL, fr_thread_julia, &data[i]);

		/*
		**	Многопоточные вычисления мандельброта
		*/
		else if (frc->type == MANDELBROT)
			pthread_create(&(threads[i]), NULL, fr_thread_mandelbrot, &data[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	free(data);
}

void		fr_scale_image(int mode, int keycode, t_fractol *frc, int x, int y)
{
	if (keycode == KEY_PLUS || keycode == MOUSE_SCROLL_UP)
		frc->scale *= 1.2;
	else if (keycode == KEY_MINUS || keycode == MOUSE_SCROLL_DOWN)
		frc->scale /= 1.2;
	if (mode == MOUSE)
	{
		if (keycode == MOUSE_SCROLL_UP)
		{
			frc->offset_x += (int)(x / 1.2);
			frc->offset_y += (int)(y / 1.2);
		}
		else if (keycode == MOUSE_SCROLL_DOWN)
		{
			frc->offset_x -= (int)(x / 10);
			frc->offset_y -= (int)(y / 10);
		}
	}
	else if (mode == KEYBOARD)
	{
		//	Сделать приближение к центру экрана
		if (keycode == KEY_PLUS)
		{
			frc->offset_x += (WINDOW_W / 2) / frc->scale;
			frc->offset_y += (WINDOW_H / 2) / frc->scale;
		}
		else if (keycode == KEY_MINUS)
		{
			frc->offset_x -= (WINDOW_W / 2) / frc->scale;
			frc->offset_y -= (WINDOW_H / 2) / frc->scale;
		}
	}
	fr_plot_image(frc);
}

void		fr_move_to_center(t_fractol *frc)
{
	frc->offset_x = 0;
	frc->offset_y = 0;
	fr_plot_image(frc);
}
