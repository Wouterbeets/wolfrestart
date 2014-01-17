/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:17:02 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/17 15:20:11 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		expose_hook(t_data *d)
{
	get_user_pos(d);
	make_bg(d);
	add_walls(d);
	mlx_put_image_to_window(d->mlx, d->win, d->bg->ptr, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	d->i = 0;
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(":");
	ft_putnbr(y);
	ft_putstr(")\n");
	return (0);
}
/*
int		key_hook(int keycode, t_data *d)
{
	d->i = 0;
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
		ft_is_up(d);
	if (keycode == KEY_DOWN)
		ft_is_down(d);
	if (keycode == KEY_LEFT)
		ft_is_left(d);
	if (keycode == KEY_RIGHT)
		ft_is_right(d);
	ft_putnbr(d->usery);
	return (0);
}*/

int		key_press(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
		d->save[0] = 1;
	if (keycode == KEY_DOWN)
		d->save[1] = 1;
	if (keycode == KEY_LEFT)
		d->save[2] = 1;
	if (keycode == KEY_RIGHT)
		d->save[3] = 1;
	return (0);
}

int		key_release(int keycode, t_data *d)
{
	if (keycode == KEY_UP)
		d->save[0] = 0;
	if (keycode == KEY_DOWN)
		d->save[1] = 0;
	if (keycode == KEY_LEFT)
		d->save[2] = 0;
	if (keycode == KEY_RIGHT)
		d->save[3] = 0;
	return (0);
}

int		loop_hook(t_data *d)
{
	if (d->save[0] == 1)
		ft_is_up(d);
	if (d->save[1] == 1)
		ft_is_down(d);
	if (d->save[2] == 1)
		ft_is_left(d);
	if (d->save[3] == 1)
		ft_is_right(d);
	return (0);
}

void	ft_mlx(t_data *d)
{
	t_img	bg;
	t_img	img;

	d->img = &img;
	d->bg = &bg;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, d->info->name);
	ft_create_image(d);
	d->userx = 0;
	d->usery = 0;
	d->dir = 0;
	mlx_hook(d->win, 2, 1, key_press, d);
	mlx_hook(d->win, 3, 2, key_release, d);
	mlx_loop_hook(d->mlx, loop_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_loop(d->mlx);
}
