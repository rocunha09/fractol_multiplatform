
#include "../../includes/fractol.h"

void	mouse(int keycode, int x, int y,  t_vars *vars)
{
    if (keycode == CLOSE_BTN)
	{
		printf("close!\n");
		close_win(vars);
	}
    else if (keycode == MOUSE_SCROLL_BTN)
	{
        printf("keycode:%i\n", keycode);
        printf("center!\n");
    }
    else if (keycode == MOUSE_BTN_LEFT)
	{
        printf("left!\n");
		
    }
    else if (keycode == MOUSE_BTN_RIGHT)
	{
        printf("right!\n");
    }
    else
    {
        mouse_zoom(keycode, vars);
    }
}

void mouse_zoom(int keycode, t_vars *vars)
{
	static double atual_scale;
	double step;

	step = 2;
	mlx_clear_window(vars->mlx, vars->win);
	//mlx_destroy_image(vars->mlx, vars->img);
	//create_img(vars);

	if (keycode == MOUSE_SCROLL_UP)
	{
		printf("IN!\n");
		atual_scale = vars->scale + (step / 10);
		vars->scale = atual_scale;
		//draw_scene(vars);
	}
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		printf("OUT!\n");
		atual_scale = vars->scale - (step / 10);
		vars->scale = atual_scale;
		//draw_scene(vars);
	}
	draw_scene(vars);
}