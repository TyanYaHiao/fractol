/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:21:17 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 19:26:46 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int 	fr_color_calc_mandelbrot(t_color color, t_point n, t_point c)
{
	int	i;
	t_point temp;

	i = 0;

	//	Исследование точки на стабильность
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
		temp.r = n.r * n.r - n.i * n.i + c.r;
		temp.i = 2 * n.r * n.i + c.i;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return(color.stable);
	else
		return(color.unstable[i]);
}

int 	fr_color_calc_burning_ship(t_color color, t_point n, t_point c)
{
	int	i;
	t_point temp;

	i = 0;

	//	Исследование точки на стабильность
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
		temp.r = n.r * n.r - n.i * n.i + c.r;
		temp.i = 2 * ft_abs_double(n.r * n.i) + c.i;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return(color.stable);
	else
		return(color.unstable[i]);
}
