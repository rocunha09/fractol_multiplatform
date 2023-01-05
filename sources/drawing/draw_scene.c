//header

#include "../../includes/fractol.h"

void draw_scene(t_vars *v)
{
	t_draw_vars vars;

	vars = new_draw_vars(v->re_max, v->re_min);
	vars.y = 0;
	while (vars.y < WIN_HEIGHT)
	{
		vars.x = 0;
		while (vars.x < WIN_WIDTH)
		{
			v->c.re =(v->re_min + (vars.x * vars.pixel_size) * 1 + v->x_increment) * v->scale; 
			v->c.im =(v->im_max - (vars.y * vars.pixel_size) * 1 + v->y_increment) * v->scale;
			v->z.re = 0.0;
			v->z.im = 0.0;
			vars.n = 1;
			while (vars.n < NMAX)
			{
				if ((complex_norm(v->z) * complex_norm(v->z)) > 4)
					break;
				v->z = complex_add(complex_pow2(v->z), v->c);
				vars.n++;
			}
			vars.t = (double)vars.n / NMAX;
			vars.color = color_bernstein_polynomials1(vars.t);
			my_mlx_pixel_put(&(*v), vars.x, vars.y, vars.color);
			vars.x++;
		}
		vars.y++;
	}
    mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}