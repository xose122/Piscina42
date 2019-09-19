/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:27:02 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 12:27:06 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char			c1;
	char			c2;
	unsigned int	i;

	i = 0;
	c1 = s1[i];
	c2 = s2[i];
	while (c1 == c2 && c1 != '\0' && c2 != '\0' && i < n - 1)
	{
		i++;
		c1 = s1[i];
		c2 = s2[i];
	}
	return (s1[i] - s2[i]);
}
