/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:40:23 by kfum              #+#    #+#             */
/*   Updated: 2022/06/14 16:35:10 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Print out messages
*/
static void	exit_msg(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

/*
** Setting up mouse zoom function
*/
int	mouse_zoom(int key, int x, int y, t_window *graph)
{
	if (key == 4)
	{
		graph->zoom *= 1.5;
		graph->x += 1.5 * (x - WIDTH / 2) / (0.5 * graph->zoom * WIDTH);
		graph->y += (y - HEIGHT / 2) / (0.5 * graph->zoom * HEIGHT);
	}
	if (key == 5 && graph->zoom > 0.2)
	{
		graph->zoom /= 1.5;
	}
	return (0);
}

/*
** Setting up mouse move function
*/
int	mouse_move(int x, int y, t_window *graph)
{
	if (graph->inter == 1)
	{
		graph->point.real = 1.5 * (x - WIDTH / 2);
		graph->point.real /= (0.5 * WIDTH * graph->zoom);
		graph->point.real += graph->x;
		graph->point.img = (y - HEIGHT / 2) / (0.5 * HEIGHT * graph->zoom);
		graph->point.img += graph->y;
	}
	return (0);
}

/*
** Key input setting
*/
int	key_setting(int key, t_window *graph)
{
	if (key == 53)
		exit_msg("Exit success");
	if (key == 37)
	{
		if (graph->inter == 0)
			graph->inter = 1;
		else
			graph->inter = 0;
	}
	if (key == 125)
		graph->y -= 0.05 / graph->zoom;
	if (key == 126)
		graph->y += 0.05 / graph->zoom;
	if (key == 123)
		graph->x += 0.05 / graph->zoom;
	if (key == 124)
		graph->x -= 0.1 / graph->zoom;
	if (key == 12)
		init_graph(graph);
	return (0);
}
