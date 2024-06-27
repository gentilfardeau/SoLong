#ifndef SO_LONG_H
# define SO_LONG_H

// DIFFERENTES LIBS
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifdef OS_LINUX
#  include <X11/keysym.h>
#  define KEY_ESC XK_Escape
#  define KEY_SPACE XK_space
#  define KEY_W XK_w
#  define KEY_A XK_a
#  define KEY_S XK_s
#  define KEY_D XK_d
#  define KEY_UP XK_Up
#  define KEY_DOWN XK_Down
#  define KEY_LEFT XK_Left
#  define KEY_RIGHT XK_Right
# else
#  define KEY_ESC 53
#  define KEY_SPACE 49
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

# define ANIM_SPEED 60
# define PATH_LENGTH 256

typedef struct
{
	int		x;
	int		y;
	int		collectibles;
	int		displayed_img;
	int		total_frame;
	int		status;
	char	orientation;
	char	offset[3];
	void	*img_idle_l[4];
	void	*img_idle_r[4];
	void	*img_walking_l[4];
	void	*img_walking_r[4];
	void	*img_jump_r[4];
	void	*img_jump_l[4];
}			Hero;

typedef struct
{
	char	**map;
	int		width;
	int		height;
	int		collectibles;
	int		frame;
	int		ticks;
	int		choice;
	int		size;
	void	*mlx;
	void	*window_2;
	void	*img_consum;
	void	*img_wall;
	void	*img_exit;
	void	*img_floor;
	Hero	hero;
}			Game;

typedef struct
{
	int		width;
	int		height;
	void	*window;
	int		ticks;
	int		frame;
	int		displayed_img;
	int		total_frame;
	int		cursor_position;
	void	*dude_monster[4];
	void	*owlet_monster[4];
	void	*pink_monster[4];
	void	*cursor;
	void	*background;
	void	*mlx;
	Game	*game;
}			Menu;

// DIFFERENTS .h
# include "includes/includes_so_long.h"
# include "srcs/srcs_so_long.h"
# include "utils/utils_so_long.h"

#endif // SO_LONG_H
