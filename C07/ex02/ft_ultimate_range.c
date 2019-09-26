/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:36:58 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/19 12:37:00 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int	i;
	int	*arr;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = max - min;
	if (!(arr = (int*)malloc(sizeof(int) * size)))
		return (-1);
	i = min;
	while (i < max)
	{
		arr[i - min] = i;
		i++;
	}
	*range = arr;
	return (size);
}

int main()
{
	int i = 0;
	int *tab;
	ft_ultimate_range(&tab, -10, 2147483647);

	while(i < 2147483647)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}