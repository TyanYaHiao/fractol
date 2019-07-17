/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:57:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/17 21:27:51 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int 	fr_random_color(t_fractol *frc)
{
	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	frc->clr->stable = fr_random_number() & 0xFF +
			((fr_random_number() & 0xFF) << 0x8) +
			((fr_random_number() & 0xFF) << 0x16);
	frc->clr->shift = fr_random_number() & 0xF;
	int i = 0;
	while (i < MAX_ITERATIONS)
	{
//		frc->clr->unstable[i] = fr_random_number() & 0xFF +
//							((fr_random_number() & 0xFF) << 0x8) +
//							((fr_random_number() & 0xFF) << 0x16);
		frc->clr->unstable[i] = (rand() & 0xFFFFFF);
		i++;
	}
	fr_plot_image(frc);
	return (0);
}

int 	fr_color(t_fractol *fractol, int n)
{
	//color palette
	return (0xFF);
}

/*
**	Генерация рандомного инта для реализации цвета
*/

int fr_random_number()
{
	static char *random_bytes;
	static int bytes_pointer;
	int fd;

	if (random_bytes == NULL || bytes_pointer == BYTES_SIZE)
	{
		if (bytes_pointer == BYTES_SIZE)
		{
			bytes_pointer = 0;
			free(random_bytes);
		}
		random_bytes = ft_strnew(BYTES_SIZE);
		fd = open("/dev/urandom", O_RDONLY);
		read(fd, random_bytes, BYTES_SIZE);
	}
//	return ((int)random_bytes[bytes_pointer++]);
//	return ((int)(clock() & 0xFFFFFF));
	return ((int)(rand() & 0xFFFFFF));
}

void	fr_solid_color(t_fractol *frc)
{
	int i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0x0;
	frc->cff->color++;
	if (i % 3 == (0 + frc->cff->color) % 3)
		frc->clr->shift = 16;
	else if (i % 3 == (1 + frc->cff->color) % 3)
		frc->clr->shift = 4;
	else if (i % 3 == (2 + frc->cff->color) % 3)
		frc->clr->shift = 0;

	while (i < MAX_ITERATIONS)
	{
//		frc->clr->unstable[i] = (0xFF / 16 * i) << frc->clr->shift;
		frc->clr->unstable[i] = fr_color_gradation(ORANGE, i);
		i++;
	}
	fr_plot_image(frc);
}

void	fr_gradient_color(t_fractol *frc)
{
	int i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0x0;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = (0xFF / 16 * i) << frc->clr->shift;
		i++;
	}
	fr_plot_image(frc);
}

int 	fr_color_gradation(int color, int i)
{
	double	gradation;
	int 	red;
	int		blue;
	int 	green;

	if (i < MAX_ITERATIONS / 2)
	{
//	printf("%f ", gradation);
		gradation = (double)(i) / (double)MAX_ITERATIONS * 2;
		red = (int)(((color >> 16) & 0xFF) * gradation);
		green = (int)(((color >> 8) & 0xFF) * gradation);
		blue = (int)((color & 0xFF) * gradation);
//		printf("%d\n", red);
	}
	else
	{
		gradation = (double)(i) / (double)MAX_ITERATIONS;
		gradation = (gradation - 0.5) * 2;
		red = ((0xFF - (color >> 16) & 0xFF) * gradation) + ((color >> 16) & 0xFF);
		green = (0xFF - (color >> 8) & 0xFF) * gradation + ((color >> 8) & 0xFF);
		blue = (0xFF - color & 0xFF) * gradation + ((color >> 0) & 0xFF);
		printf("%d: %f, %x, %x, %x\n",i, gradation, red, green, blue);
	}
	return ((red << 16) + (green << 8) + blue);
//	return (15 * i << 16);
}

void	fr_rainbow_color(t_fractol *frc)
{
	int i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0xFFFFFF;
	frc->cff->color++;
//	if (frc->clr->counter > 6)
//		frc->clr->counter = 0;
//	frc->clr->shift = 0x10;
//	frc->clr->unstable = 0xFF;
	while (i < MAX_ITERATIONS)
	{
		if (i % 7 == (0 + frc->cff->color) % 7)
			frc->clr->unstable[i] = RED;
		else if (i % 7 == (1 + frc->cff->color) % 7)
			frc->clr->unstable[i] = ORANGE;
		else if (i % 7 == (2 + frc->cff->color) % 7)
			frc->clr->unstable[i] = YELLOW;
		else if (i % 7 == (3 + frc->cff->color) % 7)
			frc->clr->unstable[i] = GREEN;
		else if (i % 7 == (4 + frc->cff->color) % 7)
			frc->clr->unstable[i] = TEAL;
		else if (i % 7 == (5 + frc->cff->color) % 7)
			frc->clr->unstable[i] = BLUE;
		else if (i % 7 == (6 + frc->cff->color) % 7)
			frc->clr->unstable[i] = PURPLE;
		i++;
	}
	fr_plot_image(frc);
}
