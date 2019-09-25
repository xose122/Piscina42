/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:20:54 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/25 11:20:55 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <unistd.h>

int		same_length(char **map, int *borders)
{
	int i;
	int ret;
	int len;

	i = 1;
	ret = 1;
	len = ft_strlen(map[0]);
	while (ret && i < borders[0])
	{
		if (ft_strlen(map[i]) == len)
			len = ft_strlen(map[i]);
		else
			ret = 0;
		i++;
	}
	return (ret);
}

int		valid_map(char **map, int *borders)
{

	if (same_length(map, borders))
		write(1, "Y", 1);
	else
		write(1, "N", 1);

	return (0);
}
