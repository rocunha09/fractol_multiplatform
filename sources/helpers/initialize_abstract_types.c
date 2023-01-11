/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_abstract_types.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:11:59 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/11 11:11:30 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_atod_vars	new_atod_vars(void)
{
	t_atod_vars	v;

	v.i = 0;
	v.nbr = 0.0;
	v.signal = 1;
	v.dot_pos = 0;
	return (v);
}

t_draw_vars	new_draw_vars(double re_max, double re_min)
{
	t_draw_vars	v;

	v.x = 0;
	v.y = 0;
	v.n = 1;
	v.t = 0.0;
	v.color = 0.0;
	v.pixel_size = (re_max - re_min) / WIN_WIDTH;
	return (v);
}

t_vars	new_t_vars(void)
{
	t_vars	v;

	v.c.re = 0.0;
	v.c.im = 0.0;
	v.z.re = 0.0;
	v.z.im = 0.0;
	v.mlx = 0;
	v.win = 0;
	v.img = 0;
	v.addr = 0;
	v.bits_per_pixel = 0;
	v.line_length = 0;
	v.endian = 0;
	v.x_position = 0;
	v.y_position = 0;
	v.scale = 1.0;
	v.x_increment = 0;
	v.y_increment = 0;
	v.re_min = -2.00;
	v.re_max = 2.00;
	v.im_min = -2.00;
	v.im_max = 2.00;
	v.fractol = 0;
	return (v);
}
