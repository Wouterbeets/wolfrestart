/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:05:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/17 20:04:00 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_put_in_img(t_data *d, float dist, int color, int col)
{
	d->x = col;
	d->y = HEIGHT - gap;
	while (d->y > gap)
	{
		ft_pixel_to_img(d->bg->data, d, color);
		d->y--;
	}
}

void	raycast(t_data *d)
{
	t_raycast	r;

	r.dist = 0;
	r.degrees = d->dir;
	r.col = 0;
	r.fov = FOV;
	r.x = d->userx;
	r.y = d->usery;
	while (r.col  <= WIDTH)
	{
		while (d->map[r.y / BLOCKSIZE][r.x / BLOCKSIZE])
		{
			r.rad = r.degrees * RAD;
			r.x = d->userx + cos(r.rad) * r.dist;
			r.y = d->usery + sin(r.rad) * r.dist;
			r.dist += PRECISION;
			if (*d->map[r.y / BLOCKSIZE][r.x / BLOCKSIZE] == d->info->wall)
				break;
		}
/*		ft_putstr("r.distance at angle ");
		ft_putnbr(r.degrees);
		ft_putstr(" = ");
		ft_putnbr(r.dist);
		ft_putstr(" = ");
		ft_putnbr(r.dist / BLOCKSIZE);
		ft_putstr(" blocks ");
		ft_putstr("\t x = ");
		ft_putnbr(d->userx);
		ft_putstr(" y = ");
		ft_putnbr(d->usery);
		ft_putstr(" \n");
*/
		ft_put_in_img(d, r.dist, YELLOW, r.col);
		r.dist = 0;
		r.x = d->userx;
		r.y = d->usery;
		r.degrees += r.fov / WIDTH;
		r.col++;
	}
}

void	add_walls(t_data *d)
{
	raycast(d);
}
/*
*/
