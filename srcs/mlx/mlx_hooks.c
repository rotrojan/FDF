/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/06 00:53:29 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ZOOMIN_COEF 1.1
#define ZOOMOUT_COEF 0.9

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

t_transformations	*get_transformations(void)
{
	static t_transformations	transformations = {
		.zoom = 50.0,
		.trans_x = 0,
		.trans_y = 0
	};

	return (&transformations);
}

void	zoom(int key)
{
	t_map	map;
	t_point	**transformed_map;
	t_mlx	*mlx;
	float	*zoom_factor;

	map = *get_map();
	transformed_map = *get_transformed_map();
	mlx = get_mlx();
	zoom_factor = &get_transformations()->zoom;
	free_transformed_map(get_transformed_map(), map.height);
	ft_bzero(mlx->data, mlx->win_width * mlx->win_height * 4);
	if (key == XK_i)
		*zoom_factor += 0.5;
	else if (key == XK_o)
	{
		*zoom_factor -= 0.5;
		if (*zoom_factor < 0)
			*zoom_factor = 0;
	}
	display_projection();
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	translate_map(int key)
{
	t_transformations	*transformations;

	transformations = get_transformations();
	if (key == XK_Up)
		transformations->trans_y -= 10;
	else if (key == XK_Down)
		transformations->trans_y += 10;
	else if (key == XK_Right)
		transformations->trans_x += 10;
	else if (key == XK_Left)
		transformations->trans_x -= 10;
}

void	translate(int key)
{
	t_map	map;
	t_point	**transformed_map;
	t_mlx	*mlx;

	map = *get_map();
	transformed_map = *get_transformed_map();
	mlx = get_mlx();
	free_transformed_map(get_transformed_map(), map.height);
	ft_bzero(mlx->data, mlx->win_width * mlx->win_height * 4);
	translate_map(key);
	display_projection();
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

static int	key_hook(int key)
{
	if (key == XK_Escape)
		close_mlx();
	if (key == XK_i || key == XK_o)
		zoom(key);
	if (key == XK_Up || key == XK_Right || key == XK_Left || key == XK_Down)
		translate(key);

	/* if (key == XKd_o) */
		/* zoom_out(mlx); */
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

void	set_mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, ClientMessage, StructureNotifyMask, &close_mlx, NULL);
	mlx_hook(mlx->win_ptr, VisibilityNotify, VisibilityChangeMask, &run_window,
		mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &key_hook, mlx);
}
