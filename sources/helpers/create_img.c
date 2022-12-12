

#include "../../includes/fractol.h"


void create_img(t_vars *vars)
{
    vars->img = mlx_new_image(vars->mlx, WIN_WIDTH * 2, WIN_HEIGHT * 2);
    vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
    				&vars->line_length,	&vars->endian);
}
