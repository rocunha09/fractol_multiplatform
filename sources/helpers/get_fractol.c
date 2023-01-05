/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:51 by big               #+#    #+#             */
/*   Updated: 2022/12/30 21:42:35 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"


void	get_fractol(t_vars *v, double pixel_size, int x, int y)
{

    if (!(ft_strncmp(v->fractol, "julia", ft_strlen(v->fractol))))
        julia(&(*v), pixel_size, x, y);
    if (!(ft_strncmp(v->fractol, "mandelbrot", ft_strlen(v->fractol))))
        mandelbrot(&(*v), pixel_size, x, y);
    if (!(ft_strncmp(v->fractol, "burning_ship", ft_strlen(v->fractol))))
        burning_ship(&(*v), pixel_size, x, y);
}