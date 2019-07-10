/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:46:40 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/10 21:19:37 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void 	fr_init_fractol(t_fractol *fractol)
{

	fractol->offset_x = -WINDOW_W / 2;
	fractol->offset_y = -WINDOW_H / 2;
	fractol->scale = START_SCALE;
	fractol->svc = (t_service*)malloc(sizeof(t_service));
	fractol->svc->mlx_ptr = mlx_init();
	fractol->svc->win_ptr = mlx_new_window(fractol->svc->mlx_ptr,
		WINDOW_W, WINDOW_H, fr_convert_name(fractol->type));
	fractol->svc->img_ptr = mlx_new_image(fractol->svc->mlx_ptr, WINDOW_W,
		WINDOW_H);
	fractol->svc->image = mlx_get_data_addr(fractol->svc->img_ptr,
		&fractol->svc->bpp, &fractol->svc->s_line, &fractol->svc->endian);

	fractol->ctrl = (t_control*)malloc(sizeof(t_control));
	fractol->ctrl->mouse_left_button = FALSE;
	fractol->ctrl->mouse_right_button = FALSE;
	fractol->ctrl->prev_x = 0;
	fractol->ctrl->prev_y = 0;
	fractol->clr = (t_color*)malloc(sizeof(t_color));
	fractol->clr->stable = 0x0;
	fractol->clr->unstable = 0xFF;
	fractol->clr->shift = 16;
	fractol->clr->direct = (int*)malloc(sizeof(int) * MAX_ITERATIONS);
}
