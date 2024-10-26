/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:32:32 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 19:32:13 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	draw_line(t_data *data, t_point p1, t_point p2, int *img_data)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    // int dc = p2.color - p1.color;
    int x = p1.x;
    int y = p1.y;
    int c;
    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // float c_inc = (float)dc / step;
    int i = 0;

    printf("dx: %3d, dy: %3d, step: %3d\n", dx, dy, step);
    printf("p1: x: %3d, y: %3d, [r: %3d, g: %3d, b: %3d]\n", p1.x, p1.y, p1.color.r, p1.color.g, p1.color.b);
    printf("p2: x: %3d, y: %3d, [r: %3d, g: %3d, b: %3d]\n", p2.x, p2.y, p2.color.r, p2.color.g, p2.color.b);
    while (i <= step)
    {
        int r = p1.color.r + (p2.color.r - p1.color.r) * i / step;
        int g = p1.color.g + (p2.color.g - p1.color.g) * i / step;
        int b = p1.color.b + (p2.color.b - p1.color.b) * i / step;
        c = r << 16 | g << 8 | b;
        img_data[y * WIN_WIDTH + x] = c;
        x = (p1.x * (step - i) + p2.x * i) / step;
        y = (p1.y * (step - i) + p2.y * i) / step;
        i++;
        printf("x: %3d, y: %3d, [r: %3d, g: %3d, b: %3d]\n", x, y, c >> 16, c >> 8 & 0xFF, c & 0xFF);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}