cmake_minimum_required(VERSION 3.13)
project(fractol)

set(CMAKE_C_STANDARD 99)

#block for Mojave:
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
add_definitions(${GCC_COMPILE_FLAGS})
link_directories(minilibx)
include_directories(includes minilibx)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

#add_library (my_library STATIC|SHARED|MODULE minilibx/libmlx.a)

add_executable(fractol
		minilibx/libmlx.a
		includes/mlx.h
		includes/fr_fractol.h
		libft/libft.h
		libft/ft_abs.c
		libft/ft_atoi.c
		libft/ft_atoi_hex.c
		libft/ft_bzero.c
		libft/ft_count_words.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isascii.c
		libft/ft_isdigit.c
		libft/ft_isprint.c
		libft/ft_itoa.c
		libft/ft_itoalen.c
		libft/ft_lstadd.c
		libft/ft_lstdel.c
		libft/ft_lstdelone.c
		libft/ft_lstiter.c
		libft/ft_lstmap.c
		libft/ft_lstnew.c
		libft/ft_memalloc.c
		libft/ft_memccpy.c
		libft/ft_memchr.c
		libft/ft_memcmp.c
		libft/ft_memcpy.c
		libft/ft_memdel.c
		libft/ft_memmove.c
		libft/ft_memset.c
		libft/ft_putchar.c
		libft/ft_putchar_fd.c
		libft/ft_putendl.c
		libft/ft_putendl_fd.c
		libft/ft_putnbr.c
		libft/ft_putnbr_fd.c
		libft/ft_putstr.c
		libft/ft_putstr_fd.c
		libft/ft_strcat.c
		libft/ft_strchr.c
		libft/ft_strchrn.c
		libft/ft_strclr.c
		libft/ft_strcmp.c
		libft/ft_strcpy.c
		libft/ft_strdel.c
		libft/ft_strdup.c
		libft/ft_strequ.c
		libft/ft_striter.c
		libft/ft_striteri.c
		libft/ft_strjoin.c
		libft/ft_strlcat.c
		libft/ft_strlen.c
		libft/ft_strmap.c
		libft/ft_strmapi.c
		libft/ft_strncat.c
		libft/ft_strncmp.c
		libft/ft_strncpy.c
		libft/ft_strnequ.c
		libft/ft_strnew.c
		libft/ft_strnstr.c
		libft/ft_strrchr.c
		libft/ft_strsplit.c
		libft/ft_strstr.c
		libft/ft_strsub.c
		libft/ft_strtrim.c
		libft/ft_tolower.c
		libft/ft_toupper.c
		libft/ft_strcut.c
		libft/get_next_line.c
		libft/ft_sqrt_up.c
		libft/ft_power.c
		libft/ft_round_double.c
		libft/ft_abs_double.c
		src/main.c
		src/fr_read.c
		src/fr_close.c
		src/fr_fractol.c
		src/fr_plot_image.c
		src/fr_keyboard.c
		src/fr_mouse.c
		src/fr_evaluate.c
		src/fr_colors.c src/fr_info.c libft/ft_dtoa.c)

#block for Mojave:
target_link_libraries(fractol mlx ${OPEN_GL} ${APP_KIT})