/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:31:05 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/19 20:01:02 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

int		fr_read(int argc, char **argv, t_fractol *fractol)
{
	fractol->type = 0;
	if (argc != 2 || !(fr_analyse_fractal(argv[1], fractol)))
	{
		ft_putendl("Usage: ./fractol [fractal]");
		ft_putendl("fractals: Mandelbrot");
		ft_putendl("          Julia");
		ft_putendl("          Butterfly");
		ft_putendl("          Burning_Ship");
		ft_putendl("          Random");
		return (0);
	}
	fr_init_fractol(fractol);
	return (1);
}

int		fr_analyse_fractal(char *fractal, t_fractol *fractol)
{
	if (!(ft_strcmp(fractal, "Mandelbrot")))
		fractol->type = MANDELBROT;
	else if (!(ft_strcmp(fractal, "Julia")))
		fractol->type = JULIA;
	else if (!(ft_strcmp(fractal, "Butterfly")))
		fractol->type = BUTTERFLY;
	else if (!(ft_strcmp(fractal, "Burning_Ship")))
		fractol->type = BURNING_SHIP;
	else if (!(ft_strcmp(fractal, "Random")))
		fractol->type = RANDOM;
	else
		return (0);
	return (1);
}

char	*fr_convert_name(int type)
{
	if (type == MANDELBROT)
		return ("Mandelbrot");
	if (type == JULIA)
		return ("Julia");
	if (type == BUTTERFLY)
		return ("Butterfly");
	if (type == BURNING_SHIP)
		return ("Burning Ship");
	if (type == RANDOM)
		return ("Random fractal");
	return ("Fract'ol");
}
