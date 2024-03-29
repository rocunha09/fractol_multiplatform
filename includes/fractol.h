/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:59:09 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/11 11:54:03 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "./libft/libft.h"
# include "./keys.h"
# include "./mlx.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define NMAX 256
# define STEP_MOVE 2.0
# define STEP_ZOOM 0.10

typedef struct s_atod_vars
{
	int		i;
	int		signal;
	int		dot_pos;
	double	nbr;
}	t_atod_vars;

typedef struct s_draw_vars
{
	int		x;
	int		y;
	int		n;
	int		color;
	double	t;
	double	pixel_size;
}	t_draw_vars;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_vars
{
	t_complex	c;
	t_complex	z;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x_position;
	int			y_position;
	double		scale;
	double		x_increment;
	double		y_increment;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	char		*fractol;
}	t_vars;

t_atod_vars		new_atod_vars(void);
t_draw_vars		new_draw_vars(double re_max, double re_min);
t_vars			new_t_vars(void);
void			my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void			print_information_to_user(void);
void			create_img(t_vars *vars);
void			get_fractol(t_vars **v, double pixel_size, int x, int y);
void			julia(t_vars **v, double pixel_size, int x, int y);
void			mandelbrot(t_vars **v, double pixel_size, int x, int y);
void			burning_ship(t_vars **v, double pixel_size, int x, int y);
void			draw_scene(t_vars *vars);
int				move_or_close(int keycode, t_vars *vars);
int				zoom_or_close(int keycode, int x, int y, t_vars *vars);
int				is_valid_fractol(char *name, char *input);
int				valid_args(t_vars *v, int argc, char **argv, char *name);
int				validate_and_filter_args(t_vars *v, int argc, char **argv);
int				close_win(t_vars *vars);
int				color_get_trgb(int t, int r, int g, int b);
int				calculate_raw_color(double t);
int				color_get_t(int trgb);
int				color_get_r(int trgb);
int				color_get_g(int trgb);
int				color_get_b(int trgb);
double			ft_atod(char *str);

#endif
