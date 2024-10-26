/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:08:40 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 19:50:40 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

#define WIN_WIDTH 500
#define WIN_HEIGHT 500

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_data;

typedef struct s_trgb
{
	unsigned int	t : 8;
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
}	t_trgb;

typedef union u_color
{
	unsigned int	color;
	t_trgb			rgb;
}	t_color;

typedef struct    s_point
{
    int	x;
    int	y;
    t_color color;
}				t_point;

void	draw_line(t_data *data, t_point p1, t_point p2, int *img_data);

#endif