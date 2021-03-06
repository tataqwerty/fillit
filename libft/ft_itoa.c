/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:25:15 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/25 18:58:30 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*arr;
	int		i;
	int		nb;
	int		flag;

	flag = 0;
	nb = (n < 0) ? n * -1 : n;
	i = (n < 0) ? 2 : 1;
	while ((nb /= 10))
		i++;
	arr = ft_strnew(i);
	if (arr == NULL)
		return (0);
	if (n == 0)
		arr[0] = '0';
	if (n < 0)
		arr[0] = '-';
	while (n && --i >= 0)
	{
		arr[i] = (n < 0) ? n % 10 * -1 + 48 : (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}
