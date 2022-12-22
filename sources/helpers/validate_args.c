//header

#include "../../includes/fractol.h"

/*
	[ ]valiar impressão de helper caso haja algum erro de input
	[ ]validar a quantidade correta de argumentos
	[ ]validar se o nome dos fractais estão corretos
	[ ]validar os parâmetros para o julia set (para isso será necessário um atod ou atof)
	[ ]validar caminho ideal (quando todos os parâmetros estão corretos)
*/
void validate_and_filter_args(t_vars *v, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) ||
			!ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])))
		{
			return ;
		}

	}

	if (argc < 2 || argc > 4)
	{
		print_information_to_user();
		exit(0);
	}
	else if (argc == 2 && ft_strncmp(argv[1], "-h", ft_strlen(argv[1])) == 0)
	{
		print_information_to_user();
		exit(0);
	}



}

void burning_ship(t_vars *v)
{
	double x;
	double c;

	// ./fractol "z=z^2+c"
	// attribution(a b)
	// multiplication
	x = (x * x) + c;
}

void check_if_fractol_exist(t_list *fractais, t_vars *v, char *str)
{

	while (fractais->content != NULL)
	{
		int i;
		
		i = 0;
					//str = argv[1]
		if(ft_strncmp(str, "fractais->content", ft_strlen(str)) == 0)
		{
			v->fractol = str;
			return (1);
		}
		i++;
	}
	return (0);
}