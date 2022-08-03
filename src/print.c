/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:53:33 by kfum              #+#    #+#             */
/*   Updated: 2022/06/30 16:13:45 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Draw 'Julia' graphic to window
*/
static void	draw_julia(t_line *line, t_fractol *p1, t_fractol *p2)
{
	int	i;

	i = 0;
	while (i < line->win->iter)
	{
		p1->real = p2->real;
		p1->img = p2->img;
		p2->real = p1->real * p1->real - p1->img * p1->img;
		p2->real += line->win->point.real;
		p2->img = 2 * p1->real * p1->img + line->win->point.real;
		if ((p2->real * p2->real + p2->img * p2->img) > 4)
			break ;
		i++;
	}
	if (i == line->win->iter)
		line->color = (0x00FFFFFF * i / (line->win->iter));
	if (i < line->win->iter / 2)
		line->color = (0x00079212 * i / (line->win->iter + 3));
	else
		line->color = 0x00FFF633;
	init_color(line->win, line->x, line->s_line, line->color);
}

/*
** Draw 'Mandelbrot' graphic to window
*/
static void	draw_mandelbrot(t_line *line, t_fractol *p1, t_fractol *p2)
{
	int		i;
	double	j;

	i = 0;
	while (i < line->win->iter)
	{
		j = p1->real;
		p1->real = p1->real * p1->real - p1->img * p1->img + p2->real;
		p1->img = 2 * j * p1->img + p2->img;
		if ((p1->real * p1->real + p1->img * p1->img) > 4)
			break ;
		i++;
	}
	if (i == line->win->iter)
		line->color = (0x00F00C0C * i / (line->win->iter));
	if (i < line->win->iter / 2)
		line->color = (0x001F618D * i / (line->win->iter));
	else
		line->color = 0x0085C1E9;
	init_color(line->win, line->x, line->s_line, line->color);
}

/*
** Draw 'Ship' graphic to window
*/
static void	draw_ship(t_line *line, t_fractol *p1, t_fractol *p2)
{
	int		i;
	double	j;

	i = 0;
	while (i < line->win->iter)
	{
		j = fabs(p1->real);
		p1->real = p1->real * p1->real - fabs(p1->img * p1->img) + p2->real;
		p1->img = 2 * fabs(j * p1->img) + p2->img;
		if ((p1->real * p1->real + p1->img * p1->img) > 4)
			break ;
		i++;
	}
	if (i == line->win->iter)
		line->color = (0x00F7E507 * i / (line->win->iter));
	if (i < line->win->iter / 2)
		line->color = (0x00581845 * i / (line->win->iter));
	else
		line->color = 0x00000000;
	init_color(line->win, line->x, line->s_line, line->color);
}

/*
** Draw 'Tricorn' graphic to window
*/
static void	draw_tricorn(t_line *line, t_fractol *p1, t_fractol *p2)
{
	int		i;

	i = 0;
	while (i < line->win->iter)
	{
		p1->real = p2->real;
		p1->img = p2->img;
		p2->real = p1->real * p1->real - p1->img * p1->img + p2->real;
		p2->img = -2 * p1->real * p1->img + p2->img;
		if ((p1->real * p1->real + p1->img * p1->img) > 4)
			break ;
		i++;
	}
	if (i == line->win->iter)
		line->color = (0x00F7E507 * i / (line->win->iter));
	if (i < line->win->iter / 2)
		line->color = (0x00581845 * i / (line->win->iter));
	else
		line->color = 0x00000000;
	init_color(line->win, line->x, line->s_line, line->color);
}

/*
** Graphic type selection
*/
void	graph_type(t_line *line, t_fractol p1, t_fractol p2)
{
	if (line->win->f_type == 1)
		return (draw_julia(line, &p1, &p2));
	else if (line->win->f_type == 2)
		return (draw_mandelbrot(line, &p1, &p2));
	else if (line->win->f_type == 3)
		return (draw_ship(line, &p1, &p2));
	else if (line->win->f_type == 4)
		return (draw_tricorn(line, &p1, &p2));
}
