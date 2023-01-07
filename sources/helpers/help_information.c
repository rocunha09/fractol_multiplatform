//header

#include "../../includes/fractol.h"

void print_information_to_user(void)
{
    ft_printf("\n------------------------------");
    ft_printf("------------------------------\n");
    ft_printf("You can use some options to execute this program.\n");
    ft_printf("\n");
    ft_printf("Execute program with name of fractol do you want to see:\n");
    ft_printf("   Ex: bash->./fractol \"mandelbrot\"\n");
    ft_printf("   Ex: bash->./fractol \"burning_ship\"\n");
    ft_printf("\n");
    ft_printf("For Julia set is necessary to pass two values c.real and c.imaginary,\n");
    ft_printf("both values can be: (value <= 2 && value >= -2).\n");
    ft_printf("   Ex: bash->./fractol \"julia\" 1.82 1.0\n");
    ft_printf("\n");
    ft_printf("ideas for julia values: -0.4 0.6 or 0.285 0.01 or -0.8 0.156");
    ft_printf("------------------------------");
    ft_printf("------------------------------\n\n");
}