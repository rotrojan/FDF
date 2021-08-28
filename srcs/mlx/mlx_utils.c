/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/28 03:34:18 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	run_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int	close_mlx(t_mlx *mlx)
{
	int		ret;

	ret = EXIT_FAILURE;
	if (mlx->mlx_ptr != NULL)
	{
		ret = EXIT_SUCCESS;
		mlx_loop_end(mlx->mlx_ptr);
		if (mlx->img_ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		else
			ret = EXIT_FAILURE;
		if (mlx->win_ptr != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		else
			ret = EXIT_FAILURE;
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(ret);
	return (EXIT_FAILURE);
}

t_error	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (MLX_INIT_ERROR);
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->screen_width, &mlx->screen_height);
	mlx->win_width = (unsigned int)fmin(WIDTH, mlx->screen_width);
	mlx->win_height = (unsigned int)fmin(HEIGHT, mlx->screen_height);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width, mlx->win_height,
			TITLE);
	if (mlx->win_ptr == NULL)
		return (MLX_WIN_ERROR);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
	if (mlx->img_ptr == NULL)
		return (MLX_IMG_ERROR);
	mlx->data = (int *)mlx_get_data_addr(
			mlx->img_ptr, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	set_mlx_hooks(mlx);
	return (NO_ERROR);
}

t_color	get_color(float r, float g, float b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color)
{
	int		final_color;

	if ((x >= mlx->win_width && x < 0) || (y >= mlx->win_height && y < 0))
		return ;
	final_color = ((((int)(color.r * 255) << 8) | (int)(color.g * 255)) << 8)
		| (int)(color.b * 255);
	mlx->data[x + y * mlx->win_width] = final_color;
}
