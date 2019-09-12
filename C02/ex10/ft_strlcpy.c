/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:20:21 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/11 15:20:25 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned	int dest_size;
	unsigned	int i;

	dest_size = 0;
	while (dest[dest_size] != '\0')
	{
		dest_size++;
	}
	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i + dest_size] = src[i];
		i++;
	}
	dest[i + dest_size] = '\0';
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}
