#include "srcs_so_long.h"

void	ft_frame_update(Game *game)
{
	game->ticks++;
	if (game->ticks >= ANIM_SPEED)
	{
		game->ticks = 0;
		game->hero.displayed_img = (game->hero.displayed_img + 1)
			% game->hero.total_frame;
		if (game->hero.displayed_img == 3 && game->hero.status == 1)
			game->hero.status = 0;
		if (game->hero.displayed_img == 3 && game->hero.status == 2)
			game->hero.status = 0;
	}
}

bool	ft_the_end(Game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->hero.collectibles == game->collectibles)
		return (mlx_destroy_window(game->mlx, game->window_2));
	else
		return (false);
}

int	ft_game_update(Game *game)
{
	ft_frame_update(game);
	ft_render(game);
	return (0);
}