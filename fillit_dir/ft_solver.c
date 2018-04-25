/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:42 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/05 13:09:32 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char **map, t_coord *list, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[list->arr_y[i] + y][list->arr_x[i] + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_fill(char **map, t_coord *list, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[list->arr_y[i] + y][list->arr_x[i] + x] == '.')
			map[list->arr_y[i] + y][list->arr_x[i] + x] = list->index;
		else if (map[list->arr_y[i] + y][list->arr_x[i] + x] != '.')
			map[list->arr_y[i] + y][list->arr_x[i] + x] = '.';
		i++;
	}
	return (map);
}

int		ft_genmap(char **map, t_coord *list, int size_map)
{
	int x;
	int y;

	if (!list)
		return (1);
	y = -1;
	while (++y < size_map)
	{
		x = -1;
		while (++x < size_map)
		{
			if ((ft_check(map, list, x, y)) == 1)
			{
				map = ft_fill(map, list, x, y);
				if ((ft_genmap(map, list->next, size_map)) == 1)
					return (1);
				map = ft_fill(map, list, x, y);
			}
		}
	}
	return (0);
}

char	**ft_createmap(char **map, int size)
{
	int i;

	i = -1;
	if (map)
	{
		while (++i < (size - 1))
		{
			ft_bzero(map[i], size - 1);
			free(map[i]);
		}
		free(map);
	}
	i = -1;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (++i < size)
	{
		if (!(map[i] = ft_strnew(size)))
			return (0);
		ft_memset(map[i], '.', size);
	}
	if (!(map[i] = ft_strnew(size)))
		return (0);
	return (map);
}

void	ft_solver(t_coord *list)
{
	char	**map;
	int		i;
	int		j;
	int		size;

	map = NULL;
	size = ft_initsizemap(list);
	map = ft_createmap(map, size);
	while (!(ft_genmap(map, list, size)))
		map = ft_createmap(map, ++size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
