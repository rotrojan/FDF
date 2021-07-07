/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/07/07 23:29:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*mlx_provider(void)
{
	static t_mlx mlx = {
		.win_width = WIDTH,
		.win_height = HEIGHT,
		.mlx_ptr = NULL,
		.win_ptr = NULL,
		.img_ptr = NULL,
		.data = NULL,
		.size_line = 0,
		.bits_per_pixel = 0,
		.endian = 0
	};

	return (&mlx);
}

/*                           
** All these functions are self explanatories. Check out the MLX "documentation"
** for further informations .endian; .. try not to cry.
*/

t_bool	run_mlx(t_main *main)
{
	if (!(set_mlx_hooks(main)))
		return (FALSE);
	mlx_loop(main->mlx.mlx_ptr);
	return (TRUE);
}

int	run_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int	close_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	/* free_scene(&main->scene, 1); */
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height, TITLE);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
}

void	put_pixel(t_mlx *mlx, unsigned int x, unsigned int y, t_color color)
{
	int		*pixel_array[mlx->win_width][1];
	int		final_color;

	if ((x >= mlx->win_width && x < 0) || (y >= mlx->win_height && y < 0))
		return ;
	final_color = ((((int)(color.r * 255) << 8)
		| (int)(color.g * 255)) << 8) | (int)(color.b * 255);
	pixel_array = (void*)mlx->data;
	*pixel_array[y][x] = final_color;
}
