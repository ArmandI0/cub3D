
#include "../../includes/cub3D.h"

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_window_settings	*set;

	set = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		set->img->instances[0].x += 2;
		set->img->instances[0].y += 2;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		return;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		return;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		return;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_window_settings	*set;

	set = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(set->window);
	}
	translation_key(keydata, param);
}
