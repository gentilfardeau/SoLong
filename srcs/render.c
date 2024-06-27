#include "srcs_so_long.h"

// Charge les props
void	ft_load_props(Game *game, int width, int height)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/GAME_x32/PROPS/wall.xpm", &width, &height);
	game->img_consum = mlx_xpm_file_to_image(game->mlx,
			"assets/GAME_x32/PROPS/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/GAME_x32/PROPS/exit_off.xpm", &width, &height);
}

// Charge les differents sprites
void	ft_images_load(Game *game)
{
	int	width;
	int	height;

	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/GAME_x32/PROPS/floor.xpm", &width, &height);
	ft_load_props(game, width, height);
	ft_load_hero(game);
	game->ticks = 0;
	game->hero.status = 0;
	game->hero.displayed_img = 0;
	game->hero.total_frame = 4;
	game->hero.orientation = 'l';
}

// Affiche les images a l'écran et les rafraichit pour le heros
void	ft_render_hero(Game *game, int x, int y)
{
	if (game->hero.status == 0 && game->hero.orientation == 'l')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_idle_l[game->hero.displayed_img], x * game->size, y
			* game->size);
	else if (game->hero.status == 0 && game->hero.orientation == 'r')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_idle_r[game->hero.displayed_img], x * game->size, y
			* game->size);
	else if (game->hero.status == 1 && game->hero.orientation == 'l')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_walking_l[game->hero.displayed_img], x * game->size,
			y * game->size);
	else if (game->hero.status == 1 && game->hero.orientation == 'r')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_walking_r[game->hero.displayed_img], x * game->size,
			y * game->size);
	else if (game->hero.status == 2 && game->hero.orientation == 'l')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_jump_l[game->hero.displayed_img], x * game->size, y
			* game->size);
	else if (game->hero.status == 2 && game->hero.orientation == 'r')
		mlx_put_image_to_window(game->mlx, game->window_2,
			game->hero.img_jump_r[game->hero.displayed_img], x * game->size, y
			* game->size);
}

// Gere l'envoi a l'écran
void	ft_render(Game *game)
{
	int	x;
	int	y;

	usleep(2000);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->window_2, game->img_floor,
				x * game->size, y * game->size);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window_2,
					game->img_wall, x * game->size, y * game->size);
			else if (game->map[y][x] == 'P')
				ft_render_hero(game, x, y);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window_2,
					game->img_consum, x * game->size, y * game->size);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window_2,
					game->img_exit, x * game->size, y * game->size);
			x++;
		}
		y++;
	}
}
