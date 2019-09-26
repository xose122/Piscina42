/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:10:19 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/19 12:10:21 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int size;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	if (!(arr = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = min;
	while (i < max)
	{
		arr[i - min] = i;
		i++;
	}
	return (arr);
}

int main()
{
	int i = 0;
	int *tab = ft_range(10, 20);

	while(i < 10)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
