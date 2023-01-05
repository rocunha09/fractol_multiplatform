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

void mandelbrot(t_vars **v, double pixel_size, int x, int y)
{
    int n;
    int color;
    double t;

    n = 1;
    t = 0.0;
    color = 0.0;
    
    (*v)->c.re = ((*v)->re_min + (x * pixel_size) * 1 + (*v)->x_increment) * (*v)->scale; 
    (*v)->c.im = ((*v)->im_max - (y * pixel_size) * 1 + (*v)->y_increment) * (*v)->scale;
    (*v)->z.re = 0.0;
    (*v)->z.im = 0.0;
    n = 1;
    while (n < NMAX)
    {
        if ((complex_norm((*v)->z) * complex_norm((*v)->z)) > 4)
            break;
        (*v)->z = complex_add(complex_pow2((*v)->z), (*v)->c);
        n++;
    }
    t = (double)n / NMAX;
    color = color_bernstein_polynomials1(t);
    my_mlx_pixel_put((*v), x, y, color);
}
