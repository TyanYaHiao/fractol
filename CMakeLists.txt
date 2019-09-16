cmake_minimum_required(VERSION 3.13)
project(fractol)

set(CMAKE_C_STANDARD 99)

#block for Mojave:
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
add_definitions(${GCC_COMPILE_FLAGS})
link_directories(minilibx)
include_directories(includes minilibx libft src)	#тут ищет хедеры

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

#add_library (my_library STATIC|SHARED|MODULE minilibx/libmlx.a)

set(SOURCES src/main.c
			src/fr_read.c
			src/fr_close.c
			src/fr_fractol.c
			src/fr_plot_image.c
			src/fr_keyboard.c
			src/fr_mouse.c
			src/fr_evaluate.c
			src/fr_colors.c
			src/fr_info.c
			src/fr_threads.c
			src/fr_calculate.c
			src/fr_color_solid.c)

set(HEADERS includes/mlx.h
			includes/fr_fractol.h)

set(LIBMLX minilibx/libmlx.a)

add_executable(fractol ${SOURCES} ${HEADERS} ${LIBMLX})

add_subdirectory(libft)

#block for Mojave:
target_link_libraries(fractol mlx ${OPEN_GL} ${APP_KIT} libft)
