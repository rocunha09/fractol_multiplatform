/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:50:12 by big               #+#    #+#             */
/*   Updated: 2022/11/19 15:38:59 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

# define CLOSE_BTN 17
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define IN 61
# define OUT 45
# define INN 65451
# define OUTT 65453
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_SCROLL_BTN 2
# define MOUSE_BTN_LEFT 1
# define MOUSE_BTN_RIGHT 3

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define NMAX 80
# define STEP 1

typedef struct s_complex {
	double	re;
	double	im;
}			t_complex;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_position;
	int		y_position;
	double		scale;
	double	x_increment;
	double	y_increment;
	double 	re_min;
	double 	re_max;
	double	im_min;
	double 	im_max;
}				t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	draw_scene(t_vars *vars);
void		move(int keycode, t_vars *vars);
int		close_win(t_vars *vars);
void		mouse(int keycode, int x, int y,  t_vars *vars);
void		mouse_zoom(int keycode, t_vars *vars);
void		keyboard_zoom(int keycode, t_vars *vars);

void	validate_and_filter_args(t_vars *v, int argc, char **argv);
void	create_img(t_vars *vars);

t_complex	complex_pow2(t_complex z);
t_complex	complex_add(t_complex z1, t_complex z2);
double		complex_norm(t_complex z);

int	color_get_trgb(int t, int r, int g, int b);
int	color_bernstein_polynomials1(double t);
int	color_get_t(int trgb);
int	color_get_r(int trgb);
int	color_get_g(int trgb);
int	color_get_b(int trgb);

#endif
