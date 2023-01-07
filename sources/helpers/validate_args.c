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

int is_valid_fractol(char *name, char *input)
{
	if (!ft_strncmp(name, input, ft_strlen(input)) &&
		(ft_strlen(name) == ft_strlen(input)))
		return (1);
	return (0);
}

int	validate_and_filter_args(t_vars *v, int argc, char **argv)
{
	v->a = 0.0;
	v->b = 0.0;
	if (argc >= 2 && argc <= 4)
	{
		if (is_valid_fractol("julia", argv[1]) && argc == 4)
		{
			if ((ft_atod(argv[2]) >= -2.0 && ft_atod(argv[2]) <= 2.0) &&
				(ft_atod(argv[3]) >= -2.0 && ft_atod(argv[3]) <= 2.0))
			{
				v->fractol =  argv[1];
				v->c.re = ft_atod(argv[2]);
				v->c.im = ft_atod(argv[3]);
				return (1);				
			}
		}
		else if ((is_valid_fractol("mandelbrot", argv[1]) ||
			is_valid_fractol("burning_ship", argv[1])) && (argc < 3))
		{
			v->fractol = argv[1];
			return (1);
		}
	}
	return (0);
}