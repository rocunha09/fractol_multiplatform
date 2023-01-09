/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_abstract_types.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:11:59 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 18:13:17 by rafade-o         ###   ########.fr       */
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
