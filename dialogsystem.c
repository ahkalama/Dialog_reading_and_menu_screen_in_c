#include "includes/cub3d.h"
#include <string.h>
#include <fcntl.h>

static char *ft_strdup(char *str)
{
	char *res;
	int i;

	i = 0;
	res = malloc(strlen(str) + 1);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return res;
}

static char *get_one_str(char *str, int i, int len)
{
	char *res;

	while (str[i++] != 32)
		len++;
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return res;
}

void go_next_data(char *readed, int *i)
{
	while (readed[*i] != 32)
		(*i)++;
	while (readed[*i] == 32)
		(*i)++;
}

void parse_that_shit(t_dialog *dialog, char *readed, int x, int y)
{
	int i;

	i = 0;
	dialog->color = atoi(&readed[i]);
	go_next_data(readed, &i);
	dialog->character = get_one_str(&readed[i], 0, 0);
	go_next_data(readed, &i);
	dialog->str = ft_strdup(&readed[i]);
	if (readed)
		free(readed);
}

bool read_dialogs(t_mlx *data)
{
	int fd;
	char *readed;
	int i;

	fd = open("dialogs.txt", O_RDONLY);
	if (fd == -1)
		return (false);
	readed = get_next_line(fd);
	if (readed == NULL)
		return (false);
	data->dialogs = malloc(sizeof(t_dialog) * atoi(readed));
	data->controller.maxd = atoi(readed);
	i = 0;
	while (true)
	{
		readed = get_next_line(fd);
		if (readed == NULL)
			break;
		parse_that_shit(&data->dialogs[i], readed, -1, -1);
		i++;
	}
	return (true);
}

void init_dialogs(t_mlx *data)
{
	data->controller.dindex = 0;
	data->controller.playing = true;
	data->controller.wait = false;
	data->controller.strindex = 0;
	data->controller.mainstr = "";

	read_dialogs(data);
}

static char *strjoin_char(char *str, char ch)
{
	char *result = (char *)malloc(strlen(str) + 2);
	if (result != NULL)
	{
		strcpy(result, str);
		result[strlen(str)] = ch;
		result[strlen(str) + 1] = '\0';
	}
	return result;
}

static void join(t_dialog_c *controller, t_dialog *dialog)
{
	controller->mainstr = strjoin_char(controller->mainstr,
									   dialog->str[controller->strindex++]);
}

static void dialog_put(t_mlx *data, t_sprite *sprite, t_dialog dialog)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	sprite = get_image(data, dialog.character);
	if (sprite != NULL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			sprite->image, sprite->x, sprite->y);

	}
	join(&data->controller, &dialog);
	mlx_string_put(data->mlx_ptr, data->win_ptr, STRİNGWIDTH, STRİNGHEIGHT,
				   dialog.color, data->controller.mainstr);
}

void get_dialog(t_mlx *data)
{
	t_sprite *sprite;

	if (!data->controller.playing || data->controller.wait)
	{
		if (data->controller.wait == false && data->controller.playing == false)
		{
			data->controller.wait = true;
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			data->dmethod = &deneme;
		}
		return;
	}
	t_dialog dialog = data->dialogs[data->controller.dindex];
	if (data->controller.strindex < strlen(dialog.str))
		dialog_put(data, sprite, dialog);
	else
	{
		data->controller.wait = true;
		data->controller.strindex = 0;
		data->controller.mainstr = "";
		data->controller.dindex++;
	}
	if (data->controller.dindex >= data->controller.maxd)
		data->controller.playing = false;
}