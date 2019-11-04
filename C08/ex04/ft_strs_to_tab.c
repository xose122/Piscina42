/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:00:32 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/23 14:00:33 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int					ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret_struct;

	ret_struct = (t_stock_str*)malloc(sizeof(t_stock_str) * ac);
	i = 0;
	while (i < ac)
	{
		ret_struct[i].str = ft_strdup(av[i]);
		ret_struct[i].copy = ft_strdup(av[i]);
		ret_struct[i].size = ft_strlen(av[i]);
		i++;
	}
	ret_struct[i].str = "0";
	ret_struct[i].copy = "0";
	ret_struct[i].size = 1;
	return (ret_struct);
}
