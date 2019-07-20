/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:57:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/20 19:04:54 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_random_color(t_fractol *frc)
{
	int		i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	frc->clr->stable = (rand() & 0xFFFFFF);
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = (rand() & 0xFFFFFF);
		i++;
	}
	fr_plot_image(frc);
	return (0);
}

void		fr_gradient_color(t_fractol *frc)
{
	int		i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0x0;
	frc->cff->color++;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = fr_color_gradation(
			frc->clr->rainbow[frc->cff->color % SOLID_COLORS], i);
		i++;
	}
	fr_plot_image(frc);
}

int			fr_color_gradation(int color, int i)
{
	double	gradation;
	int		red;
	int		blue;
	int		green;

	if (i < MAX_ITERATIONS / 2)
	{
		gradation = (double)(i) / (double)MAX_ITERATIONS * 2;
		red = (int)(((color >> 16) & 0xFF) * gradation);
		green = (int)(((color >> 8) & 0xFF) * gradation);
		blue = (int)((color & 0xFF) * gradation);
	}
	else
	{
		gradation = (((double)(i) / (double)MAX_ITERATIONS) - 0.5) * 2;
		red = ((0xFF - (color >> 16) & 0xFF) * gradation) +
				((color >> 16) & 0xFF);
		green = (0xFF - (color >> 8) & 0xFF) * gradation +
				((color >> 8) & 0xFF);
		blue = (0xFF - color & 0xFF) * gradation +
				((color >> 0) & 0xFF);
	}
	return ((red << 16) + (green << 8) + blue);
}

void		fr_rainbow_color(t_fractol *frc)
{
	int		i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0xFFFFFF;
	frc->cff->color++;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = frc->clr->rainbow[(i + frc->cff->color) % 7];
		i++;
	}
	fr_plot_image(frc);
}
