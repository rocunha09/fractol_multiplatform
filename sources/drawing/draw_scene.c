//header

#include "../../includes/fractol.h"

void draw_scene(t_vars *vars)
{
    int	 x, y;
	t_complex c;
	t_complex z;
	int n;
	int color;
	float t;

    vars->re_min = -1.50f;
	vars->re_max = 1.50f;
	vars->im_max = 1.50f;
    double pixel_size = (vars->re_max - vars->re_min) / WIN_WIDTH;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
            /*INICIO DO CALCULO DE MANDELBROT*/
			/*QUANDO COLOQUEI O ZOOM, O DIRECIONAMENTO PAROU DE FUNCIONAR*/
			c.re = vars->re_min + (x * pixel_size) * 1 + vars->x_increment;// * vars->scale; 
			c.im = vars->im_max - (y * pixel_size) * 1 + vars->y_increment;// * vars->scale;
			z.re = 0.0f;
			z.im = 0.0f;
			n = 1;
			while (n < NMAX)
			{
				if (complex_norm(z) > 2)
					break;
				z = complex_add(complex_pow2(z), c);
				n++;
			}
            /*FINAL DO CALCULO DE MANDELBROT*/

            /*ACHO QUE ESSE IF DESENHA O PLANO CARTEZIANO NA TELA EM VERMELHO*/
			if (c.re == 0.0f || c.im == 0.0f) // draw axis after convert from pixels to point
                my_mlx_pixel_put(&(*vars), x, y, 0x00FF0000);
			else 
			{ // color using smooth pallete
				t = (float)n / NMAX;
				color = color_bernstein_polynomials1(t);
                my_mlx_pixel_put(&(*vars), x, y, color);
			}
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}