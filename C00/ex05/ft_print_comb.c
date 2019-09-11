/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:20:46 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/06 12:20:49 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int i, int j, int k)
{
	char comma;
	char space;
	char *str;

	comma = ',';
	space = ' ';
	str = "0123456789";
	write(1, &str[i], 1);
	write(1, &str[j], 1);
	write(1, &str[k], 1);
	if (!(i == 7 && j == 8 && k == 9))
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		k = j + 1;
		while (j <= 9)
		{
			while (k <= 9)
			{
				ft_print_number(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
