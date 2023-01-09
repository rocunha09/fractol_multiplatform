/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:53:43 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/09 10:54:21 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

static void	calc_pos(struct s_vars **v, double pixel_size, int x, int y)
{
	(*v)->z.re = ((*v)->re_min + (x * pixel_size) * 1 + (*v)->x_increment)
		* (*v)->scale;
	(*v)->z.im = ((*v)->im_max - (y * pixel_size) * 1 + (*v)->y_increment)
		* (*v)->scale;
}

void	julia(struct s_vars **v, double pixel_size, int x, int y)
{
	int		n;
	int		color;
	double	t;

	calc_pos(&(*v), pixel_size, x, y);
	n = 0;
	while (n < NMAX)
	{
		if (((*v)->z.re * (*v)->z.re + (*v)->z.im * (*v)->z.im) > 4.0)
			break ;
		t = (*v)->z.re * (*v)->z.re - (*v)->z.im * (*v)->z.im;
		(*v)->z.im = 2 * (*v)->z.re * (*v)->z.im + (*v)->c.im;
		(*v)->z.re = t + (*v)->c.re;
		n++;
	}
	t = (double)n / NMAX;
	color = calculate_raw_color(t);
	my_mlx_pixel_put((*v), x, y, color);
}
