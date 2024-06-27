#include "srcs_so_long.h"

// Gere les actions dans le menu
int	ft_keypress_menu(int keycode, Menu *menu)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	else if (keycode == KEY_A && menu->cursor_position > 0)
		menu->cursor_position--;
	else if (keycode == KEY_D && menu->cursor_position < 2)
		menu->cursor_position++;
	else if (keycode == KEY_SPACE)
	{
		menu->game->choice = menu->cursor_position;
		printf("Choice n %d || Initializing game...\n", menu->game->choice);
		ft_game(menu->game);
		mlx_destroy_window(menu->mlx, menu->window);
		return (1);
	}
	return (0);
}

// Charge les monstres dans le menu
void	ft_load_monster(Menu *menu, int width, int height)
{
	menu->dude_monster[0] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/dude1.xpm", &width, &height);
	menu->dude_monster[1] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/dude2.xpm", &width, &height);
	menu->dude_monster[2] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/dude3.xpm", &width, &height);
	menu->dude_monster[3] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/dude4.xpm", &width, &height);
	menu->owlet_monster[0] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/owlet1.xpm", &width, &height);
	menu->owlet_monster[1] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/owlet2.xpm", &width, &height);
	menu->owlet_monster[2] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/owlet3.xpm", &width, &height);
	menu->owlet_monster[3] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/owlet4.xpm", &width, &height);
	menu->pink_monster[0] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/pink1.xpm", &width, &height);
	menu->pink_monster[1] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/pink2.xpm", &width, &height);
	menu->pink_monster[2] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/pink3.xpm", &width, &height);
	menu->pink_monster[3] = mlx_xpm_file_to_image(menu->mlx,
			"assets/MENU/pink4.xpm", &width, &height);
}

void	ft_menu_load(Menu *menu)
{
	int	width;
	int	height;

	menu->ticks = 0;
	menu->displayed_img = 0;
	menu->total_frame = 4;
	menu->background = mlx_xpm_file_to_image(menu->mlx, "assets/MENU/MENU.xpm",
			&width, &height);
	menu->cursor = mlx_xpm_file_to_image(menu->mlx, "assets/MENU/cursor.xpm",
			&width, &height);
	ft_load_monster(menu, width, height);
}

void	ft_menu_update(Menu *menu)
{
	menu->ticks++;
	if (menu->ticks >= ANIM_SPEED)
	{
		menu->ticks = 0;
		menu->displayed_img = (menu->displayed_img + 1) % menu->total_frame;
	}
}

void	ft_render_monsters(Menu *menu)
{
	mlx_put_image_to_window(menu->mlx, menu->window,
		menu->pink_monster[menu->displayed_img], 57, 207);
	mlx_put_image_to_window(menu->mlx, menu->window,
		menu->owlet_monster[menu->displayed_img], 450, 207);
	mlx_put_image_to_window(menu->mlx, menu->window,
		menu->dude_monster[menu->displayed_img], 254, 207);
}

void	ft_render_cursor(Menu *menu)
{
	if (menu->cursor_position == 0)
		mlx_put_image_to_window(menu->mlx, menu->window, menu->cursor, 28, 250);
	if (menu->cursor_position == 1)
		mlx_put_image_to_window(menu->mlx, menu->window, menu->cursor, 228,
			250);
	if (menu->cursor_position == 2)
		mlx_put_image_to_window(menu->mlx, menu->window, menu->cursor, 422,
			250);
}

// Gere le render de la fenetre
int	ft_render_menu(Menu *menu)
{
	usleep(3000);
	ft_menu_update(menu);
	mlx_put_image_to_window(menu->mlx, menu->window, menu->background, 0, 0);
	ft_render_monsters(menu);
	ft_render_cursor(menu);
	return (0);
}

// Check les actions
void	ft_menu_key_hook(Menu *menu)
{
	mlx_key_hook(menu->window, ft_keypress_menu, menu);
}

// Loop pour actualiser la fenetre
void	ft_menu_loop(Menu *menu)
{
	mlx_loop_hook(menu->mlx, ft_render_menu, menu);
	mlx_loop(menu->mlx);
}

int	ft_menu(Menu *menu)
{
	menu->height = 400;
	menu->width = 600;
	menu->cursor_position = 0;
	menu->mlx = mlx_init();
	menu->window = mlx_new_window(menu->mlx, menu->width, menu->height, "MENU");
	ft_menu_load(menu);
	ft_menu_key_hook(menu);
	ft_menu_loop(menu);
	return (false);
}