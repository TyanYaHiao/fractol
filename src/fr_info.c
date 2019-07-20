/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/20 20:38:57 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_info(t_fractol *frc)
{
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		20, WINDOW_H - 30, TEXT_COLOR, "Help:     <H>");
	if (frc->ctrl->help)
	{
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			20, WINDOW_H - 130, TEXT_COLOR, "Colors:");
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			20, WINDOW_H - 110, TEXT_COLOR, "Solid:    <Z>");
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			20, WINDOW_H - 90, TEXT_COLOR, "Gradient: <X>");
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			20, WINDOW_H - 70, TEXT_COLOR, "Random:   <C>");
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			20, WINDOW_H - 50, TEXT_COLOR, "Rainbow:  <V>");
		mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
			200, WINDOW_H - 50, TEXT_COLOR, "To center: <SPACE>");
		if (frc->type == RANDOM)
		{
			mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
				200, WINDOW_H - 70, TEXT_COLOR, "Next type: <R>");
		}
	}
}

void		fr_help_switch(t_fractol *frc)
{
	frc->ctrl->help = !frc->ctrl->help;
	fr_plot_image(frc);
}
