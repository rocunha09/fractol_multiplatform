/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:51 by big               #+#    #+#             */
/*   Updated: 2022/12/30 21:42:35 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

void burning_ship(struct s_vars  **v, double pixel_size, int x, int y)
{
	int		n;
    int color;
	double	t;

    (*v)->c.re = ((*v)->re_min + (x * pixel_size) * 1 + (*v)->x_increment) * (*v)->scale; 
    (*v)->c.im = ((*v)->im_max - (y * pixel_size) * 1 + (*v)->y_increment) * (*v)->scale;
	(*v)->z.re = 0.0;
    (*v)->z.im = 0.0;
	n = 0;
	while (n < NMAX)
	{
		if (((*v)->z.re * (*v)->z.re + (*v)->z.im * (*v)->z.im) > 4.0)
			break ;
		(*v)->z.re = fabs((*v)->z.re);
		(*v)->z.im = fabs((*v)->z.im);
		t = -2 * (*v)->z.re * (*v)->z.im + (*v)->c.im;
		(*v)->z.re = (*v)->z.re * (*v)->z.re - (*v)->z.im * (*v)->z.im + (*v)->c.re;
		(*v)->z.im = t;
		n++;
	}
	t = (double)n / NMAX;
    color = color_bernstein_polynomials1(t);
    my_mlx_pixel_put((*v), x, y, color);
}
