#include "includes/cub3d.h"
// spritelari linked listte tutucaz ve getsprite ile string verip sprite adresini alicaz.

void	add_image(t_mlx *data, char *name, char *location, int x, int y)
{
	t_sprite *sprite;
	t_sprite *tmp;

	tmp = data->smanager.sprites;
	while (tmp)
	{
		if (tmp->name == name)
		{
			printf("this sprite already added : %s", name);
			return;
		}
		tmp = tmp->next;
	}
	sprite = new_sprite(data, name, location, x, y);
	add_list_back(&data->smanager.sprites, sprite);
}

t_sprite	*get_image(t_mlx *data, char *name)
{
	t_sprite *tmp;

	tmp = data->smanager.sprites;
	while (tmp)
	{
		if (tmp->name[0] == name[0])
			return (tmp);
		tmp = tmp->next;
	}
	printf("image cannot found : %s\n", name);
	return (NULL);
}