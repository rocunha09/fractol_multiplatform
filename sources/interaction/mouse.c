/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:46:34 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 17:47:30 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	zoom_or_close(int keycode, int x, int y, struct s_vars *v)
{
	static double	atual_scale;

	mlx_clear_window(v->mlx, v->win);
	if (keycode == CLOSE_BTN)
		close_win(v);
	if (keycode == MOUSE_SCROLL_DOWN)
		atual_scale = v->scale + (STEP_ZOOM / 10);
	else if (keycode == MOUSE_SCROLL_UP)
		atual_scale = v->scale - (STEP_ZOOM / 10);
	v->scale = atual_scale;
	draw_scene(&(*v));
	return (0);
}
