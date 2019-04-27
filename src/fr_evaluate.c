/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/27 16:45:11 by fsmith           ###   ########.fr       */
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
	double 	n_r, n_i, c_r, c_i, temp_r, temp_i;
	int		x, y, temp_x, temp_y;
	int 	i;
	int 	color;

	c_r = (double)(frc->coeff_x - WINDOW_W / 2) / START_SCALE;
	c_i = (double)(frc->coeff_y - WINDOW_H / 2) / START_SCALE;
	x = 0;
	while (x < WINDOW_W)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			i = 0;
			n_r = (double)(x - WINDOW_W / 2) / START_SCALE;
			n_i = (double)(y - WINDOW_H / 2) / START_SCALE;
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
				color = 0x0000FF / 0xF * i;
			fr_set_pixel2(*frc, x, y, color);
			y++;
		}
		x++;
	}
}
