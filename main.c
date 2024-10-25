/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:09:43 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/24 14:41:21 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 500

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_data;

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
	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			img_data[y * WIN_WIDTH + x] = x % 256 * 0x10000 + y % 256 * 0x100;
		}
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);



	// set key_hook
	mlx_key_hook(data.win, key_hook, &data);
	// when the cross button is clicked, close the window
	mlx_hook(data.win, 17, 0, close_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}