#include "srcs_so_long.h"

// Initialise la fenetre
bool	ft_game_init(Game *game)
{
	game->mlx = mlx_init();
	game->window_2 = mlx_new_window(game->mlx, game->width * game->size,
			game->height * game->size, "SO_LONG");
	if (!game->window_2 || !game->mlx)
		return (false);
	return (true);
}

// Gestion de la partie jeu
int	ft_game(Game *game)
{
	game->size = 32;
	if (!ft_game_init(game))
		return (1);
	ft_images_load(game);
	ft_key_hook_set(game);
	ft_game_loop(game);
	return (0);
}