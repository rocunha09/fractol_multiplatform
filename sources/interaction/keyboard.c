//header

#include "../../includes/fractol.h"

int	close_win(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	move_or_close(int keycode, t_vars *vars)
{
	t_vars temp;
	double step;
	static double atual_x_position;
	static double atual_y_position;
	
	step = 2;
	if (keycode == ESC)
		close_win(vars);
	else if (keycode == UP)
		atual_y_position = vars->y_increment - (step / 10);
    else if (keycode == DOWN)
		atual_y_position = vars->y_increment + (step / 10);
    else if (keycode == LEFT)
		atual_x_position = vars->x_increment + (step / 10);
    else if (keycode == RIGHT)
		atual_x_position = vars->x_increment - (step / 10);
	vars->x_increment = atual_x_position;
	vars->y_increment = atual_y_position;
	draw_scene(&(*vars));
}
