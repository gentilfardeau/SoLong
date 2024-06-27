#include "utils_so_long.h"

void	mlx_img_win(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
}