/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:57:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/10 21:44:53 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int 		fr_change_color(t_fractol *frc)
{
	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	frc->clr->unstable = fr_random_number() & 0xFF;
	frc->clr->stable = fr_random_number() & 0xFF +
			((fr_random_number() & 0xFF) << 0x8) +
			((fr_random_number() & 0xFF) << 0x16);
	frc->clr->shift = fr_random_number() & 0xF;
	int i = 0;
	while (i < MAX_ITERATIONS)
	{
		frc->clr->direct[i] = fr_random_number() & 0xFF +
							((fr_random_number() & 0xFF) << 0x8) +
							((fr_random_number() & 0xFF) << 0x16);
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
	return ((int)random_bytes[bytes_pointer++]);
}
