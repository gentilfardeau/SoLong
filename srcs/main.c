#include "srcs_so_long.h"

int main(int argc, char **argv)
{
	Game game;
	Menu menu;

	menu.game = &game;
	if (argc != 2 || !argv)
		return (1);
	if (!ft_parsing(&game, argv[1]))
		return (1);
	if (ft_menu(&menu))
		return (0);
	return (0);
}