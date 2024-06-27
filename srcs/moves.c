#include "srcs_so_long.h"

// Reset le status du joueur
void	ft_change_status(Game *game, int status)
{
	game->ticks = 0;
	game->hero.status = status;
	game->hero.displayed_img = 0;
}

// Gere le deplacement du joueur
void	ft_player_moves(Game *game, int d_x, int d_y)
{
	if (d_x <= 0 || d_x >= game->width || d_y <= 0 || d_y >= game->height)
		return ;
	if (game->map[d_y][d_x] == '1')
		return ;
	else if (game->map[d_y][d_x] == 'C')
	{
		game->hero.collectibles++;
		ft_change_status(game, 2);
		ft_printf("%d / %d \n", game->hero.collectibles, game->collectibles);
	}
	else if (game->map[d_y][d_x] == 'E')
	{
		if (game->collectibles == game->hero.collectibles)
			exit(1);
		else
			return ;
	}
	game->map[game->hero.y][game->hero.x] = '0';
	game->hero.x = d_x;
	game->hero.y = d_y;
	game->map[game->hero.y][game->hero.x] = 'P';
}

// Gere les inputs
int	ft_keypress_handle(int keycode, Game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window_2);
		exit(0);
	}
	if (keycode == KEY_SPACE)
	{
		game->hero.status = 2;
		game->hero.displayed_img = 0;
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_player_moves(game, game->hero.x, game->hero.y - 1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_player_moves(game, game->hero.x, game->hero.y + 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->hero.orientation = 'l';
		ft_change_status(game, 1);
		ft_player_moves(game, game->hero.x - 1, game->hero.y);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->hero.orientation = 'r';
		ft_change_status(game, 1);
		ft_player_moves(game, game->hero.x + 1, game->hero.y);
	}
	return (0);
}