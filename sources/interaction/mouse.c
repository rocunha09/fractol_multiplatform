
#include "../../includes/fractol.h"

void	zoom_or_close(int keycode, int x, int y,  t_vars *v)
{
	static double atual_scale;
    
	mlx_clear_window(v->mlx, v->win);
	if (keycode == CLOSE_BTN)
		close_win(v);
	if (keycode == MOUSE_SCROLL_UP)
	{
		ft_printf("UP");
		atual_scale = v->scale + (STEP_ZOOM / 10);
	}
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		ft_printf("DOWN");
		atual_scale = v->scale - (STEP_ZOOM / 10);
	}
	v->scale = atual_scale;
	draw_scene(&(*v));
}
