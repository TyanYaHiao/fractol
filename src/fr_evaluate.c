/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/05/31 20:29:24 by fsmith           ###   ########.fr       */
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
		if (frc->type == JULIA)
			pthread_create(&(threads[i]), NULL, fr_thread_julia, &data[i]);
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

void		fr_scale_image(int mode, int keycode, t_fractol *frc)
{
	if ((mode == KEYBOARD && keycode == KEY_PLUS)
	|| (mode == MOUSE && keycode == MOUSE_SCROLL_UP))
		frc->scale *= 1.2;
	else if ((mode == KEYBOARD && keycode == KEY_MINUS)
	|| (mode == MOUSE && keycode == MOUSE_SCROLL_DOWN))
		frc->scale /= 1.2;
	fr_plot_image(frc);
}

void		fr_move_to_center(t_fractol *frc)
{
	frc->offset_x = 0;
	frc->offset_y = 0;
	fr_plot_image(frc);
}
