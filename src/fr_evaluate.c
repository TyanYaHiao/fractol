/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/22 21:42:48 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
//
//
//	int n;
//
//	n = 0;
//	fr_mandelbrot(frc);
//	while (n < STEP_X * STEP_Y)
//	{
//		frc->pts[n].y = (int)(frc->pts[n].i * START_SCALE + WINDOW_H / 2);
//		frc->pts[n].x = (int)(frc->pts[n].r * START_SCALE + WINDOW_W / 2);
//		frc->pts[n].color = 0xFF0000 * frc->pts[n].iterations / 20;
//		n++;
//	}
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
	int		n;
	int		iterations;
	double	r;
	double	i;
	double	temp_r;
	double	temp_i;
	double	temp_r2;
	double	temp_i2;

	n = 0;
	r = -3;
	while (r < 2)
	{
		i = -2;
		while (i < 2)
		{
			iterations = 0;
			temp_r = r;
			temp_i = i;
			while (iterations < MAX_ITERATIONS)
			{
				temp_r *= r;
				temp_i *= i;
//				temp_r2 = temp_r * temp_r - temp_i * temp_i;
//				temp_i2 = 2 * temp_r * temp_i;
				if (temp_r < -3 || temp_r > 2 || temp_i < -2 || temp_i > 2)
					break;
//				temp_r = temp_r2;
//				temp_i = temp_i2;
				iterations++;
			}
			if (iterations > 5)
			{
				frc->pts[n].r = temp_r;
				frc->pts[n].i = temp_i;
				frc->pts[n].iterations = iterations;
				n++;
			}
			i += 0.01;
		}
		r += 0.01;
	}
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
//	int		n;
//	double	r;
//	double	i;
//	double	temp_r;
//	double	temp_i;
//	int		temp_n;
//
//	temp_n = 0;
//
//	r = -0.5;
//	while (r < 0.5)
//	{
//		i = -0.5;
//		while (i < 0.5)
//		{
//			n = 0;
//			while (n < 100)
//			{
//				temp_r = r * r - i * i + frc->coeff_x;
//				temp_i = 2 * r * i + frc->coeff_y;
//				frc->pts[n].r = temp_r;
//				frc->pts[n].i = temp_i;
//				frc->pts[n].x = (int) (frc->pts[n].r * START_SCALE + WINDOW_W / 2);
//				frc->pts[n].y = (int) (frc->pts[n].i * START_SCALE + WINDOW_H / 2);
//				frc->pts[n].iterations = n;
//				if (frc->pts[n].x < 0 || frc->pts[n].x > WINDOW_W
//					|| frc->pts[n].y < 0 || frc->pts[n].y > WINDOW_H)
//				{
//					temp_n = n;
//					n = 0;
//					while (n < temp_n)
//					{
//						frc->pts[n].color = 0x00FF00 / 5 * frc->pts[n].iterations;
//						n++;
//					}
//					break;
//				}
//				r = temp_r;
//				i = temp_i;
//				n++;
//			}
//			if (!temp_n)
//			{
//				n = 0;
//				while (n < 100)
//				{
//					frc->pts[n].color = 0xFF0000;
//					n++;
//				}
//			}
//			int i = 0;
//			while (i < 100)
//			{
//				fr_set_pixel(*frc, i);
//				i++;
//			}
//			i += 0.01;
//		}
//		r += 0.01;
//	}
}
