#include "utils_so_long.h"

void	ft_key_hook_set(Game *game)
{
	mlx_key_hook(game->window_2, ft_keypress_handle, game);
}

void	ft_game_loop(Game *game)
{
	mlx_loop_hook(game->mlx, ft_game_update, game);
	mlx_loop(game->mlx);
}