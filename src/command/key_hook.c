
#include "../../includes/cub3D.h"

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		translate_player_forward(p->player, 0.1, p->map->map2d);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		translate_player_forward(p->player, -0.1, p->map->map2d);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		printf("x = %f // y = %f\n", p->player->pos_y, p->player->pos_x);
		translate_player_l_to_r(p->player, 0.1, p->map->map2d);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		printf("rotation\n");
		translate_player_l_to_r(p->player, -0.1 , p->map->map2d);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_REPEAT)
	{
		printf("rotation\n");
		rotate_player(p->player, +5);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_REPEAT)
	{
		printf("rotation\n");
		rotate_player(p->player, -5);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
}


void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(p->set->window);
	}
	translation_key(keydata, param);
}
