/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:26:17 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 23:04:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

#define TITLE fdf
#define WIDTH 800 
#define HEIGHT 600 

/*
** This structure contains all informations needed by the MLX. Even if a screen-
** shot is called (hence the mlx is not initialized) the *data pointer contains
** the array of pixels of the resulting image.
*/

typedef struct		s_mlx
{
	unsigned int		win_width;
	unsigned int		win_height;
	int					screen_width;
	int					screen_height;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*data;
	int					size_line;
	int					bits_per_pixel;
	int					endian;
}					t_mlx;

/*
** mlx_utils.c
*/

void	init_mlx(t_mlx *mlx);
int		close_mlx(t_main *main);
int		run_window(t_main *main);
void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color);
t_bool	run_mlx(t_main *main);

/*
** mlx_hooks.c
*/

int		set_mlx_hooks(t_main *main);


#endif
