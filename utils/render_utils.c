#include "utils_so_long.h"

void	ft_load_idle(Game *game, int width, int height)
{
	game->hero.img_idle_r[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_r1.xpm", &width, &height);
	game->hero.img_idle_r[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_r2.xpm", &width, &height);
	game->hero.img_idle_r[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_r3.xpm", &width, &height);
	game->hero.img_idle_r[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_r4.xpm", &width, &height);
	game->hero.img_idle_l[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_l1.xpm", &width, &height);
	game->hero.img_idle_l[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_l2.xpm", &width, &height);
	game->hero.img_idle_l[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_l3.xpm", &width, &height);
	game->hero.img_idle_l[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/IDLE/idle_l4.xpm", &width, &height);
}

void	ft_load_walk(Game *game, int width, int height)
{
	game->hero.img_walking_r[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_r1.xpm", &width, &height);
	game->hero.img_walking_r[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_r2.xpm", &width, &height);
	game->hero.img_walking_r[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_r3.xpm", &width, &height);
	game->hero.img_walking_r[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_r4.xpm", &width, &height);
	game->hero.img_walking_l[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_l1.xpm", &width, &height);
	game->hero.img_walking_l[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_l2.xpm", &width, &height);
	game->hero.img_walking_l[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_l3.xpm", &width, &height);
	game->hero.img_walking_l[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/WALKING/walking_l4.xpm", &width, &height);
}

void	ft_load_jump(Game *game, int width, int height)
{
	game->hero.img_jump_r[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_r1.xpm", &width, &height);
	game->hero.img_jump_r[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_r2.xpm", &width, &height);
	game->hero.img_jump_r[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_r3.xpm", &width, &height);
	game->hero.img_jump_r[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_r4.xpm", &width, &height);
	game->hero.img_jump_l[0] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_l1.xpm", &width, &height);
	game->hero.img_jump_l[1] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_l2.xpm", &width, &height);
	game->hero.img_jump_l[2] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_l3.xpm", &width, &height);
	game->hero.img_jump_l[3] = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/HERO/JUMP/jump_l4.xpm", &width, &height);
}