/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:12:52 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/05 19:44:36 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_keyboard_key_check(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_SPACE ||
		keycode == KEY_MINUS || keycode == KEY_PLUS ||
		keycode == KEY_NUM_1 || keycode == KEY_NUM_2 || keycode == KEY_NUM_3 ||
		keycode == KEY_NUM_4 || keycode == KEY_NUM_6 || keycode == KEY_NUM_7 ||
		keycode == KEY_NUM_8 || keycode == KEY_NUM_9 ||
		keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
		keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
		keycode == KEY_Z || keycode == KEY_X || keycode == KEY_T ||
		keycode == KEY_I || keycode == KEY_R || keycode == KEY_G ||
		keycode == KEY_B || keycode == KEY_Q || keycode == KEY_S ||
		keycode == KEY_F || keycode == KEY_H || keycode == KEY_W ||
		keycode == KEY_E)
		return (1);
	return (0);
}

void		fr_keyboard_key_letter(int keycode, t_fractol *frc)
{
//	if (keycode == KEY_I)
//		fdf_plot_isometry(frc);
//	if (keycode == KEY_T)
//		fdf_plot_top_view(frc);
//	if (keycode == KEY_F)
//		fdf_plot_front_view(frc);
//	if (keycode == KEY_S)
//		fdf_plot_side_view(frc);
//	if (keycode == KEY_H)
//		fdf_switch_help(frc);
//	if (keycode == KEY_Z || keycode == KEY_X)
//		fdf_change_depth(keycode, frc);
//	if (keycode == KEY_B || keycode == KEY_G || keycode == KEY_E ||
//		keycode == KEY_R || keycode == KEY_Q || keycode == KEY_W)
//		fdf_change_color(keycode, frc);
}

int			fr_keyboard_press(int keycode, t_fractol *frc)
{
	if (fr_keyboard_key_check(keycode))
	{
		if (keycode == KEY_ESC)
			exit(0);
		if (keycode == KEY_Q)
		{
			frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
			frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,
				&frc->svc->bpp,	&frc->svc->s_line, &frc->svc->endian);
			frc->clean_window = !frc->clean_window;
		}
//		mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
//		fr_keyboard_key_letter(keycode, frc);
		if (keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
			keycode == KEY_NUM_DOWN || keycode == KEY_NUM_UP)
			fr_move(keycode, frc);
		if (keycode == KEY_PLUS || keycode == KEY_MINUS)
			fr_scale_image(KEYBOARD, keycode, frc, 0, 0);
		if (keycode == KEY_SPACE)
			fr_move_to_center(frc);
//		if (keycode == KEY_NUM_1 || keycode == KEY_NUM_2 ||
//			keycode == KEY_NUM_3 || keycode == KEY_NUM_4
//			|| keycode == KEY_NUM_6 || keycode == KEY_NUM_7 ||
//			keycode == KEY_NUM_8 || keycode == KEY_NUM_9)
//			fdf_rotate(KEYBOARD, keycode, fdf);
	}
//	if (keycode == KEY_CTRL_LEFT)
//		fdf->control->key_ctrl = TRUE;
//	if (keycode == KEY_SHIFT_LEFT)
//		fdf->control->key_shift = TRUE;
	return (0);
}

int 		fr_move(int keycode, t_fractol *frc)
{
	mlx_clear_window((*frc).svc->mlx_ptr, (*frc).svc->win_ptr);
	if (keycode == KEY_NUM_LEFT)
		frc->offset_x += STEP_X;
	else if (keycode == KEY_NUM_RIGHT)
		frc->offset_x -= STEP_X;
	else if (keycode == KEY_NUM_UP)
		frc->offset_y += STEP_Y;
	else if (keycode == KEY_NUM_DOWN)
		frc->offset_y -= STEP_Y;
	fr_plot_image(frc);
}

int			fr_keyboard_release(int keycode, t_fractol *frc)
{
//	if (keycode == KEY_CTRL_LEFT)
//	{
//		frc->control->key_ctrl = FALSE;
//		frc->control->prev_y = 0;
//		frc->control->prev_x = 0;
//	}
//	if (keycode == KEY_SHIFT_LEFT)
//	{
//		frc->control->key_shift = FALSE;
//		frc->control->prev_y = 0;
//		frc->control->prev_x = 0;
//	}
	return (0);
}