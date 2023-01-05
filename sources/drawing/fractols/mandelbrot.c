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

void mandelbrot(t_vars *v, t_draw_vars *vars)
{
    v->c.re =(v->re_min + (vars->x * vars->pixel_size) * 1 + v->x_increment) * v->scale; 
    v->c.im =(v->im_max - (vars->y * vars->pixel_size) * 1 + v->y_increment) * v->scale;
    v->z.re = 0.0;
    v->z.im = 0.0;
   /*    vars->n = 1;
    while (vars->n < NMAX)
    {
        if ((complex_norm(v->z) * complex_norm(v->z)) > 4)
            break;
        v->z = complex_add(complex_pow2(v->z), v->c);
        vars->n++;
    }
    v->interations = vars->n;
    */
}

//o calculo depende de n interações 
//esse n não está chegando ao draw_scene
//pelo que percebi esse while muda para cada fractal
