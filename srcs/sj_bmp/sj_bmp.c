#include "../../include/cub3d.h"

// void	set_bmp(t_cub *cub)
// {
// 	int		size;
// 	int		px;

// 	if (!(C->B = malloc(sizeof(t_bmp))))
// 	{
// 		ft_printf("\033[0;31mError\n__MALLOC_ERROR__\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	if ((C->B->fd = open("./4deepthought/snapshot_cub.bmp",
// 		O_WRONLY | S_IRWXU | O_CREAT | O_TRUNC | O_APPEND)) < 0)
// 	{
// 		ft_printf("\033[0;31mError\n__BMPCREAT_FAIL__\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	size = 54 + 4 * C->res_x * C->res_y;
// 	px = 2540 * 39.375;
// 	write(C->B->fd, "BM", 2);
// 	write(C->B->fd, "\66", 1);
// 	ft_putnbr_fd(size, C->B->fd);
// 	write(C->B->fd, "\0\0\0\0\0\0\0\0\0\0\0", 11);
// }

// void	sj_writebmp(t_cub *cub, int color)
// {
// 	if (!C->B->yes)
// 		ft_putnbr_fd(color, C->B->fd);
// }
