/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:13:32 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/15 15:53:36 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_map(int ***map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			ft_putnbr(*map[i][j]);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		***map;
	t_map	info;
	t_data	d;

	if ((map = ft_get_map(ac, av, &info)))
	{
		d.map = map;
		d.info = &info;
		d.bgfill = 0;
		ft_mlx(&d);
	}
	return (0);
}
