/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/15 21:44:32 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
	double	r, temp_r, temp_r2;
	double	i, temp_i, temp_i2;
	int 	n;
	int 	iterations;

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
//			frc->pts[n].x = frc->pts[n].r;
//			frc->pts[n].y = frc->pts[n].i;
//			n++;
//			i += 0.01;
//		}
//		r += 0.01;
//	}



	frc->pts[0].x = 20;
	frc->pts[0].y = 20;
	frc->pts[0].color = DEFAULT_COLOR;
	frc->pts[1].x = 21;
	frc->pts[1].y = 21;
	frc->pts[1].color = DEFAULT_COLOR;
	frc->pts[2].x = 22;
	frc->pts[2].y = 22;
	frc->pts[2].color = DEFAULT_COLOR;
	frc->pts[3].x = 23;
	frc->pts[3].y = 23;
	frc->pts[3].color = DEFAULT_COLOR;
	frc->pts[4].x = 24;
	frc->pts[4].y = 24;
	frc->pts[4].color = DEFAULT_COLOR;
	frc->pts[5].x = 25;
	frc->pts[5].y = 25;
	frc->pts[5].color = DEFAULT_COLOR;
	frc->pts[6].x = 26;
	frc->pts[6].y = 26;
	frc->pts[6].color = DEFAULT_COLOR;
}