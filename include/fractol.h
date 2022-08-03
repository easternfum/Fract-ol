/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:46:04 by kfum              #+#    #+#             */
/*   Updated: 2022/06/20 14:08:31 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1200
# define HEIGHT 800
# define THREADS 32

# include <math.h>
# include <pthread.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_fractol
{
	double	real;
	double	img;
}				t_fractol;

typedef struct s_window
{
	void		*mlx;
	void		*window;
	void		*graphic;
	double		x;
	double		y;
	double		zoom;
	int			color;
	int			iter;
	int			inter;
	char		*fract;
	double		init;
	int			f_type;
	t_fractol	point;
}				t_window;

typedef struct s_line
{
	int			x;
	int			s_line;
	int			e_line;
	int			color;
	t_window	*win;
}				t_line;

/* color.c */
void	init_color(t_window *graph, int x, int y, int color);

/* control.c */
int		mouse_zoom(int key, int x, int y, t_window *graph);
int		mouse_move(int x, int y, t_window *graph);
int		key_setting(int key, t_window *graph);

/* graphic.c */
void	init_graph(t_window *graph);
int		init_draw(t_window *graph);
void	clear_graph(t_window *graph);

/* print.c */
void	graph_type(t_line *line, t_fractol p1, t_fractol p2);

/* window.c*/
void	create_window(t_window *graph);
void	control_instruction(t_window *graph);

#endif