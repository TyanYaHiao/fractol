/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 21:00:52 by fsmith           ###   ########.fr       */
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
		if (i == THREADS - 1)
			data[i].end_x = WINDOW_W;
		else
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
		else if (frc->type == BURNING_SHIP)
			pthread_create(&(threads[i]), NULL, fr_thread_burning_ship, &data[i]);
		else if (frc->type == BUTTERFLY)
			pthread_create(&(threads[i]), NULL, fr_thread_butterfly, &data[i]);
		else if (frc->type == RANDOM)
			pthread_create(&(threads[i]), NULL, fr_thread_random, &data[i]);

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

	if ((keycode == MOUSE_SCROLL_UP || keycode == KEY_PLUS)
	&& frc->scale < 0x4FFFFFFF)
	{
		/*
		**	1.2 - коэффициент увеличения. 0.2 = 1.2 - 1
		*/
		frc->scale *= 1.2;
		frc->offset_x = (int)(frc->offset_x * 1.2 + x * 0.2);
		frc->offset_y = (int)(frc->offset_y * 1.2 + y * 0.2);
	}
	else if (keycode == MOUSE_SCROLL_DOWN || keycode == KEY_MINUS)
	{
		frc->scale /= 1.2;
		frc->offset_x = (int)(frc->offset_x / 1.2 - x * 0.2);
		frc->offset_y = (int)(frc->offset_y / 1.2 - y * 0.2);
	}
	fr_plot_image(frc);
}

void		fr_move_to_center(t_fractol *frc)
{
	frc->offset_x = -WINDOW_W / 2;
	frc->offset_y = -WINDOW_H / 2;
	frc->scale = START_SCALE;
	fr_plot_image(frc);
}

void	fr_random_fractol(t_fractol *frc)
{
	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	if (rand() % 2 == 0)
		frc->ctrl->s1 = 1;
	else
		frc->ctrl->s1 = -1;
	if (rand() % 2 == 0)
		frc->ctrl->s2 = 1;
	else
		frc->ctrl->s2 = -1;
	if (rand() % 2 == 0)
		frc->ctrl->s3 = 1;
	else
		frc->ctrl->s3 = -1;
	frc->ctrl->s4 = (int)rand() % 10;
	if (frc->ctrl->s4 == 9)
		frc->ctrl->s4 = 1.5;
	else if (frc->ctrl->s4 == 8)
		frc->ctrl->s4 = 3;
	else
		frc->ctrl->s4 = 2;
	frc->ctrl->s5 = (int)rand() % 3;
	if (rand() % 2 == 0)
		frc->ctrl->s6 = 1;
	else
		frc->ctrl->s6 = -1;
	fr_plot_image(frc);
}