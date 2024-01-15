#include <unistd.h>
#include "includes/cub3d.h"

void	add_list_back(t_sprite **lst, t_sprite *sprite)
{
	t_sprite *tmp;

	if (!(*lst))
	{
		(*lst) = sprite;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = sprite;
}

t_sprite	*new_sprite(t_mlx *data, char *name, char *location, int x, int y)
{
	int	a;
	t_sprite *sprite = malloc(sizeof(t_sprite));

	sprite->image = mlx_xpm_file_to_image(data->mlx_ptr, location, &a, &a);
	sprite->name = name;
	sprite->x = x;
	sprite->y = y;
	sprite->next = NULL;
	return (sprite);
}
