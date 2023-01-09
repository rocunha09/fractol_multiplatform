/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:07:18 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 17:46:22 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	close_win(struct s_vars *v)
{
	mlx_clear_window(v->mlx, v->win);
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

int	move_or_close(int keycode, struct s_vars *v)
{
	static double	atual_x_position;
	static double	atual_y_position;
	t_vars			temp;

	mlx_clear_window(v->mlx, v->win);
	if (keycode == ESC)
		close_win(v);
	else if (keycode == DOWN)
		atual_y_position = v->y_increment - (STEP_MOVE / 10);
	else if (keycode == UP)
		atual_y_position = v->y_increment + (STEP_MOVE / 10);
	else if (keycode == RIGHT)
		atual_x_position = v->x_increment + (STEP_MOVE / 10);
	else if (keycode == LEFT)
		atual_x_position = v->x_increment - (STEP_MOVE / 10);
	v->y_increment = atual_y_position;
	v->x_increment = atual_x_position;
	draw_scene(&(*v));
	return (0);
}
