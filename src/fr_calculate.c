/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:21:17 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 15:59:36 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int			fr_color_calc_mandelbrot(t_color color, t_point n, t_point c)
{
	int		i;
	t_point	temp;

	i = 0;
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
		temp.r = n.r * n.r - n.i * n.i + c.r;
		temp.i = 2 * n.r * n.i + c.i;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return (color.stable);
	else
		return (color.unstable[i]);
}

int			fr_color_calc_burning_ship(t_color color, t_point n, t_point c)
{
	int		i;
	t_point	temp;

	i = 0;
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= 4)
	{
		temp.r = n.r * n.r - n.i * n.i + c.i;
		temp.i = 2 * ft_abs_double(n.r * n.i) + c.r;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return (color.stable);
	else
		return (color.unstable[i]);
}

int			fr_color_calc_random_fractol(t_coeff cff, t_color color,
										t_point n, t_point c)
{
	int		i;
	t_point	temp;

	i = 0;
	while (i < MAX_ITERATIONS && (n.r * n.r * 0.95 + n.i * n.i) <= cff.c1)
	{
		temp.r = cff.r1 * n.r * n.r + cff.r2 * n.i * n.i + cff.r3 * c.i;
		if (cff.abs)
			temp.i = cff.i1 * ft_abs_double(n.r * n.i) + cff.i2 * c.r;
		else
			temp.i = cff.i1 * n.r * n.i + cff.i2 * c.r;
		n.r = temp.r;
		n.i = temp.i;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return (color.stable);
	else
		return (color.unstable[i]);
}
