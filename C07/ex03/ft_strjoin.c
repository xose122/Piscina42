/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:11:42 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/20 11:11:43 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str_ret;

	if (size < 0)
		return ((char*)malloc(0));
	if (!(str_ret = (char*)malloc(size * sizeof(char))))
		return ((char*)malloc(0));
	i = 0;
	while (i < size)
	{
		ft_strcat(str_ret, strs[i]);
		if (i < size - 1)
		{
			ft_strcat(str_ret, sep);
		}
		i++;
	}
	return (str_ret);
}
