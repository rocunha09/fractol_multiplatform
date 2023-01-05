//header

#include "../../includes/fractol.h"

void draw_scene(t_vars *v)
{
	int x;
	int y;
	double pixel_size;
	
	x = 0;
	y = 0;
	pixel_size = (v->re_max - v->re_min) / WIN_WIDTH;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (!(ft_strncmp(v->fractol, "julia", ft_strlen(v->fractol))))
				julia(&v, pixel_size, x, y);
			if (!(ft_strncmp(v->fractol, "mandelbrot", ft_strlen(v->fractol))))
				mandelbrot(&v, pixel_size, x, y);
			if (!(ft_strncmp(v->fractol, "burning_ship", ft_strlen(v->fractol))))
				burning_ship(&v, pixel_size, x, y);
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}