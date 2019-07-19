/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:57:33 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/19 21:40:46 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int				main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!(fr_read(argc, argv, &fractol)))
		return (0);
	fr_plot_image(&fractol);
	mlx_hook(fractol.svc->win_ptr, 4, 0, fr_mouse_press, &fractol);
	mlx_hook(fractol.svc->win_ptr, 5, 0, fr_mouse_release, &fractol);
	mlx_hook(fractol.svc->win_ptr, 6, 0, fr_mouse_move, &fractol);
	mlx_hook(fractol.svc->win_ptr, 17, 0, fr_close, 0);
	mlx_hook(fractol.svc->win_ptr, 2, 0, fr_keyboard_press, &fractol);
//	mlx_hook(fractol.svc->win_ptr, 3, 0, fr_keyboard_release, &fractol);
	mlx_loop(fractol.svc->mlx_ptr);
	return (0);
}
