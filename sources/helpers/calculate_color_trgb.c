//header

#include "../../includes/fractol.h"

int	color_get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_bernstein_polynomials1(double t)
{
	int raw_color;

	raw_color = color_get_trgb(0, 
						(int)(9 * ( 1 - t ) * t * t * t  * 255),
						(int)(15 * ( 1 - t ) * t * t * 255),
						(int)(8.5 * ( 1 - t ) * t * 255)
						);
	return (raw_color % 0xFFFFFF);
	
}

/*
 Function retrieves the transparancy channel from the color
*/
int	color_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

/*
 Function retrieves the red channel from the color
*/
int	color_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

/*
 Function retrieves the green channel from the color
*/
int	color_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

/*
 Function retrieves the blue channel from the color
*/
int	color_get_b(int trgb)
{
	return (trgb & 0xFF);
}