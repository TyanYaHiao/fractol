/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/10 20:09:16 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_info(t_fractol *frc)
{
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 180, 20, TEXT_COLOR, "Scale:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 110, 20,
		TEXT_COLOR, ft_strcat(ft_dtoa(frc->scale / START_SCALE * 100, 0), "%"));
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 180, 40, TEXT_COLOR, "    x:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 110, 40,
		TEXT_COLOR, ft_itoa(frc->ctrl->x));
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 180, 60, TEXT_COLOR, "    y:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 110, 60,
		TEXT_COLOR, ft_itoa(frc->ctrl->y));
}

