/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:58:34 by kfum              #+#    #+#             */
/*   Updated: 2022/10/05 12:00:11 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** Initial colors to graphic
*/
static void	init_color_part(t_window *graph, char *new_graph, int g, int color)
{
	if (graph->f_type == 2 || graph->f_type == 3)
	{
		new_graph[g + 0] = (int)((color) & 0xFF);
		new_graph[g + 1] = (int)((color >> 16) & 0xFF);
		new_graph[g + 2] = (int)((color >> 10) & 0xFF);
	}
	else
	{
		new_graph[g + 0] = (int)((color) & 0xFF);
		new_graph[g + 1] = (int)((color >> 1) & 0xFF);
		new_graph[g + 2] = (int)((color >> 5) & 0xFF);
	}
}

/*
** Initial colors to graphic
*/
void	init_color(t_window *graph, int x, int y, int color)
{
	char	*new_graph;
	int		g;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		new_graph = mlx_get_data_addr(graph->graphic, &g, &g, &g);
		g = WIDTH * y * 4 + x * 4;
		init_color_part(graph, new_graph, g, color);
	}
}
