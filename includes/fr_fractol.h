/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/13 19:08:48 by fsmith           ###   ########.fr       */
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
# include <pthread.h>

# define BYTES_SIZE			10

# define DEFAULT_COLOR		0xFF6b6b
# define TEXT_COLOR			0x00cdcd
# define RED				0xFF0000
# define ORANGE				0xFF4500
# define YELLOW				0xFFFF00
# define GREEN				0x228B22
# define TEAL				0x00FFFF
# define BLUE				0x0000FF
# define PURPLE				0x8A2BE2

# define WINDOW_H			500
# define WINDOW_W			700
# define START_SCALE		200
# define MAX_ITERATIONS		0xFF
# define THREADS			16
# define STEP_X				100
# define STEP_Y				100

# define MANDELBROT			1
# define JULIA				2
# define TURTLE				3
# define ISLAND				4
# define BURNING_SHIP		5
# define EXPLANATION		6

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

typedef struct		s_point
{
	double 			r;
	double 			i;
}					t_point;

/*
**	Структура для управления
*/
typedef struct		s_control
{
	int 			mouse_left_button;
	int 			mouse_right_button;
	int 			prev_x;
	int 			prev_y;
	int 			x;
	int 			y;
	t_point			c;
}					t_control;

/*
**	Структура с сервисной информацией
*/
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

typedef struct		s_color
{
	int 			stable;
	int 			shift;
	int 			*unstable;
	int				counter;
}					t_color;

/*
**	Основная структура со всей информацией
**	по фракталу
*/
typedef struct		s_fractol
{
	u_int8_t		type;
	int 			offset_x;
	int 			offset_y;
	double			scale;
	t_service		*svc;
	t_control		*ctrl;
	t_color			*clr;
}					t_fractol;

/*
**	Структура для параллельных вычислений
*/
typedef struct		s_tdata
{
	int 			start_x;
	int 			end_x;
	t_fractol		*frc;
}					t_tdata;

int 		fr_read(int argc, char **argv, t_fractol *fractol);
int 		fr_analyse_fractal(char *fractal, t_fractol *fractol);
char		*fr_convert_name(int type);
void 		fr_init_fractol(t_fractol *fractol);
void		fr_set_pixel(t_fractol frc, int x, int y, int color);
void		fr_plot_image(t_fractol *fractol);
void		fr_evaluate(t_fractol *frc);
void*		fr_thread_julia(void* thread_data);
void*		fr_thread_mandelbrot(void* thread_data);
void*		fr_thread_burning_ship(void* thread_data);
void		fr_scale_image(int mode, int keycode, t_fractol *frc, int x, int y);
int			fr_keyboard_press(int keycode, t_fractol *frc);
int 		fr_move(int keycode, t_fractol *frc);
int			fr_keyboard_key_check(int keycode);
int			fr_keyboard_release(int keycode, t_fractol *frc);
int			fr_mouse_press(int button, int x, int y, t_fractol *frc);
int			fr_mouse_release(int button, int x, int y, t_fractol *frc);
int			fr_mouse_move(int x, int y, t_fractol *frc);
void		fr_info(t_fractol *frc);
int			fr_close(void *param);
int 		fr_color(t_fractol *fractol, int n);
void		fr_move_to_center(t_fractol *frc);
int 		fr_color_calc_mandelbrot(t_color color, t_point n, t_point c);
int 		fr_color_calc_burning_ship(t_color color, t_point n, t_point c);
int 		fr_random_color(t_fractol *frc);
void		fr_rainbow_color(t_fractol *frc);
void		fr_solid_color(t_fractol *frc);
int			fr_random_number();

#endif
