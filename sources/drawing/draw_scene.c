/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:54:53 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/09 10:56:47 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	draw_scene(t_vars *v)
{
	int		x;
	int		y;
	int		t;
	int		color;
	double	pixel_size;

	x = 0;
	y = 0;
	pixel_size = (v->re_max - v->re_min) / WIN_WIDTH;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			get_fractol(&v, pixel_size, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
