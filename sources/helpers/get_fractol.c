/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:56:57 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/09 11:57:55 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	get_fractol(t_vars **vars, double pixel_size, int x, int y)
{
	t_vars	*v;

	v = (*vars);
	if (!(ft_strncmp(v->fractol, "julia", ft_strlen(v->fractol))))
		julia(&v, pixel_size, x, y);
	if (!(ft_strncmp(v->fractol, "mandelbrot", ft_strlen(v->fractol))))
		mandelbrot(&v, pixel_size, x, y);
	if (!(ft_strncmp(v->fractol, "burning_ship", ft_strlen(v->fractol))))
		burning_ship(&v, pixel_size, x, y);
}
