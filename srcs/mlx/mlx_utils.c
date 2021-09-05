/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/05 21:19:18 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*get_mlx(void)
{
	static t_mlx	mlx = {0};

	return (&mlx);
}

int	run_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int	close_mlx(void)
{
	int		ret;
	t_mlx	*mlx;

	mlx = get_mlx();
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

t_error	init_mlx(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
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
