/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 04:06:15 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/30 20:18:35 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_bmp(t_cub *cub)
{
	if ((C->bmp->fd = open("./4deepthought/capture.bmp"
		, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 1)
	{
		ft_printf("Error\n__ERROR_BMP__\n");
		ult_i_to_vii(-99, cub);
		close(C->bmp->fd);
		exit(EXIT_SUCCESS);
	}
}

void	sj_init_bpm(t_cub *cub)
{
	C->bmp->width = C->res_x;
	C->bmp->height = C->res_y;
	C->bmp->bitcount = 32;
	C->bmp->width_in_bytes =
		((C->bmp->width * C->bmp->bitcount + 31) / 32) * 4;
	C->bmp->imagesize = C->bmp->width_in_bytes * C->bmp->height;
	C->bmp->bisize = 40;
	C->bmp->bfoffbits = 54;
	C->bmp->filesize = 54 + C->bmp->imagesize;
	C->bmp->biplanes = 1;
	ft_memcpy(C->bmp->header, "BM", 2);
	ft_memcpy(C->bmp->header + 2, &C->bmp->filesize, 4);
	ft_memcpy(C->bmp->header + 10, &C->bmp->bfoffbits, 4);
	ft_memcpy(C->bmp->header + 14, &C->bmp->bisize, 4);
	ft_memcpy(C->bmp->header + 18, &C->bmp->width, 4);
	ft_memcpy(C->bmp->header + 22, &C->bmp->height, 4);
	ft_memcpy(C->bmp->header + 26, &C->bmp->biplanes, 4);
	ft_memcpy(C->bmp->header + 28, &C->bmp->bitcount, 4);
	ft_memcpy(C->bmp->header + 34, &C->bmp->imagesize, 4);
	sj_bmp(cub);
}

void	sj_write_bmp(t_cub *cub)
{
	int y;

	y = C->res_y;
	write(C->bmp->fd, C->bmp->header, 54);
	while (y)
	{
		write(C->bmp->fd, C->img_data + (y * C->res_x), C->res_x * 4);
		y--;
	}
	close(C->bmp->fd);
	C->bmp->reset = 0;
}
