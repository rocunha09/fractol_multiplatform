
#include "../../includes/fractol.h"

void	zoom_or_close(int keycode, int x, int y,  t_vars *vars)
{
	static double atual_scale;
    
	if (keycode == CLOSE_BTN)
		close_win(vars);
	if (keycode == MOUSE_SCROLL_UP)
		atual_scale = vars->scale + (STEP / 10);
	else if (keycode == MOUSE_SCROLL_DOWN)
		atual_scale = vars->scale - (STEP / 10);
	vars->scale = atual_scale;
	draw_scene(vars);
}
