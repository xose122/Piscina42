/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:51:55 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 12:52:00 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int		len;
	char	c;

	len = 0;
	c = str[len];
	while (c != '\0')
	{
		len++;
		c = str[len];
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
