/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:57:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 20:13:10 by fsmith           ###   ########.fr       */
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
	frc->clr->counter++;
	if (i % 3 == (0 + frc->clr->counter) % 3)
		frc->clr->shift = 16;
	else if (i % 3 == (1 + frc->clr->counter) % 3)
		frc->clr->shift = 4;
	else if (i % 3 == (2 + frc->clr->counter) % 3)
		frc->clr->shift = 0;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->unstable[i] = (0xFF / 16 * i) << frc->clr->shift;
		i++;
	}
	fr_plot_image(frc);
}

void	fr_rainbow_color(t_fractol *frc)
{
	int i;

	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	i = 0;
	frc->clr->stable = 0xFFFFFF;
	frc->clr->counter++;
//	if (frc->clr->counter > 6)
//		frc->clr->counter = 0;
//	frc->clr->shift = 0x10;
//	frc->clr->unstable = 0xFF;
	while (i < MAX_ITERATIONS)
	{
		if (i % 7 == (0 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = RED;
		else if (i % 7 == (1 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = ORANGE;
		else if (i % 7 == (2 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = YELLOW;
		else if (i % 7 == (3 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = GREEN;
		else if (i % 7 == (4 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = TEAL;
		else if (i % 7 == (5 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = BLUE;
		else if (i % 7 == (6 + frc->clr->counter) % 7)
			frc->clr->unstable[i] = PURPLE;
		i++;
	}
	fr_plot_image(frc);
}
