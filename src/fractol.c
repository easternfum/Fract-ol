/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:12:58 by kfum              #+#    #+#             */
/*   Updated: 2022/06/17 14:02:32 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	available_type(void)
{
	ft_putendl("1. Julia or J");
	ft_putendl("2. Mandelbrot or M");
	ft_putendl("3. Ship or S");
	ft_putendl("4. Tricorn or T");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_window	graph;

	if (argc != 2)
		available_type();
	else
	{
		if (ft_strequ("Julia", argv[1]) || ft_strequ("J", argv[1]))
			graph.f_type = 1;
		else if (ft_strequ("Mandelbrot", argv[1]) || ft_strequ("M", argv[1]))
			graph.f_type = 2;
		else if (ft_strequ("Ship", argv[1]) || ft_strequ("S", argv[1]))
			graph.f_type = 3;
		else if (ft_strequ("Tricorn", argv[1]) || ft_strequ("T", argv[1]))
			graph.f_type = 4;
		else
			available_type();
		graph.fract = argv[1];
		create_window(&graph);
	}
	return (0);
}
