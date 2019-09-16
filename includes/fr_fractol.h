/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:57:26 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_FRACTOL_H
# define FR_FRACTOL_H
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
# define YELLOW				0xFFD700
# define GREEN				0x228B22
# define TEAL				0x00FFFF
# define BLUE				0x0000FF
# define PURPLE				0x8A2BE2
# define SOLID_COLORS		7
# define COLOR_DIVIDER		20

# define WINDOW_H			500
# define WINDOW_W			700
# define START_SCALE		200
# define MAX_ITERATIONS		0xFF
# define THREADS			16
# define STEP_X				100
# define STEP_Y				100

# define OFF				0
# define ON					1

# define MANDELBROT			1
# define JULIA				2
# define BUTTERFLY			3
# define BURNING_SHIP		4
# define RANDOM				5

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
# define KEY_H				4
# define KEY_Z				6
# define KEY_X				7
# define KEY_R				15
# define KEY_C				8
# define KEY_V				9
# define KEY_SPACE			49
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_NUM_UP			126
# define KEY_NUM_DOWN		125
# define KEY_NUM_LEFT		123
# define KEY_NUM_RIGHT		124

typedef struct	s_point
{
	double		r;
	double		i;
}				t_point;

/*
**	Структура для управления
*/
typedef struct	s_control
{
	int			mouse_left_button;
	int			mouse_right_button;
	int			prev_x;
	int			prev_y;
	int			x;
	int			y;
	int			help;
	t_point		c;
}				t_control;

typedef struct	s_coeff
{
	int			c1;
	int			color;
	int			r1;
	int			r2;
	int			r3;
	int			abs;
	double		i1;
	int			i2;
}				t_coeff;

/*
**	Структура с сервисной информацией
*/
typedef struct	s_service
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*image;
	char		*map_name;
	int			bpp;
	int			endian;
	int			s_line;
}				t_service;

typedef struct	s_color
{
	int			stable;
	int			shift;
	int			*unstable;
	int			*rainbow;
}				t_color;

/*
**	Основная структура со всей информацией
**	по фракталу
*/
typedef struct	s_fractol
{
	u_int8_t	type;
	int			offset_x;
	int			offset_y;
	double		scale;
	t_service	*svc;
	t_control	*ctrl;
	t_color		*clr;
	t_coeff		*cff;
}				t_fractol;

/*
**	Структура для параллельных вычислений
*/
typedef struct	s_tdata
{
	int			start_x;
	int			end_x;
	t_fractol	*frc;
}				t_tdata;

int				fr_read(int argc, char **argv, t_fractol *fractol);
int				fr_analyse_fractal(char *fractal, t_fractol *fractol);
char			*fr_convert_name(int type);
void			fr_init_fractol(t_fractol *fractol);
void			fr_set_pixel(t_fractol frc, int x, int y, int color);
void			fr_plot_image(t_fractol *fractol);
void			fr_evaluate(t_fractol *frc);
void			fr_thread_selection(int i, t_tdata *data, pthread_t *threads);
void			*fr_thread_julia(void *thread_data);
void			*fr_thread_mandelbrot(void *thread_data);
void			*fr_thread_burning_ship(void *thread_data);
void			*fr_thread_butterfly(void *thread_data);
void			fr_scale_image(int keycode, t_fractol *frc, int x, int y);
int				fr_keyboard_press(int keycode, t_fractol *frc);
int				fr_move(int keycode, t_fractol *frc);
int				fr_keyboard_key_check(int keycode);
int				fr_mouse_press(int button, int x, int y, t_fractol *frc);
int				fr_mouse_release(int button, int x, int y, t_fractol *frc);
int				fr_mouse_move(int x, int y, t_fractol *frc);
void			fr_info(t_fractol *frc);
int				fr_close(void *param);
void			fr_move_to_center(t_fractol *frc);
int				fr_color_calc_mandelbrot(t_color color, t_point n, t_point c);
int				fr_color_calc_burning_ship(t_color color, t_point n, t_point c);
int				fr_random_color(t_fractol *frc);
void			fr_rainbow_color(t_fractol *frc);
void			fr_solid_color(t_fractol *frc);
void			fr_gradient_color(t_fractol *frc);
void			fr_solid_colors_init(t_fractol *frc);
void			fr_random_fractol(t_fractol *frc);
void			*fr_thread_random(void *thread_data);
int				fr_solid_color_gradation(int color, int i);
void			fr_new_coefficients(t_fractol *fractol);
void			fr_help_switch(t_fractol *frc);
int				fr_color_gradation(int color, int i);
int				fr_color_calc_random_fractol(t_coeff cff, t_color color,
				t_point n, t_point c);
#endif
