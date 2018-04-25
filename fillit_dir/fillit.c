/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:43:38 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/09 11:04:58 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_read_file(char *av)
{
	int		fd;
	int		i;
	char	*str;
	char	buf[1];

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1 || read(fd, buf, 1) == -1)
		return ("error\n");
	else
		i++;
	while (read(fd, buf, 1))
		i++;
	close(fd);
	str = (char *)malloc(i + 1);
	if (!(fd = open(av, O_RDONLY)))
		return (0);
	i = 0;
	while (read(fd, buf, 1))
		str[i++] = buf[0];
	str[i] = '\0';
	close(fd);
	return (str);
}

int		ft_check_map(char *str, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[++i] != '\0')
	{
		if (++j % 5 == 0 && str[i] == '\n')
			continue ;
		else if (j == 21)
		{
			if (str[i] != '\n')
				return (0);
			j = 0;
			if (k != 4)
				return (0);
			k = 0;
		}
		else if (str[i] == '#')
			k++;
		else if ((j % 5 == 0 && str[i] != '\n') || str[i] != '.')
			return (0);
	}
	return ((j == 20 && k == 4 && i <= 545) ? 1 : 0);
}

int		ft_check_1(char *str, int i, int count, int j)
{
	while (str[++i] != '\0')
	{
		j = -1;
		count = 0;
		while (++j < 20 && str[i] != '\0')
		{
			if (str[i] == '#')
			{
				if ((j - 1) >= 0 && str[i - 1] == '#')
					count++;
				if ((j - 5) >= 0 && str[i - 5] == '#')
					count++;
				if ((j + 1) <= 18 && str[i + 1] == '#')
					count++;
				if ((j + 5) <= 18 && str[i + 5] == '#')
					count++;
			}
			i++;
		}
		if (count < 6 || count > 8)
			return (0);
		if (str[i] == '\0')
			return (1);
	}
	return (1);
}

int		ft_check_validation(char *str)
{
	int i;
	int count;
	int j;

	i = -1;
	count = 0;
	j = 0;
	if ((ft_check_map(str, i)) == 0)
		return (0);
	if ((ft_check_1(str, i, count, j)) == 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	char	*str;
	t_coord *list;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	str = ft_read_file(av[1]);
	if (ft_strcmp(str, "error\n") == 0 ||
	(ft_check_validation(str) == 0 && (str = "error\n")))
	{
		ft_putstr(str);
		return (0);
	}
	list = ft_coords(str);
	ft_solver(list);
	return (1);
}
