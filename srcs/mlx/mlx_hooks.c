/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/27 18:36:55 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Erase the current image, switch to the next camera, raytrace again and load
** the new image.
*/

/* static void	switch_cam(t_main *main) */
/* { */
	/* ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4); */
	/* main->scene.cam_lst = main->scene.cam_lst->next; */
	/* ray_tracer(main); */
	/* mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr, */
		/* main->mlx.img_ptr, 0, 0); */
/* } */

/*
** Launch the function corresponding to the received event.
*/

static int	key_hook(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_mlx(mlx);
	/* if (key == XK_space) */
		/* switch_cam(mlx); */
	/* run_mlx(mlx); */
	return (0);
}

/*
** The mlx_loop_hook function wait for key or mouse events.
** For more informations about events management with the MlX, check out the MLX
** "documentation" ... and try not to cry.
*/

void			set_mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, ClientMessage, StructureNotifyMask, &close_mlx, mlx);
	mlx_hook(mlx->win_ptr, VisibilityNotify, VisibilityChangeMask, &run_window,
		mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &key_hook, mlx);
}
