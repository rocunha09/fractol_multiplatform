//header

#include "../../includes/fractol.h"

void draw_scene(t_vars *vars)
{
    int	x;
	int	y;
	int n;
	int color;
	float t;
	double pixel_size;
	t_complex c;
	t_complex z;

	vars->re_min = -2.00f;
	vars->re_max = 2.00f;
	vars->im_min = -2.00f;
	vars->im_max = 2.00f;
    pixel_size = (vars->re_max - vars->re_min) / WIN_WIDTH;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{										    //deste ponto em diante refere-se a movimento e zoom	
			c.re = (vars->re_min + (x * pixel_size) * 1 + vars->x_increment) * vars->scale; 
			c.im = (vars->im_max - (y * pixel_size) * 1 + vars->y_increment) * vars->scale;
			z.re = 0.0f;
			z.im = 0.0f;
			n = 1;
			while (n < NMAX)
			{
				if ((complex_norm(z) * complex_norm(z)) > 4)
					break;
				z = complex_add(complex_pow2(z), c);
				n++;
			}
				t = (float)n / NMAX;
				color = color_bernstein_polynomials1(t);
                my_mlx_pixel_put(&(*vars), x, y, color);
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}