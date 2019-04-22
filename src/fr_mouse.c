/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:18:53 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/22 19:37:57 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_mouse_press(int button, int x, int y, t_fractol *frc)
{
	if (frc->type == EXPLANATION)
	{
		if (button == MOUSE_LEFT_BUTTON)
		{
			frc->ctrl->mouse_left_button = TRUE;
			frc->mouse_x = x;
			frc->mouse_y = y;
			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
			fr_evaluate(frc);
			fr_plot_image(frc);
		}
		if (button == MOUSE_RIGHT_BUTTON)
		{
			frc->offset_x = ((double) x - WINDOW_W / 2) / START_SCALE;
			frc->offset_y = ((double) y - WINDOW_H / 2) / START_SCALE;
			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
			mlx_destroy_image(frc->svc->mlx_ptr, frc->svc->img_ptr);
			frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
			frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,
												&frc->svc->bpp, &frc->svc->s_line, &frc->svc->endian);
		}
	}
	else if (frc->type == JULIA)
	{

	}



//	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN
//		|| button == MOUSE_BUTTON_MID)
//	{
//		if (button == MOUSE_BUTTON_MID)
//			frc->control->mouse_button_mid = TRUE;
//		else
//		{
//			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
//			if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
//			{
//				if (button == MOUSE_SCROLL_UP)
//				{
//					fdf->offset_x -= ((x - WINDOW_W / 2) / 3);
//					fdf->offset_y -= ((y - WINDOW_H / 2) / 3);
//				}
//				if (button == MOUSE_SCROLL_DOWN)
//				{
//					fdf->offset_x -= ((x - WINDOW_W / 2) / 10);
//					fdf->offset_y -= ((y - WINDOW_H / 2) / 10);
//				}
//				fdf_scale_image(MOUSE, button, frc);
//			}
//		}
//	}
	return (0);
}

int			fr_mouse_release(int button, int x, int y, t_fractol *frc)
{
	if (button == MOUSE_LEFT_BUTTON)
	{
		frc->ctrl->mouse_left_button = FALSE;
	}
//	x++;
//	y++;
//	if (button == MOUSE_BUTTON_MID)
//	{
//		frc->control->mouse_button_mid = FALSE;
//		frc->control->prev_y = 0;
//		frc->control->prev_x = 0;
//	}
	return (0);
}

//void		fr_mouse_move_modificator(int x, int y, t_fractol *frc)
//{
//	if (fdf->control->key_shift == FALSE && fdf->control->key_ctrl == TRUE)
//	{
//		fdf->offset_x += x - fdf->control->prev_x;
//		fdf->offset_y += y - fdf->control->prev_y;
//		fdf->control->prev_x = x;
//		fdf->control->prev_y = y;
//	}
//	if (fdf->control->key_shift == TRUE && fdf->control->key_ctrl == FALSE)
//	{
//		fdf->angle_z += ANGLE_STEP * (y - fdf->control->prev_y) / 100;
//		fdf->control->prev_x = x;
//	}
//}

int			fr_mouse_move(int x, int y, t_fractol *frc)
{
	if (frc->type == EXPLANATION)
	{
		if (frc->ctrl->mouse_left_button == TRUE)
		{
			frc->mouse_x = x;
			frc->mouse_y = y;
			mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
			fr_evaluate(frc);
			fr_plot_image(frc);
		}
	}
	else if (frc->type == JULIA)
	{

	}

//	if (fdf->control->mouse_button_mid == TRUE)
//	{
//		if (fdf->control->prev_x == 0)
//			fdf->control->prev_x = x;
//		if (fdf->control->prev_y == 0)
//			fdf->control->prev_y = y;
//		if (fdf->control->key_shift == FALSE && fdf->control->key_ctrl == FALSE)
//		{
//			fdf->angle_y -= ANGLE_STEP * (x - fdf->control->prev_x) / 10;
//			fdf->angle_x -= ANGLE_STEP * (y - fdf->control->prev_y) / 10;
//			fdf->control->prev_x = x;
//			fdf->control->prev_y = y;
//		}
//		else
//			fdf_mouse_move_modificator(x, y, frc);
//		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
//		fdf_points_copy(fdf);
//		fdf_evaluate(fdf);
//		fdf_center_image(fdf);
//		fdf_plot_image(fdf);
//	}
	return (0);
}