/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:12:52 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_keyboard_key_check(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_SPACE ||
		keycode == KEY_MINUS || keycode == KEY_PLUS ||
		keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
		keycode == KEY_NUM_UP || keycode == KEY_NUM_DOWN ||
		keycode == KEY_Z || keycode == KEY_X ||
		keycode == KEY_R || keycode == KEY_H ||
		keycode == KEY_C || keycode == KEY_V)
		return (1);
	return (0);
}

int			fr_keyboard_press(int keycode, t_fractol *frc)
{
	if (fr_keyboard_key_check(keycode))
	{
		if (keycode == KEY_ESC)
			exit(0);
		if (keycode == KEY_NUM_LEFT || keycode == KEY_NUM_RIGHT ||
			keycode == KEY_NUM_DOWN || keycode == KEY_NUM_UP)
			fr_move(keycode, frc);
		if (keycode == KEY_PLUS || keycode == KEY_MINUS)
			fr_scale_image(keycode, frc, WINDOW_W / 2, WINDOW_H / 2);
		if (keycode == KEY_SPACE)
			fr_move_to_center(frc);
		if (keycode == KEY_C)
			fr_random_color(frc);
		if (keycode == KEY_V)
			fr_rainbow_color(frc);
		if (keycode == KEY_Z)
			fr_solid_color(frc);
		if (keycode == KEY_R && frc->type == RANDOM)
			fr_random_fractol(frc);
		if (keycode == KEY_X)
			fr_gradient_color(frc);
		if (keycode == KEY_H)
			fr_help_switch(frc);
	}
	return (0);
}

int			fr_move(int keycode, t_fractol *frc)
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
	return (0);
}
