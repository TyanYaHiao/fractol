/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/05 19:44:36 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_info(t_fractol *frc)
{
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 160, 10, TEXT_COLOR, "Offset");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 160, 30, TEXT_COLOR, "      x:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 30,
		TEXT_COLOR, ft_dtoa((double)(frc->offset_x)
		/ START_SCALE, 2));
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 160, 50, TEXT_COLOR, "      y:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 50,
		TEXT_COLOR, ft_dtoa((double)(frc->offset_y)
		/ START_SCALE, 2));
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
//		WINDOW_W - 160, 80, TEXT_COLOR, "Addition");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 160, 100, TEXT_COLOR, "Scale:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 100,
		TEXT_COLOR, ft_strcat(ft_dtoa(frc->scale / START_SCALE * 100, 0), "%"));
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
//		WINDOW_W - 160, 120, TEXT_COLOR, "Imagin':");
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 120,
//		TEXT_COLOR, ft_dtoa(frc->coeff_y, 2));

//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
//		WINDOW_W - 160, 140, TEXT_COLOR, "    x:");
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 140,
//		TEXT_COLOR, ft_itoa(frc->ctrl->x - WINDOW_H / 2));
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
//				   WINDOW_W - 160, 160, TEXT_COLOR, "    y:");
//	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 160,
//				   TEXT_COLOR, ft_itoa(frc->ctrl->y - WINDOW_W / 2));

	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
		WINDOW_W - 160, 140, TEXT_COLOR, "    x:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 140,
		TEXT_COLOR, ft_itoa(frc->ctrl->x));
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
				   WINDOW_W - 160, 160, TEXT_COLOR, "    y:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 160,
				   TEXT_COLOR, ft_itoa(frc->ctrl->y));

	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
				   WINDOW_W - 160, 180, TEXT_COLOR, "offset x:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 180,
				   TEXT_COLOR, ft_itoa(frc->offset_x));
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
				   WINDOW_W - 160, 200, TEXT_COLOR, "offset y:");
	mlx_string_put(frc->svc->mlx_ptr, frc->svc->win_ptr, WINDOW_W - 70, 200,
				   TEXT_COLOR, ft_itoa(frc->offset_y));
}
