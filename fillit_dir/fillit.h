/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:58:41 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/05 13:10:45 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct		s_coord
{
	int				arr_x[4];
	int				arr_y[4];
	struct s_coord	*next;
	char			index;
}					t_coord;

t_coord				*ft_pushback(t_coord *head);
t_coord				*ft_coords(char *s);
t_coord				*ft_coords_help(int i, char *s,
					t_coord *list, t_coord *head);
void				ft_sdvig(t_coord *list);
int					ft_initsizemap(t_coord *list);
void				ft_solver(t_coord *list);
char				**ft_createmap(char **map, int size);
int					ft_check(char **map, t_coord *list, int x, int y);
int					ft_genmap(char **map, t_coord *list, int size_map);
char				**ft_fill(char **map, t_coord *list, int x, int y);
#endif
