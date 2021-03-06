/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_plot_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:52:39 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_set_pixel(t_fractol frc, int x, int y, int color)
{
	int		*tmp;

	tmp = (int*)frc.svc->image;
	if (x >= 0 && x <= WINDOW_W
		&& y >= 0 && y <= WINDOW_H)
		tmp[WINDOW_W * y + x] = color;
}

void		fr_plot_image(t_fractol *frc)
{
	int		i;

	i = 0;
	mlx_clear_window(frc->svc->mlx_ptr, frc->svc->win_ptr);
	frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
	frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,
		&frc->svc->bpp, &frc->svc->s_line, &frc->svc->endian);
	fr_evaluate(frc);
	mlx_put_image_to_window(frc->svc->mlx_ptr, frc->svc->win_ptr,
		frc->svc->img_ptr, 0, 0);
	mlx_destroy_image(frc->svc->mlx_ptr, frc->svc->img_ptr);
	fr_info(frc);
	if (frc->cff->color > MAX_ITERATIONS)
		frc->cff->color = MAX_ITERATIONS & 1;
}
