/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:39:51 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 17:41:28 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars	v;

	if (!validate_and_filter_args(&v, argc, &(*argv)))
	{
		print_information_to_user();
		exit(1);
	}
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol!");
	create_img(&v);
	v.re_min = -2.00;
	v.re_max = 2.00;
	v.im_min = -2.00;
	v.im_max = 2.00;
	v.scale = 1;
	v.x_increment = 0;
	v.y_increment = 0;
	draw_scene(&v);
	mlx_hook(v.win, CLOSE_BTN, 0, close_win, &v);
	mlx_key_hook(v.win, move_or_close, &v);
	mlx_mouse_hook(v.win, zoom_or_close, &v);
	mlx_loop(v.mlx);
	return (0);
}
