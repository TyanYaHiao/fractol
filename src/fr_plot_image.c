/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_plot_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:52:39 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/21 17:56:50 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fr_fractol.h"

void		fr_set_pixel(t_fractol frc, int i)
{
	int 	*tmp;

	tmp = (int*)frc.svc->image;
	if (frc.pts[i].x >= 0 && frc.pts[i].x <= WINDOW_W
	&& frc.pts[i].y >= 0 && frc.pts[i].y <= WINDOW_H)
		tmp[WINDOW_W * frc.pts[i].y + frc.pts[i].x] = frc.pts[i].color;
}

void		fdf_set_line(t_fractol field, int start, int end)
{
//	double	err;
//	double	e2;
//
//	fdf_init_curr(field, start, end);
//	err = -(field.current->dy) / 2;
//	if (field.current->dx > field.current->dy)
//		err = field.current->dx / 2;
//	while (field.current->x != END_POINT.x || field.current->y != END_POINT.y)
//	{
//		if (field.current->x >= 0 && field.current->x < WINDOW_W
//			&& field.current->y >= 0 && field.current->y < WINDOW_H)
//			*(int*)(field.image + (int)field.current->x * 4 +
//			(int)field.current->y * field.s_line) = color(field, start, end);
//		e2 = err;
//		if (e2 > -(field.current->dx))
//		{
//			err -= field.current->dy;
//			field.current->x += field.current->sx;
//		}
//		if (e2 < field.current->dy)
//		{
//			err += field.current->dx;
//			field.current->y += field.current->sy;
//		}
//	}
}

//void		fr_plot_image(t_fractol *frc)
//{
//	int		i;
//
//	fr_evaluate(frc);
//	mlx_clear_window(frc->svc->mlx_ptr, frc->svc->win_ptr);
//	frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
//	frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr, &frc->svc->bpp,
//										&frc->svc->s_line, &frc->svc->endian);
////	i = 0;
////	while (i++ < frc->width * frc->height)
//	mlx_pixel_put(frc->svc->mlx_ptr, frc->svc->win_ptr,
//				  (int)50, (int)50, DEFAULT_COLOR);
////		if (i % (frc->width * frc->height) != 0)
////		{
////			if ((frc->height) * (frc->width) - i < frc->width)
////				fdf_set_line(*frc, i, i + 1);
////			else if ((i % (frc->width)) == 0 && i != 0)
////				fdf_set_line(*frc, i, i + frc->width);
////			else
////			{
////				fdf_set_line(*frc, i, i + frc->width);
////				fdf_set_line(*frc, i, i + 1);
////			}
////		}
//	mlx_put_image_to_window(frc->svc->mlx_ptr, frc->svc->win_ptr,
//							frc->svc->img_ptr, 0, 0);
//	mlx_destroy_image(frc->svc->mlx_ptr, frc->svc->img_ptr);
////	fdf_field_info(*frc);
//}

void		fr_plot_image(t_fractol *frc)
{
	int		i;

	i = 0;

	fr_evaluate(frc);
	mlx_clear_window(frc->svc->mlx_ptr, frc->svc->win_ptr);
	if (frc->clean_window)
	{
		frc->svc->img_ptr = mlx_new_image(frc->svc->mlx_ptr, WINDOW_W, WINDOW_H);
		frc->svc->image = mlx_get_data_addr(frc->svc->img_ptr,
			&frc->svc->bpp,	&frc->svc->s_line, &frc->svc->endian);
	}
	while (i < 100)
	{
		fr_set_pixel(*frc, i);
		i++;
	}
	mlx_put_image_to_window(frc->svc->mlx_ptr, frc->svc->win_ptr,
							frc->svc->img_ptr, 0, 0);
	if (frc->clean_window)
	{
		mlx_destroy_image(frc->svc->mlx_ptr, frc->svc->img_ptr);
	}
	fr_info(frc);
}