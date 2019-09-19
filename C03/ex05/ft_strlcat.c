/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:37:42 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 14:37:46 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dstlength;
	unsigned int	srclength;

	i = 0;
	dstlength = ft_strlen(dest);
	srclength = ft_strlen(src);
	if (size <= dstlength)
		return (srclength + size);
	while ((dest[i] != '\0') && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dstlength + srclength);
}
