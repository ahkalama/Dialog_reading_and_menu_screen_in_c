
#include "includes/cub3d.h"

void	deneme(t_mlx *data)
{
	printf("deneme\n");
}

int press_enter(int keycode, t_mlx *emerald)
{
	if (keycode == 36)
		emerald->controller.wait = false;
	if (keycode == 53)
		exit(0);
	return 0;
}

void	real_girl_mlx(int a, int b, t_mlx *emerald)
{
	a = 300;
	b = 300;
	emerald->mlx_ptr = mlx_init();
	emerald->win_ptr = mlx_new_window(emerald->mlx_ptr, WIDTH, HEIGHT, "My Window");
	add_image(emerald, "b", "Pictures/arkaseda.xpm", 0, 0);
	add_image(emerald, "c", "Pictures/ahmetarka.xpm", 0, 0);
	add_image(emerald, "d", "Pictures/menu0.xpm", 0, 0);
	init_dialogs(emerald);
	mlx_hook(emerald->win_ptr, KEY_PRESS, 0, press_enter, emerald);
}
