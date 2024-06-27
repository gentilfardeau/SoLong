#include "srcs_so_long.h"

bool	ft_measure_map(char *filename, Game *game)
{
	int		height;
	int		width;
	int		fd;
	char	*gnl;

	fd = fileno(fopen(filename, "r"));
	height = 0;
	while ((gnl = get_next_line(fd)) != NULL)
	{
		width = 0;
		while (gnl[width])
		{
			if (gnl[width] == '\n')
			{
				if (height == 0)
					game->width = width;
				else if (height != 0 && game->width != width)
					return (false);
			}
			width++;
		}
		height++;
	}
	free(gnl);
	game->height = height;
	return (true);
}

bool	ft_format_check(char *str)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	i = ft_strlen(str) - 1;
	j = ft_strlen(ber) - 1;
	if (i < 4)
		return (false);
	while (ber[j])
	{
		if (ber[j] != str[i])
			return (false);
		j--;
		i--;
	}
	return (true);
}

bool	ft_map_init(Game *game)
{
	int	i;

	i = 0;
	game->map = malloc(game->height * sizeof(char *));
	if (!game->map)
		return (false);
	while (i < game->height)
	{
		game->map[i] = malloc(sizeof(game->width) + 1);
		if (!game->map[i])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_parsing(Game *game, char *filename)
{
	if (!ft_format_check(filename))
		return (false);
	if (!ft_measure_map(filename, game))
		return (false);
	ft_map_init(game);
	ft_map_fill(game, filename);
	return (true);
}