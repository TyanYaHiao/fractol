/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_color_solid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:49:34 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/20 19:21:56 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_solid_colors_init(t_fractol *frc)
{
	int		i;

	frc->clr->stable = 0x0;
	frc->clr->shift = 16;
	frc->clr->unstable = (int*)malloc(sizeof(int) * MAX_ITERATIONS);
	frc->clr->rainbow = (int*)malloc(sizeof(int) * SOLID_COLORS);
	i = 0;
	frc->clr->rainbow[i++] = RED;
	frc->clr->rainbow[i++] = ORANGE;
	frc->clr->rainbow[i++] = YELLOW;
	frc->clr->rainbow[i++] = GREEN;
	frc->clr->rainbow[i++] = TEAL;
	frc->clr->rainbow[i++] = BLUE;
	frc->clr->rainbow[i++] = PURPLE;
}

void		fr_solid_color(t_fractol *frc)
{
	int		i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0x0;
	frc->cff->color++;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = fr_solid_color_gradation(
				(frc->clr->rainbow[(frc->cff->color) % SOLID_COLORS]), i);
		i++;
	}
	fr_plot_image(frc);
}

int			fr_solid_color_gradation(int color, int i)
{
	double	gradation;
	int		red;
	int		blue;
	int		green;

	gradation = (double)(i % COLOR_DIVIDER) / COLOR_DIVIDER;
	red = (int)(((color >> 16) & 0xFF) * gradation);
	green = (int)(((color >> 8) & 0xFF) * gradation);
	blue = (int)((color & 0xFF) * gradation);
	return ((red << 16) + (green << 8) + blue);
}
