/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/28 17:14:46 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
	if (frc->type == EXPLANATION)
	{
		fr_explanation(frc);
	}
	else if (frc->type == JULIA)
	{
		fr_julia(frc);
	}
}

void		fr_mandelbrot(t_fractol *frc)
{

}

void		fr_explanation(t_fractol *frc)
{
	int		n;
	double	n_r;
	double	n_i;
	double	c_r;
	double	c_i;
	double	temp_r;
	double	temp_i;
	int		temp_n;

	temp_n = 0;
	n = 0;
	n_r = (double)(frc->number_x - WINDOW_W / 2) / START_SCALE;
	n_i = (double)(frc->number_y - WINDOW_H / 2) / START_SCALE;
	c_r = (double)(frc->coeff_x - WINDOW_W / 2) / START_SCALE;
	c_i = (double)(frc->coeff_y - WINDOW_H / 2) / START_SCALE;
	while (n < 100)
	{
		temp_r = n_r * n_r - n_i * n_i + c_r;
		temp_i = 2 * n_r * n_i + c_i;
		frc->pts[n].r = temp_r;
		frc->pts[n].i = temp_i;
		frc->pts[n].x = (int)(frc->pts[n].r * START_SCALE + WINDOW_W / 2);
		frc->pts[n].y = (int)(frc->pts[n].i * START_SCALE + WINDOW_H / 2);
		frc->pts[n].iterations = n;
		if (frc->pts[n].x < 0 || frc->pts[n].x > WINDOW_W
		|| frc->pts[n].y < 0 || frc->pts[n].y > WINDOW_H)
		{
			temp_n = n;
			n = 0;
			while (n < temp_n)
			{
				frc->pts[n].color = 0x00FF00 / 5 * frc->pts[n].iterations;
				n++;
			}
			break;
		}
		n_r = temp_r;
		n_i = temp_i;
		n++;
	}
	if (!temp_n)
	{
		n = 0;
		while (n < 100)
		{
			frc->pts[n].color = 0xFF0000;
			n++;
		}
	}
}

void		fr_julia(t_fractol *frc)
{
	int		i;

	pthread_t* threads = (pthread_t*) malloc(sizeof(pthread_t) * THREADS);
	t_tdata *data = (t_tdata*)malloc(sizeof(t_tdata) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		data[i].start_x = WINDOW_W / THREADS * i;
		data[i].end_x = WINDOW_W / THREADS * (i + 1);
		data[i].frc = frc;
		pthread_create(&(threads[i]), NULL, fr_thread_julia, &data[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
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