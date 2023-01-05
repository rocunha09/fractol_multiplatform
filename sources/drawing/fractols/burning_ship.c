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

void burning_ship(t_vars *v, double pixel_size, int x, int y)
{
    v->c.re =(v->re_min + (x * pixel_size) * 1 + v->x_increment) * v->scale; 
    v->c.im =(v->im_max - (y * pixel_size) * 1 + v->y_increment) * v->scale;
    v->z.re = 0.0;
    v->z.im = 0.0;
}