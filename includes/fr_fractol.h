/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/04/27 17:07:57 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "../includes/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define DEFAULT_COLOR		0xFF6b6b
# define TEXT_COLOR			0x00cdcd
# define WINDOW_H			1400
# define WINDOW_W			1800
# define START_SCALE		200
# define MAX_ITERATIONS		100
# define STEP_X				10000
# define STEP_Y				1000

# define MANDELBROT			1
# define JULIA				2
# define TURTLE				3
# define ISLAND				4
# define EXPLANATION		5

# define KEYBOARD			1
# define MOUSE				2

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_BUTTON_MID	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define KEY_ESC			53
# define KEY_CTRL_LEFT		256
# define KEY_SHIFT_LEFT		257
# define KEY_F				3
# define KEY_H				4
# define KEY_S				1
# define KEY_Z				6
# define KEY_X				7
# define KEY_I				34
# define KEY_T				17
# define KEY_E				14
# define KEY_R				15
# define KEY_G				5
# define KEY_B				11
# define KEY_Q				12
# define KEY_W				13
# define KEY_SPACE			49
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_NUM_1			83
# define KEY_NUM_2			84
# define KEY_NUM_3			85
# define KEY_NUM_4			86
# define KEY_NUM_6			88
# define KEY_NUM_7			89
# define KEY_NUM_8			91
# define KEY_NUM_9			92
# define KEY_NUM_UP			126
# define KEY_NUM_DOWN		125
# define KEY_NUM_LEFT		123
# define KEY_NUM_RIGHT		124

typedef struct		s_points
{
	int 			x;
	int 			y;
	double 			r;
	double 			i;
	int 			iterations;
	int				color;
}					t_points;

typedef struct		s_control
{
	int 			mouse_left_button;
}					t_control;

typedef struct		s_service
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	char			*map_name;
	int				bpp;
	int				endian;
	int				s_line;
}					t_service;

typedef struct		s_fractol
{
	u_int8_t		type;
	int 			clean_window;

//	double			angle_x;
//	double			angle_y;
//	double			angle_z;

//	int				coeff_z;
//	int				width;
//	int				height;
//	int				color_shift;
//	int				color_height;
//	double			max_z;
//	double			min_z;

	int 			number_x;
	int 			number_y;
	double			coeff_x;
	double			coeff_y;
	double			scale;
	t_points		*pts;
	t_service		*svc;
	t_control		*ctrl;
//	t_curr			*current;
//	t_control		*control;
//	t_point			*points_mem;
//	t_point			*points_out;
}					t_fractol;

int 		fr_read(int argc, char **argv, t_fractol *fractol);
int 		fr_analyse_fractal(char *fractal, t_fractol *fractol);
void 		fr_init_fractol(t_fractol *fractol);
void		fr_set_pixel(t_fractol frc, int i);
void		fr_set_pixel2(t_fractol frc, int x, int y, int color);
void		fr_plot_image(t_fractol *fractol);
void		fr_evaluate(t_fractol *frc);
void		fr_scale_image(int mode, int keycode, t_fractol *frc);
void		fr_julia(t_fractol *frc);
void		fr_mandelbrot(t_fractol *frc);
void		fr_explanation(t_fractol *frc);
int			fr_keyboard_press(int keycode, t_fractol *frc);
int			fr_keyboard_key_check(int keycode);
int			fr_keyboard_release(int keycode, t_fractol *frc);
int			fr_mouse_press(int button, int x, int y, t_fractol *frc);
int			fr_mouse_release(int button, int x, int y, t_fractol *frc);
int			fr_mouse_move(int x, int y, t_fractol *frc);
void		fr_info(t_fractol *frc);
int			fr_close(void *param);
int 		fr_color(t_fractol *fractol, int n);


#endif
