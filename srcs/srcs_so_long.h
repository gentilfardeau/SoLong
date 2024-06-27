#ifndef SRCS_SO_LONG_H
# define SRCS_SO_LONG_H

# include "../so_long.h"

///////// CHOICE.C ///////////////////////////////////
void	ft_set_load_hero(Game *game, char *path, char **character,
			char **actions);
void	ft_load_hero(Game *game);
///////// EVENTS.C ///////////////////////////////////
void	ft_frame_update(Game *game);
bool	ft_the_end(Game *game, int x, int y);
int		ft_game_update(Game *game);

///////// GAME.C ///////////////////////////////////
bool	ft_game_init(Game *game);
int		ft_game(Game *game);

///////// MAIN.C ///////////////////////////////////
int		main(int argc, char **argv);

///////// MAPS.C ///////////////////////////////////
bool	ft_map_fill(Game *game, char *filename);
bool	ft_map_allocate(Game *game, char *filename);

///////// MENU.C ///////////////////////////////////
int		ft_keypress_menu(int keycode, Menu *menu);
void	ft_menu_key_hook(Menu *menu);
void	ft_load_monster(Menu *menu, int width, int height);
void	ft_menu_load(Menu *menu);
void	ft_menu_update(Menu *menu);
void	ft_render_monsters(Menu *menu);
int		ft_render_menu(Menu *menu);
void	ft_menu_key_hook(Menu *menu);
void	ft_menu_loop(Menu *menu);
int		ft_menu(Menu *menu);

///////// MOVES.C ///////////////////////////////////
void	ft_player_moves(Game *game, int d_x, int d_y);
int		ft_keypress_handle(int keycode, Game *game);

///////// RENDER.C ///////////////////////////////////
void	ft_load_walk(Game *game, int width, int height);
void	ft_load_props(Game *game, int width, int height);
void	ft_hero_load(Game *game, int width, int height);
void	ft_images_load(Game *game);
void	ft_render_hero(Game *game, int x, int y);
void	ft_render(Game *game);

///////// PARSING.C ///////////////////////////////////
bool	ft_measure_map(char *filename, Game *game);
bool	ft_check_format(char *str);
bool	ft_map_init(Game *game);
bool	ft_parsing(Game *game, char *filename);

#endif