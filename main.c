#include "./libft/libft.h"
#include "./include/cub3d.h"

// typedef struct    data_s
// {
// 	void          *mlx_ptr;
// 	void          *mlx_win;
// }                 data_t;

int main(int ac, char **gv)
{
	int		ret;
	// data_t		data;

	// if ((data.mlx_ptr = mlx_init()) == NULL)
	// 	return (EXIT_FAILURE);
	// if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 900, 900, "Hello world")) == NULL)
	// 	return (EXIT_FAILURE);
	// mlx_new_image(data.mlx_ptr, 500,500);
	// mlx_loop(data.mlx_ptr);
	// return (EXIT_SUCCESS);
	ret = sj_cub(ac, gv);
	return (ret);
}
