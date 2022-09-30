/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:19:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/09/30 09:51:56 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_win(t_data *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pix / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(t_coord start, t_coord end, t_data *map)
{
	t_coord	delta;
	t_coord	cur;
	t_coord	inc;
	int		p;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	if (abs(delta.x) > abs(delta.y))
	{
		if (start.x > end.x)
		{
			ft_swap(&start.x, &end.x);
			ft_swap(&start.y, &end.y);
			delta.x *= -1;
			delta.y *= -1;
		}
		inc.y = 1;
		if (delta.y < 0)
		{
			inc.y = -1;
			delta.y *= -1;
		}
		cur = start;
		p = (2 * delta.y) - delta.x;
		while (cur.x <= end.x)
		{
			pixel_put(&map->img, cur.x, cur.y, 0xFFC0CB);
			if (p < 0)
			{
				p += 2 * delta.y;
			}
			else
			{
				p += 2 * (delta.y - delta.x);
				cur.y += inc.y;
			}
			cur.x++;
		}
	}
	else
	{
		if (start.y > end.y)
		{
			ft_swap(&start.x, &end.x);
			ft_swap(&start.y, &end.y);
			delta.x *= -1;
			delta.y *= -1;
		}
		inc.x = 1;
		if (delta.x < 0)
		{
			inc.x = -1;
			delta.x *= -1;
		}
		cur = start;
		p = (2 * delta.x) - delta.y;
		while (cur.y < end.y)
		{
			pixel_put(&map->img, cur.x, cur.y, 0xFFC0CB);
			if (p < 0)
			{
				p += 2 * delta.x;
			}
			else
			{
				p += 2 * (delta.x - delta.y);
				cur.x += inc.x;
			}
			cur.y++;
		}
	}
}