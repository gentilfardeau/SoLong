#include "srcs_so_long.h"

// Create the final filepath
void	ft_construct_filepath(char *buffer, char *path, char *character,
		char *action, char *direction, int frame)
{
	char	frame_str[2];

	frame_str[0] = '0' + frame;
	frame_str[1] = '\0';
	buffer[0] = '\0';
	strcpy(buffer, path);
	strcat(buffer, character);
	strcat(buffer, action);
	strcat(buffer, direction);
	strcat(buffer, frame_str);
	strcat(buffer, ".xpm");
}

// Load the images with final filepath
void	ft_set_load_hero(Game *game, char *path, char **character,
		char **actions)
{
	int		height;
	int		width;
	char	filepath_l[PATH_LENGTH];
	char	filepath_r[PATH_LENGTH];
	int		y;
	int		frame;

	frame = 0;
	while (frame < 4)
	{
		y = 0;
		while (y < 3)
		{
			ft_construct_filepath(filepath_l, path, character[game->choice],
				actions[y], "l", frame + 1);
			ft_construct_filepath(filepath_r, path, character[game->choice],
				actions[y], "r", frame + 1);
			if (y == 0)
			{
				game->hero.img_idle_l[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_l, &width, &height);
				game->hero.img_idle_r[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_r, &width, &height);
			}
			if (y == 1)
			{
				game->hero.img_walking_l[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_l, &width, &height);
				game->hero.img_walking_r[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_r, &width, &height);
			}
			if (y == 2)
			{
				game->hero.img_jump_l[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_l, &width, &height);
				game->hero.img_jump_r[frame] = mlx_xpm_file_to_image(game->mlx,
						filepath_r, &width, &height);
			}
			y++;
		}
		frame++;
	}
}

// Initialise le chargement du perso
void	ft_load_hero(Game *game)
{
	char	*character[3];
	char	*actions[3];
	char	*path;

		path = NULL;
	if (game->size == 32)
		path = "assets/GAME_x32/";
	else if (game->size == 64)
		path = "assets/GAME_x64/";
	actions[0] = "idle_";
	actions[1] = "walk_";
	actions[2] = "jump_";
	character[0] = "PINK/";
	character[1] = "DUDE/";
	character[2] = "OWLET/";
	ft_set_load_hero(game, path, character, actions);
}
