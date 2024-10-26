/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:09:43 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 19:31:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 0xFF1B)
	{
		printf("ESC key is pressed\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

// cross button
int	close_hook(t_data *data)
{
	printf("cross button is clicked\n");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}


int	main(void)
{
	t_data	data;

	// initialize mlx
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		perror("mlx_init");
		exit(1);
	}
	// create a window
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello, world!");
	if (data.win == NULL)
	{
		perror("mlx_new_window");
		exit(1);
	}
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (data.img == NULL)
	{
		perror("mlx_new_image");
		exit(1);
	}

	// draw a red rectangle
	int *img_data;
	int size_line;
	int bpp;
	int endian;
	img_data = (int *)mlx_get_data_addr(data.img, &bpp, &size_line, &endian);
	printf("bpp: %d\n", bpp);
	printf("size_line: %d\n", size_line);
	printf("endian: %d\n", endian);
	t_point p1 = {100, 100, (t_color){0, 255, 0, 0}};
	t_point p2 = {200, 100, (t_color){0, 0, 255, 0}};
	t_point p3 = {150, 200, (t_color){0, 0, 0, 255}};
	draw_line(&data, p1, p2, img_data);
	draw_line(&data, p2, p3, img_data);
	draw_line(&data, p3, p1, img_data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);



	// set key_hook
	mlx_key_hook(data.win, key_hook, &data);
	// when the cross button is clicked, close the window
	mlx_hook(data.win, 17, 0, close_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}