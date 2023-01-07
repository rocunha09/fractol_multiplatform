//header

#include "../../includes/fractol.h"

int	close_win(struct s_vars *v)
{
	mlx_clear_window(v->mlx, v->win);
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

void	move_or_close(int keycode, struct s_vars *v)
{
	t_vars temp;
	static double atual_x_position;
	static double atual_y_position;
	
	mlx_clear_window(v->mlx, v->win);
	if (keycode == ESC)
		close_win(v);
	else if (keycode == UP)
		atual_y_position = v->y_increment - (STEP_MOVE / 10);
    else if (keycode == DOWN)
		atual_y_position = v->y_increment + (STEP_MOVE / 10);
    else if (keycode == RIGHT)
		atual_x_position = v->x_increment + (STEP_MOVE / 10);
    else if (keycode == LEFT)
		atual_x_position = v->x_increment - (STEP_MOVE / 10);
	v->y_increment = atual_y_position;
	v->x_increment = atual_x_position;
	draw_scene(&(*v));
}
