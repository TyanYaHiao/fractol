/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:46:40 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/14 16:33:00 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void 	fr_init_fractol(t_fractol *fractol)
{
//
	fractol->scale = 100;
	fractol->pts = (t_points*)malloc(sizeof(t_points) * 10000 * 1000);
	fractol->svc = (t_service*)malloc(sizeof(t_service));
	fractol->svc->mlx_ptr = mlx_init();
	fractol->svc->win_ptr = mlx_new_window(fractol->svc->mlx_ptr,
		WINDOW_W, WINDOW_H, "Fract'ol");
	fractol->svc->img_ptr = mlx_new_image(fractol->svc->mlx_ptr, WINDOW_W,
		WINDOW_H);
	fractol->svc->image = mlx_get_data_addr(fractol->svc->img_ptr,
		&fractol->svc->bpp, &fractol->svc->s_line, &fractol->svc->endian);
//	frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
//	frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,

}
