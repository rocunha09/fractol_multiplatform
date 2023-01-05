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
# include "./keys.h"
# include "./mlx.h"
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define NMAX 256
# define STEP_MOVE 2.0f
# define STEP_ZOOM 1.0f

typedef struct s_atod_vars {
	int i;
    double nbr;
    int signal;
    int dot_pos;
}	t_atod_vars;

typedef struct s_draw_vars {
	int	x;
	int	y;
	int n;
	int color;
	double t;
	double pixel_size;
}	t_draw_vars;


typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

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
	char 	*fractol;
	double	a;
	double	b;
	t_complex	c;
	t_complex	z;
	int			interations;
}				t_vars;

int is_valid_fractol(char *name, char *input);

t_atod_vars	new_atod_vars();
t_draw_vars new_draw_vars(double re_max, double re_min);
int		valid_args(t_vars *v, int argc, char **argv, char *name);
int		validate_and_filter_args(t_vars *v, int argc, char **argv);
double	ft_atod(char *str);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	print_information_to_user(void);
void	create_img(t_vars *vars);

void	get_fractol(t_vars *v, double pixel_size, int x, int y);
void	julia(t_vars *v, double pixel_size, int x, int y);
void	mandelbrot(t_vars *v, t_draw_vars *vars);
void	burning_ship(t_vars *v, double pixel_size, int x, int y);

void	draw_scene(t_vars *vars);
void	move_or_close(int keycode, t_vars *vars);
void	zoom_or_close(int keycode, int x, int y,  t_vars *vars);
int		close_win(t_vars *vars);

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
