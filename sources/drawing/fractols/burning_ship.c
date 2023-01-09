/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:51:17 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/09 10:53:21 by rafade-o         ###   ########.fr       */
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

void	burning_ship(struct s_vars **v, double pixel_size, int x, int y)
{
	int		n;
	int		color;
	double	t;

	(*v)->im_max = 2.0;
	(*v)->re_min = -2.0;
	calc_pos(&(*v), pixel_size, x, y);
	n = 0;
	while (n < NMAX)
	{
		if (((*v)->z.re * (*v)->z.re + (*v)->z.im * (*v)->z.im) > 4.0)
			break ;
		(*v)->z.re = fabs((*v)->z.re);
		(*v)->z.im = fabs((*v)->z.im);
		t = -2 * (*v)->z.re * (*v)->z.im + (*v)->c.im;
		(*v)->z.re = (*v)->z.re * (*v)->z.re - (*v)->z.im * (*v)->z.im
			+ (*v)->c.re;
		(*v)->z.im = t;
		n++;
	}
	t = (double)n / NMAX;
	color = calculate_raw_color(t);
	my_mlx_pixel_put((*v), x, y, color);
}
