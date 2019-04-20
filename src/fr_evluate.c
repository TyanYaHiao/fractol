/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/20 17:28:02 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
//	double	r, temp_r, temp_r2;
//	double	i, temp_i, temp_i2;
//	int 	n;
//	int 	iterations;
//
//	n = 0;
//	r = -3;
//	while (r <= 3)
//	{
//		i = -3;
//		while (i <= 3)
//		{
//			temp_r = r;
//			temp_i = i;
//			iterations = 0;
//			while (iterations <= MAX_ITERATIONS)
//			{
//				temp_r2 = temp_r * temp_r - temp_i * temp_i;
//				temp_i2 = 2 * temp_r * temp_i;
//				temp_r = temp_r2;
//				temp_i = temp_i2;
//				iterations++;
//				if (temp_r > WINDOW_W || temp_r < -WINDOW_W
//				|| temp_i > WINDOW_H || temp_i < -WINDOW_H)
//					break;
//			}
//			printf("%d: %f, %f\n", n, temp_r, temp_i);
//			frc->pts[n].r = temp_r + WINDOW_W / 2;
//			frc->pts[n].i = temp_i + WINDOW_H / 2;
//			frc->pts[n].x = (int)frc->pts[n].r * 2;
//			frc->pts[n].y = (int)frc->pts[n].i * 2;
//			frc->pts[n].color = DEFAULT_COLOR;
//			n++;
//			i += 0.01;
//		}
//		r += 0.01;
//	}

//	int g = 0;
//	while (g < 500)
//	{
//		frc->pts[g].x = 20 + g;
//		frc->pts[g].y = 20 + g;
//		frc->pts[g].color = DEFAULT_COLOR;
//		g++;
//	}

//	r = -2;
//	while (r < 2,5)
//	{
//		i = -2;
//		{
//			temp_r = r;
//			temp_i = i;
//			iterations = 0;
//			while (iterations <= MAX_ITERATIONS)
//			{
//				temp_r2 = temp_r * temp_r - temp_i * temp_i;
//				temp_i2 = 2 * temp_r * temp_i;
//				iterations++;
//				if (temp_r > WINDOW_W || temp_r < -WINDOW_W
//				|| temp_i > WINDOW_H || temp_i < -WINDOW_H)
//					break;
//			}
//			i += 0.1;
//		}
//		r += 0.1;
//	}

	int n;

	n = 0;
	fr_mandelbrot(frc);
	while (n < STEP_X * STEP_Y)
	{
		frc->pts[n].y = (int)(frc->pts[n].i * START_SCALE + WINDOW_H / 2);
		frc->pts[n].x = (int)(frc->pts[n].r * START_SCALE + WINDOW_W / 2);
		frc->pts[n].color = 0xFF0000 * frc->pts[n].iterations / 20;
		n++;
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
