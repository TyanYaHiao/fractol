/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:18:53 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/10 20:09:13 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_mouse_press(int button, int x, int y, t_fractol *frc)
{
	if (button == MOUSE_LEFT_BUTTON)
		frc->ctrl->mouse_left_button = TRUE;
	if (button == MOUSE_RIGHT_BUTTON)
		frc->ctrl->mouse_right_button = TRUE;
	if (frc->type == EXPLANATION)
	{
		if (button == MOUSE_LEFT_BUTTON)
		{
			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
			fr_plot_image(frc);
		}
		if (button == MOUSE_RIGHT_BUTTON)
		{
			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
			mlx_destroy_image(frc->svc->mlx_ptr, frc->svc->img_ptr);
			frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
			frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,
				&frc->svc->bpp, &frc->svc->s_line, &frc->svc->endian);
		}
	}
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN
		|| button == MOUSE_BUTTON_MID)
	{
		if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		{
			fr_scale_image(MOUSE, button, frc, x, y);
		}
	}
	return (0);
}

int			fr_mouse_release(int button, int x, int y, t_fractol *frc)
{
	if (button == MOUSE_LEFT_BUTTON)
	{
		frc->ctrl->mouse_left_button = FALSE;
		frc->ctrl->prev_x = 0;
		frc->ctrl->prev_y = 0;
	}
	else if (button == MOUSE_RIGHT_BUTTON)
		frc->ctrl->mouse_right_button = FALSE;
	return (0);
}

int			fr_mouse_move(int x, int y, t_fractol *frc)
{
	frc->ctrl->x = x;
	frc->ctrl->y = y;
	if (frc->type == JULIA)
	{
		frc->ctrl->c_r = (frc->ctrl->x + frc->offset_x) / frc->scale;
		frc->ctrl->c_i = (frc->ctrl->y + frc->offset_y) / frc->scale;
		fr_plot_image(frc);
	}
	else if (frc->type == MANDELBROT)
	{
		if (frc->ctrl->mouse_left_button)
		{
			if (frc->ctrl->prev_x == 0)
				frc->ctrl->prev_x = x;
			if (frc->ctrl->prev_y == 0)
				frc->ctrl->prev_y = y;
			frc->offset_x += frc->ctrl->prev_x - x;
			frc->offset_y += frc->ctrl->prev_y - y;
			frc->ctrl->prev_x = x;
			frc->ctrl->prev_y = y;
		}
		fr_plot_image(frc);
	}
	return (0);
}