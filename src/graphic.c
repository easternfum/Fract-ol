/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:58:34 by kfum              #+#    #+#             */
/*   Updated: 2022/06/27 18:11:06 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initialize the graphic output
*/
void	init_graph(t_window *graph)
{
	graph->x = 0.0;
	graph->y = 0.0;
	graph->zoom = 0.3;
	if (graph->f_type == 1)
	{
		graph->zoom = 0.4;
		graph->point.real = -0.6;
		graph->point.img = 1;
	}
	if (graph->f_type == 3)
	{
		graph->iter = 410;
	}
	if (graph->f_type == 4)
	{
		graph->point.real = -10;
		graph->point.img = 10;
		graph->iter = 120;
	}
}

/*
** Draw graphic to window
*/
static void	*draw_graph(void *arg)
{
	t_fractol	p1;
	t_fractol	p2;
	t_line		*line;
	int			i;

	line = (t_line *)arg;
	while (line->s_line != line->e_line)
	{
		i = 0;
		while (i < WIDTH)
		{
			line->x = i;
			p1.real = 0;
			p1.img = 0;
			p2.real = 1.5 * (i - WIDTH / 2) / (0.5 * line->win->zoom * WIDTH);
			p2.real += line->win->x;
			p2.img = (line->s_line - HEIGHT / 2)
				/ (0.5 * line->win->zoom * HEIGHT);
			p2.img += line->win->y;
			graph_type(line, p1, p2);
			i++;
		}
		line->s_line += 1;
	}
	pthread_exit(NULL);
}

/*
** Initialize drawing to window
*/
int	init_draw(t_window *graph)
{
	pthread_t	threads[THREADS];
	t_line		line[THREADS];
	int			i;

	clear_graph(graph);
	i = 0;
	while (i < THREADS)
	{
		line[i].win = graph;
		line[i].s_line = HEIGHT / THREADS * i;
		line[i].e_line = HEIGHT / THREADS * (i + 1);
		pthread_create(&(threads[i]), NULL, draw_graph, &(line[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(graph->mlx, graph->window, graph->graphic, 0, 0);
	control_instruction(graph);
	return (0);
}

/*
** Clear the graphic
*/
void	clear_graph(t_window *graph)
{
	char	*new_graph;
	int		g;

	new_graph = mlx_get_data_addr(graph->graphic, &g, &g, &g);
	ft_bzero(new_graph, 4 * WIDTH * HEIGHT);
}
