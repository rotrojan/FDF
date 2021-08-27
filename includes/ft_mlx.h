/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:17 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 17:18:06 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

#define TITLE "fdf"
#define WIDTH 800 
#define HEIGHT 600 

/*
** This structure contains all informations needed by the MLX. Even if a screen-
** shot is called (hence the mlx is not initialized) the *data pointer contains
** the array of pixels of the resulting image.
*/

typedef struct	s_mlx
{
	unsigned int	win_width;
	unsigned int	win_height;
	int				screen_width;
	int				screen_height;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
}				t_mlx;

typedef struct	s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

/*
** mlx_utils.c
*/

t_mlx	*get_mlx(void);
t_color	get_color(float r, float g, float b);
void	init_mlx(t_mlx *mlx);
int		close_mlx(t_mlx *mlx);
int		run_window(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color);
void	run_mlx(t_mlx *mlx);

/*
** mlx_hooks.c
*/

void		set_mlx_hooks(t_mlx *mlx);

#endif
