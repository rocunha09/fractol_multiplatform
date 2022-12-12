//header

#include "../../includes/fractol.h"

t_complex	complex_pow2(t_complex z)
{
	t_complex	result;

	result.re = pow(z.re, 2) - pow(z.im, 2);
	result.im = 2 * z.re * z.im;
	return (result);
}

t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

double	complex_norm(t_complex z)
{
	return (hypot(z.re, z.im));
}