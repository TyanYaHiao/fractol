/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_evluate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:37:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/14 20:00:16 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_evaluate(t_fractol *frc)
{
	double	r, temp_r;
	double	i, temp_i;
	int 	n;
	int 	iterations;

	n = 0;
	r = -3;
	while (r <= 3)
	{
		i = -3;
		while (i <= 3)
		{
			iterations = 0;
			temp_r = r;
			temp_i = i;
			while (iterations <= MAX_ITERATIONS)
			{
				temp_r = temp_r * temp_r - temp_i * temp_i - 0.15;
				temp_i = 2 * temp_r * temp_i + 0.01;
				iterations++;
			}
			frc->pts[n].real = temp_r / 1 + WINDOW_W / 2;
			frc->pts[n].imaginary = temp_i / 1 + WINDOW_H/2;
			n++;
			i += 0.1;
		}
		r += 0.1;
	}



//	frc->pts[0].real = 20;
//	frc->pts[0].imaginary = 20;
//	frc->pts[0].color = DEFAULT_COLOR;
//	frc->pts[1].real = 21;
//	frc->pts[1].imaginary = 21;
//	frc->pts[1].color = DEFAULT_COLOR;
//	frc->pts[2].real = 22;
//	frc->pts[2].imaginary = 22;
//	frc->pts[2].color = DEFAULT_COLOR;
//	frc->pts[3].real = 23;
//	frc->pts[3].imaginary = 23;
//	frc->pts[3].color = DEFAULT_COLOR;
//	frc->pts[4].real = 24;
//	frc->pts[4].imaginary = 24;
//	frc->pts[4].color = DEFAULT_COLOR;
//	frc->pts[5].real = 25;
//	frc->pts[5].imaginary = 25;
//	frc->pts[5].color = DEFAULT_COLOR;
//	frc->pts[6].real = 26;
//	frc->pts[6].imaginary = 26;
//	frc->pts[6].color = DEFAULT_COLOR;
}