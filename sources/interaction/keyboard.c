//header

#include "../../includes/fractol.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	move(int keycode, t_vars *vars)
{
	t_vars temp;
	double step = 2;
	static double atual_x_position;
	static double atual_y_position;
	mlx_clear_window(vars->mlx, vars->win);
	//mlx_destroy_image(vars->mlx, vars->img);
	//create_img(vars);
	if (keycode == ESC)
	{
		printf("close!\n");
		close_win(vars);
	}
	else if (keycode == UP)
	{
		printf("up!\n");
		atual_y_position = vars->y_increment - (step / 10);
		vars->y_increment = atual_y_position;
		//draw_scene(&(*vars));
	}
    else if (keycode == DOWN)
	{
		printf("down!\n");
		atual_y_position = vars->y_increment + (step / 10);
		vars->y_increment = atual_y_position;
		//draw_scene(&(*vars));
	}
    else if (keycode == LEFT)
	{
		printf("left!\n");
		atual_x_position = vars->x_increment + (step / 10);
		vars->x_increment = atual_x_position;
		//draw_scene(&(*vars));
	}
    else if (keycode == RIGHT)
	{
		printf("right!\n");
		atual_x_position = vars->x_increment - (step / 10);
		vars->x_increment = atual_x_position;
		//draw_scene(&(*vars));
	}
	draw_scene(&(*vars));
}
