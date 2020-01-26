/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_windows.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:44:53 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 11:06:38 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_key_press(int key, t_cub *cub)
{
	dprintf(1, GREEN);
	dprintf(1, "KEY_PRESS = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_DOWN)
		cub->key.down = 1;
	if (key == L_RIGHT)
		cub->key.right = 1;
	if (key == L_LEFT)
		cub->key.left = 1;
	if (key == L_UP)
		cub->key.up = 1;
	if (key == ESCAPE)
		exit(EXIT_SUCCESS);
	if (cub->key.down)
	{
		cub->cast.one = (int)(cub->cast.pos_x - cub->cast.dir_x * cub->cast.move_speed);
		cub->cast.tho = (int)cub->cast.pos_y;
    	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
			cub->cast.pos_x -= cub->cast.dir_x * cub->cast.move_speed;
		cub->cast.one = (int)cub->cast.pos_x;
		cub->cast.tho = (int)(cub->cast.pos_y - cub->cast.dir_y * cub->cast.move_speed);
    	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
			cub->cast.pos_y -= cub->cast.dir_y * cub->cast.move_speed;
	}
	if (cub->key.right)
	{
    	cub->cast.old_dir_x = cub->cast.dir_x;
    	cub->cast.dir_x = cub->cast.dir_x * cos(-cub->cast.rotation_speed) - cub->cast.dir_y * sin(-cub->cast.rotation_speed);
    	cub->cast.dir_y = cub->cast.old_dir_x * sin(-cub->cast.rotation_speed) + cub->cast.dir_y * cos(-cub->cast.rotation_speed);
    	cub->cast.oldcam_plane_x = cub->cast.cam_plane_x;
    	cub->cast.cam_plane_x = cub->cast.cam_plane_x * cos(-cub->cast.rotation_speed) - cub->cast.cam_plane_y * sin(-cub->cast.rotation_speed);
    	cub->cast.cam_plane_y = cub->cast.oldcam_plane_x * sin(-cub->cast.rotation_speed) + cub->cast.cam_plane_y * cos(-cub->cast.rotation_speed);
	}
	if (cub->key.left)
	{
		cub->cast.old_dir_x = cub->cast.dir_x;
		cub->cast.dir_x = cub->cast.dir_x * cos(cub->cast.rotation_speed) - cub->cast.dir_y * sin(cub->cast.rotation_speed);
		cub->cast.dir_y = cub->cast.old_dir_x * sin(cub->cast.rotation_speed) + cub->cast.dir_y * cos(cub->cast.rotation_speed);
		cub->cast.oldcam_plane_x = cub->cast.cam_plane_x;
		cub->cast.cam_plane_x = cub->cast.cam_plane_x * cos(cub->cast.rotation_speed) - cub->cast.cam_plane_y * sin(cub->cast.rotation_speed);
		cub->cast.cam_plane_y = cub->cast.oldcam_plane_x * sin(cub->cast.rotation_speed) + cub->cast.cam_plane_y * cos(cub->cast.rotation_speed);
	}
	if (cub->key.up)
	{
		cub->cast.one = (int)(cub->cast.pos_x + cub->cast.dir_x * cub->cast.move_speed);
		cub->cast.tho = (int)cub->cast.pos_y;
     	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
			cub->cast.pos_x += cub->cast.dir_x * cub->cast.move_speed;
		cub->cast.one = (int)cub->cast.pos_x;
		cub->cast.tho = (int)cub->cast.pos_y + cub->cast.dir_y * cub->cast.move_speed;
    	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
	  		cub->cast.pos_y += cub->cast.dir_y * cub->cast.move_speed;
	}
	//mlx_pixel_put(cub->mlx, cub->windows, cub->x, cub->y, OXRESET);
	return (0);
}

int		sj_key_release(int key, t_cub *cub)
{
	dprintf(1, RED);
	dprintf(1, "KEY_RELEA = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_DOWN)
		cub->key.down = 0;
	if (key == L_RIGHT)
		cub->key.right = 0;
	if (key == L_LEFT)
		cub->key.left = 0;
	if (key == L_UP)
		cub->key.up = 0;
	return (0);
}

int		sj_close()
{
	exit(EXIT_SUCCESS);
}

float	sj_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	sj_creat_new_windows(t_cub *cub)
{
	dprintf(2, "\nRES \t= [%d]\n", cub->res_x);
	cub->key.right = 0;
	cub->key.left = 0;
	cub->key.down = 0;
	cub->key.up = 0;
	cub->mlx = mlx_init();
	cub->windows = mlx_new_window(cub->mlx, cub->res_x, cub->res_y, "Cub3D");
	mlx_do_key_autorepeaton(cub->mlx);

	
	/* TEST */

	cub->cast.dir_x = -1; // ITS N of POS // (DEGRES)
	cub->cast.dir_y = 0; // ITS N of POS // (DEGRES)
	cub->cast.cam_plane_x = 0;
	cub->cast.cam_plane_y = 0.66;
	cub->cast.time = 0;
	cub->cast.oldtime = 0;
	cub->cast.x = 0;

	/* DDA START */
	cub->cast.pos_x = cub->dbl_pos_x;
	cub->cast.pos_y = cub->dbl_pos_y;
	cub->cast.size_max_x = cub->res_x;
	dprintf(2, "\ncub->cast.pos_x \t= [%f]\n", cub->cast.pos_x);
	dprintf(2, "\ncub->cast.size_max_x \t= [%f]\n", cub->cast.size_max_x);
	dprintf(2, "cub->cast.pos_y \t= [%f]\n", cub->cast.pos_y);
	while (1)
	{
		while (cub->cast.x <= cub->cast.size_max_x)
		{
			cub->cast.cameraX = 2 * cub->cast.x / cub->cast.size_max_x - 1;
			cub->cast.raydir_x = cub->cast.dir_x + cub->cast.cam_plane_x * cub->cast.cameraX;
			cub->cast.raydir_y = cub->cast.dir_y + cub->cast.cam_plane_y * cub->cast.cameraX;
			cub->cast.mapx = cub->cast.pos_x;
			cub->cast.mapy = cub->cast.pos_y;
			cub->cast.deltadistx = sj_abs(1 / cub->cast.raydir_x);
			cub->cast.deltadisty = sj_abs(1 / cub->cast.raydir_y);
			cub->cast.hit = 0;
			if (cub->cast.raydir_x < 0)
			{
				cub->cast.stepX = -1;
				cub->cast.sidedistx = (cub->cast.pos_x - cub->cast.mapx) * cub->cast.deltadistx;
			}
			else
			{
				cub->cast.stepX = 1;
				cub->cast.sidedistx = (cub->cast.mapx + 1.0 - cub->cast.pos_x) * cub->cast.deltadistx;
			}
			if (cub->cast.raydir_y < 0)
			{
				cub->cast.stepY = -1;
				cub->cast.sidedisty = (cub->cast.pos_y - cub->cast.mapy) * cub->cast.deltadisty;
			}
			else
			{
				cub->cast.stepY = 1;
				cub->cast.sidedisty = (cub->cast.mapy + 1.0 - cub->cast.pos_y) * cub->cast.deltadisty;
			}
			while (cub->cast.hit == 0)
			{
				if (cub->cast.sidedistx < cub->cast.sidedisty)
				{
					cub->cast.sidedistx += cub->cast.deltadistx;
					cub->cast.mapx += cub->cast.stepX;
					cub->cast.side = 0;
				}
				else
				{
					cub->cast.sidedisty += cub->cast.deltadisty;
					cub->cast.mapy += cub->cast.stepY;
					cub->cast.side = 1;
				}
				if (cub->tab_map[cub->cast.mapy][cub->cast.mapx] > '0')
					cub->cast.hit = 1;
			}
			/* DDA FINISH */

			dprintf(2, "X \t\t= [%f]\n", cub->cast.x);
			dprintf(2, "cub->cast.mapx \t= [%d]\n", cub->cast.mapx);
			dprintf(2, "cub->cast.mapy \t= [%d]\n", cub->cast.mapy);
			dprintf(2, "cub->cast.pos_x \t= [%f]\n", cub->cast.pos_x);
			dprintf(2, "STPX \t\t= [%d]\n", cub->cast.stepX);
			dprintf(2, "RAYX \t\t= [%f]\n", cub->cast.raydir_x);
			dprintf(2, "cub->cast.side \t= [%d]\n\n", cub->cast.side);
			if (cub->cast.side == 0)
				cub->cast.perpwalldist = (cub->cast.mapx - cub->cast.pos_x + (1 - cub->cast.stepX) / 2) / cub->cast.raydir_x;
			else
				cub->cast.perpwalldist = (cub->cast.mapy - cub->cast.pos_y + (1 - cub->cast.stepY) / 2) / cub->cast.raydir_y;
			dprintf(2, "PERPEN \t\t= [%f]\n\n", cub->cast.perpwalldist);
			cub->cast.lineheight = (long int)(HEIGHT / cub->cast.perpwalldist);
			cub->cast.drawstart = -cub->cast.lineheight / 2 + HEIGHT / 2;
			if (cub->cast.drawstart < 0)
				cub->cast.drawstart = 0;
			dprintf(2, "LINEH \t\t= [%d]\n\n", cub->cast.lineheight);
			cub->cast.drawend = cub->cast.lineheight / 2 + HEIGHT / 2;
			if (cub->cast.drawend >= HEIGHT)
				cub->cast.drawend = HEIGHT - 1;
			dprintf(2, "START \t\t= [%d]\n", cub->cast.drawstart);
			dprintf(2, "END \t\t= [%d]\n\n===============================\n\n", cub->cast.drawend);
			cub->cast.color = OXRED;
			if (cub->cast.side == 1)
				cub->cast.color = OXBLUE;
			while (cub->cast.drawstart < cub->cast.drawend)
				mlx_pixel_put(cub->mlx, cub->windows, cub->cast.x, cub->cast.drawstart++, cub->cast.color);
			cub->cast.x++;
		}

		/* FPS */

		cub->cast.oldtime = cub->cast.time;
		cub->cast.time = 60;
		cub->cast.frametime = (cub->cast.time - cub->cast.oldtime) / 1000.0;
		//mlx_clear_window(cub->mlx, cub->windows);
		cub->cast.str = ft_itoa(cub->cast.frametime);
		mlx_string_put(cub->mlx, cub->windows, cub->res_x / 2, cub->res_y, OXRESET, cub->cast.str);
		//mlx_loop(cub->mlx);
		/* SPEED */


		cub->cast.move_speed = cub->cast.frametime * 5.0;
		cub->cast.rotation_speed = cub->cast.frametime * 3.0;
		
		/* MOVE */
		mlx_hook(cub->windows, 2, 0, sj_key_press, cub);
		mlx_hook(cub->windows, 17, 0, sj_close, cub);
		mlx_hook(cub->windows, 3, 0, sj_key_release, cub);

		mlx_loop(cub->mlx);
	}
}

	// while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
	// 	mlx_pixel_put(cub->mlx, cub->windows, i++, 540, OXRESET);
	// i = cub->res_y / 2;
	// while (y < cub->res_x / 2 + cub->res_x / 2 / 2)
	// {
	// 	while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
	// 		mlx_pixel_put(cub->mlx, cub->windows, y, i++, OXRESET);
	// 	y++;
	// 	i = cub->res_y / 2;;
	// width = 0;

	// int	wall;
	// int	width;
	// int	temp_x;
	// int	temp_y;
	// temp_x = cub->init_cub->cast.pos_x;
	// temp_y = cub->init_cub->cast.pos_y;
	// while (cub->tab_map[temp_x][temp_y] != '0')
	// {
	// 	width++;
	// 	if (cub->pos == 'N')
	// 		temp_y++;
	// 	else if (cub->pos == 'S')
	// 		temp_y--;
	// 	else if (cub->pos == 'E')
	// 		temp_x++;
	// 	else if (cub->pos == 'W')
	// 		temp_x--;
	// }
	// while (width)
	// 	mlx_pixel_put(cub->mlx, cub->windows, 0, 0, OXRESET);
	// }