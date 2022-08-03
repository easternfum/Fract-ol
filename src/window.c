/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:29:04 by kfum              #+#    #+#             */
/*   Updated: 2022/06/21 15:04:54 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Putting all the input to struct then create a pop up window
*/
void	create_window(t_window *graph)
{
	graph->iter = 400;
	init_graph(graph);
	graph->mlx = mlx_init();
	graph->window = mlx_new_window(graph->mlx, WIDTH, HEIGHT, graph->fract);
	graph->graphic = mlx_new_image(graph->mlx, WIDTH, HEIGHT);
	mlx_hook(graph->window, 6, 64, mouse_move, graph);
	mlx_mouse_hook(graph->window, mouse_zoom, graph);
	mlx_hook(graph->window, 2, 3, key_setting, graph);
	mlx_loop_hook(graph->mlx, init_draw, graph);
	mlx_loop(graph->mlx);
}

/*
** Instruction for the controls that show on screen
*/
void	control_instruction(t_window *graph)
{
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 140, 0x00FFFFFF,
		"Mouse wheel - zoom in/zoom out");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 130, 0x00FFFFFF, "");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 120, 0x00FFFFFF,
		"Arrow left/Arrow right - move left/right");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 110, 0x00FFFFFF, "");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 100, 0x00FFFFFF,
		"Arrow up/Arrow down - move up/down");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 90, 0x00FFFFFF, "");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 80, 0x00FFFFFF,
		"Q - back to default mode");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 70, 0x00FFFFFF, "");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 60, 0x00FFFFFF,
		"ESC - exit window");
	mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 50, 0x00FFFFFF, "");
	if (ft_strequ(graph->fract, "Julia") || ft_strequ(graph->fract, "J"))
	{
		mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 40, 0x00FFFFFF,
			"L - lock/unlock mode");
		mlx_string_put(graph->mlx, graph->window, 20, HEIGHT - 30, 0x00FFFFFF,
			"");
	}
}
