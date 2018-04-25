/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:07:49 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/05 13:08:14 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_initsizemap(t_coord *list)
{
	int	i;
	int size;

	size = 0;
	while (list)
	{
		i = -1;
		while (++i < size)
		{
			if (size < list->arr_y[i])
				size = list->arr_y[i] + 1;
			if (size < list->arr_x[i])
				size = list->arr_x[i] + 1;
		}
		list = list->next;
	}
	return (size);
}

t_coord		*ft_pushback(t_coord *head)
{
	char	index;

	index = 'A';
	if (head)
	{
		index++;
		while (head->next)
		{
			head = head->next;
			index++;
		}
		head->next = (t_coord*)malloc(sizeof(t_coord));
		head->next->index = index;
		head->next->next = NULL;
		return (head->next);
	}
	head = (t_coord*)malloc(sizeof(t_coord));
	head->index = index;
	head->next = NULL;
	return (head);
}

t_coord		*ft_coords_help(int i, char *s, t_coord *list, t_coord *head)
{
	int j;
	int index;

	while (s[++i] != '\0')
	{
		j = -1;
		index = 0;
		if (!head)
		{
			head = ft_pushback(head);
			list = head;
		}
		else
			list = ft_pushback(head);
		while (++j < 20 && s[i] != '\0')
			if (s[i++] == '#')
			{
				list->arr_x[index] = j % 5;
				list->arr_y[index++] = j / 5;
			}
		if (s[i] == '\0')
			break ;
	}
	return (head);
}

void		ft_sdvig(t_coord *list)
{
	int	i;
	int min_x;
	int min_y;

	while (list)
	{
		i = 0;
		min_x = list->arr_x[0];
		min_y = list->arr_y[0];
		while (++i < 4)
		{
			if (list->arr_x[i] < min_x)
				min_x = list->arr_x[i];
			if (list->arr_y[i] < min_y)
				min_y = list->arr_y[i];
		}
		i = -1;
		while (++i < 4)
		{
			list->arr_x[i] -= min_x;
			list->arr_y[i] -= min_y;
		}
		list = list->next;
	}
}

t_coord		*ft_coords(char *s)
{
	int		i;
	t_coord	*list;
	t_coord *head;

	head = NULL;
	list = NULL;
	i = -1;
	head = ft_coords_help(i, s, list, head);
	ft_sdvig(head);
	return (head);
}
