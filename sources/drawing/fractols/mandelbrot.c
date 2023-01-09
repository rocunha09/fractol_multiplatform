/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:34:19 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/09 10:46:46 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

static void	calc_pos(struct s_vars **v, double pixel_size, int x, int y)
{
	(*v)->c.re = ((*v)->re_min + (x * pixel_size) * 1 + (*v)->x_increment)
		* (*v)->scale;
	(*v)->c.im = ((*v)->im_max - (y * pixel_size) * 1 + (*v)->y_increment)
		* (*v)->scale;
	(*v)->z.re = 0.0;
	(*v)->z.im = 0.0;
}

void	mandelbrot(struct s_vars **v, double pixel_size, int x, int y)
{
	int		n;
	int		color;
	double	t;

	n = 1;
	t = 0.0;
	color = 0.0;
	calc_pos(&(*v), pixel_size, x, y);
	n = 1;
	while (n < NMAX)
	{
		if (((*v)->z.re * (*v)->z.re + (*v)->z.im * (*v)->z.im) > 4.0)
			break ;
		t = (*v)->z.re;
		(*v)->z.re = (*v)->z.re * (*v)->z.re - (*v)->z.im * (*v)->z.im
			+ (*v)->c.re;
		(*v)->z.im = 2 * (*v)->z.im * t + (*v)->c.im;
		n++;
	}
	t = (double)n / NMAX;
	color = calculate_raw_color(t);
	my_mlx_pixel_put((*v), x, y, color);
}
