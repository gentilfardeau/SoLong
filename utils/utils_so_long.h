#ifndef UTILS_SO_LONG_H
# define UTILS_SO_LONG_H

#include "../so_long.h"

// MLX_UTILS.C
void mlx_img_win(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
void *mlx_xpm_img(void *mlx_ptr, char **xpm_data, int *width, int *height);

///////// RENDER_UTILS.C ///////////////////////////////////
void	ft_load_idle(Game *game, int width, int height);
void	ft_load_jump(Game *game, int width, int height);
void ft_key_hook_set(Game *game);
void ft_game_loop(Game *game);

// MAP_UTILS.C
bool ft_map_load(Game *game, char *filename);

// PARSING_UTILS.C


#endif