#ifndef CUB3D_H
# define CUB3D_H

# define KEY_PRESS 3

# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 1280
# define HEIGHT 720
# define STRİNGWIDTH 300
# define STRİNGHEIGHT 600



typedef struct s_mlx t_mlx;
typedef void(*delegateMethod)(t_mlx*);


typedef struct s_dialog
{
    unsigned int color;
    char *str;
    char *character;
}   t_dialog;

typedef struct s_dialog_c
{
    int dindex;
    int maxd;
    char *mainstr;
    int strindex;
    bool wait;
    bool playing;
}   t_dialog_c;

typedef struct s_sprite
{
    char *name;
    void *image;
    int x;
    int y;
    struct s_sprite *next;
}   t_sprite;

typedef struct s_smanager
{
    t_sprite *sprites;
}   t_smanager;

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int clear_ptr;
    t_dialog_c controller;
    t_smanager smanager;
    t_dialog *dialogs;
    delegateMethod dmethod;
}   t_mlx;

void    add_image(t_mlx *data, char *name, char *location, int x, int y);
t_sprite    *get_image(t_mlx *data, char *name);
void	real_girl_mlx(int a, int b, t_mlx *emerald);
int     press_enter();
void    get_dialog(t_mlx *data);
void    init_dialogs(t_mlx *data);
t_sprite	*new_sprite(t_mlx *data, char *name, char *location, int x, int y);
void	add_list_back(t_sprite **lst, t_sprite *sprite);
void    deneme(t_mlx *data);

#endif