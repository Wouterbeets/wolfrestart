/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 11:16:44 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/17 16:54:15 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int		pos_is_wall(int x, int y, t_data *d)
{
	return (*d->map[y][x] == d->info->wall);
}

void	ft_is_up(t_data *d)
{
	int	tmpx;
	int	tmpy;

	tmpx = d->userx;
	tmpy = d->usery;
	d->usery = d->usery + sin((d->dir + FOV / 2) * RAD) * (SPEED);
	d->userx = d->userx + cos((d->dir + FOV / 2) * RAD) * (SPEED);
	if (pos_is_wall(d->userx / BLOCKSIZE, d->usery / BLOCKSIZE, d))
	{
		d->userx = tmpx;
		d->usery = tmpy;
	}
	make_bg(d);
	raycast(d);
	mlx_put_image_to_window(d->mlx, d->win, d->bg->ptr, 0, 0);
}

void	ft_is_down(t_data *d)
{
	int	tmpx;
	int	tmpy;

	tmpx = d->userx;
	tmpy = d->usery;
	d->usery = d->usery - sin((d->dir + FOV / 2) * RAD) * (SPEED);
	d->userx = d->userx - cos((d->dir + FOV / 2) * RAD) * (SPEED);
	if (pos_is_wall(d->userx / BLOCKSIZE, d->usery / BLOCKSIZE, d))
	{
		d->userx = tmpx;
		d->usery = tmpy;
	}
		make_bg(d);
	raycast(d);
	mlx_put_image_to_window(d->mlx, d->win, d->bg->ptr, 0, 0);
}

void	ft_is_left(t_data *d)
{
	d->dir = d->dir - 5;
	make_bg(d);
	raycast(d);
	mlx_put_image_to_window(d->mlx, d->win, d->bg->ptr, 0, 0);
}

void	ft_is_right(t_data *d)
{
	d->dir = d->dir + 5;
	make_bg(d);
	raycast(d);
	mlx_put_image_to_window(d->mlx, d->win, d->bg->ptr, 0, 0);
}
