#include "srcs_so_long.h"

// Alloue la map et rempli avec les sprites
bool	ft_map_allocate(Game *game, char *filename)
{
	int	x;

	if (!game || !filename)
		return (false);
	game->map = malloc(game->height * sizeof(char *));
	if (!game->map)
		return (false);
	x = 0;
	while (x < game->height)
	{
		game->map[x] = malloc(sizeof(game->width + 1));
		if (!game->map[x])
			return (false);
		x++;
	}
	return (true);
}

// Remplis la map allouee
bool	ft_map_fill(Game *game, char *filename)
{
	int x;
	int y;
	int fd;
	char *gnl;

	if (!game || !filename)
		return (false);
	game->collectibles = 0;
	y = 0;
	fd = fileno(fopen(filename, "r"));
	while ((gnl = get_next_line(fd)) != NULL && y < game->height)
	{
		x = 0;
		while (gnl[x])
		{
			game->map[y][x] = gnl[x];
			if (game->map[y][x] == 'P')
			{
				game->hero.x = x;
				game->hero.y = y;
				game->hero.collectibles = 0;
			}
			else if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
	return (true);
}