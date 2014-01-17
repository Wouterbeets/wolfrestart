/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 19:58:32 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/13 20:18:30 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**ft_fill_map(char *line, t_map *info)
{
	int		*tmp;
	int		**map;
	char	**maptext;
	int		i;

	i = 0;
	tmp = (int *)malloc((info->x + 1) *sizeof(int));
	map = (int **)malloc((info->x + 1) *sizeof(int *));
	maptext = ft_strsplit(line, ' ');
	while (i < info->x)
	{
		tmp[i] = ft_atoi(maptext[i]);
		map[i] = &tmp[i];
		i++;
	}
	map[i] = NULL;
	free(maptext);
	return (map);
}

void		ft_fill_map_info(char *line, t_map *info)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	info->x = ft_atoi(tab[0]);
	info->y = ft_atoi(tab[1]);
	info->name = ft_strdup(tab[2]);
	info->wall = ft_atoi(tab[3]);
	info->empty = ft_atoi(tab[4]);
	info->start = ft_atoi(tab[5]);
	free(tab);
	free(line);
}

int		***ft_get_map(int ac, char **av, t_map *info)
{
	int		fd;
	char	*line;
	int		***map;
	int		i;

	i = 0;
	fd = open(av[1], O_RDWR);
	map = NULL;
	if (ac == 2)
	{
		if (get_next_line(fd, &line) > 0)
			ft_fill_map_info(line, info);
		map =  (int ***)malloc((info->y + 1) * sizeof(int **));
		while (get_next_line(fd, &line) > 0)
		{
			map[i] = (int **)malloc(info->x * sizeof(int *));
			map[i] = ft_fill_map(line, info);
			i++;
			free(line);
		}
		map[i] = NULL;
	}
	return (map);
}

