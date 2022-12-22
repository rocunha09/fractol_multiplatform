/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:39:51 by big               #+#    #+#             */
/*   Updated: 2022/11/19 12:59:54 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//int main()
int	main(int argc, char **argv)
{
	t_vars	v;


	//validaçao de inputs
	validate_and_filter_args(&v, argc, &(*argv));
	v.mlx = mlx_init();
    v.win = mlx_new_window(v.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol!");
	create_img(&v);

	v.scale = 1;
	v.x_increment = 0;
	v.y_increment = 0;
	draw_scene(&v);

	mlx_hook(v.win, CLOSE_BTN, 0, close_win, &v);
	mlx_key_hook(v.win, move, &v);
	mlx_mouse_hook(v.win, mouse, &v);
	mlx_loop(v.mlx);
	return (0);
}
