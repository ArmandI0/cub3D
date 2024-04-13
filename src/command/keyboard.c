
#include "../../includes/cub3D.h"

/* if tr = FASLSE translate forward else translate R or L*/

void	rotation(t_params *p, double step)
{
	rotate_player(p->player, step);
	mlx_delete_image(p->set->window, p->set->img);
	p->set->img = set_img(p->set);
	if (raycasting(p, p->set, p->player) == FALSE)
		exit_fct(p);
	if(mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10) < 0)
		exit_fct(p);
	print_player(p->set);
}
static void translation(t_params *p, double step, t_bool tr)
{
	if (tr == FALSE)
		translate_player_forward(p->player, step, p->map->map2d);
	else
		translate_player_l_to_r(p->player, step, p->map->map2d);
	mlx_delete_image(p->set->window, p->set->img);
	p->set->img = set_img(p->set);
	if (raycasting(p, p->set, p->player) == FALSE)
		exit_fct(p);
	if(mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10) < 0)
		exit_fct(p);
	print_player(p->set);
}

static void	translation_key(mlx_key_data_t	keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		translation(p, 0.1, FALSE);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		translation(p, -0.1, FALSE);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		translation(p, 0.1, TRUE);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		translation(p, -0.1, TRUE);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_REPEAT)
		rotation(p, 5);
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_REPEAT)
		rotation(p, -5);
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
