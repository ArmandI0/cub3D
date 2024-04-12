
#include "../../includes/cub3D.h"

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
	{
		move_player_forward(p->player, 0.2);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		return;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		printf("rotation\n");
		rotate_player(p->player, +5);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		printf("rotation\n");
		rotate_player(p->player, -5);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
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
