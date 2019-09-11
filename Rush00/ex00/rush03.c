/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:04:27 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/07 13:00:30 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_newrow(char intc, char extc1, char extc2, int x)
{
	int aux;

	aux = x;
	while (x >= 1)
	{
		if (x == aux)
		{
			ft_putchar(extc1);
		}
		else if (x == 1)
		{
			ft_putchar(extc2);
		}
		else
		{
			ft_putchar(intc);
		}
		x--;
	}
}

void	rush(int x, int y)
{
	int		fila;
	char	intc;
	char	extc1;
	char	extc2;

	fila = y;
	while (fila > 0)
	{
		if (fila == 1 || fila == y)
		{
			extc1 = 'A';
			extc2 = 'C';
			intc = 'B';
		}
		else
		{
			extc1 = 'B';
			extc2 = extc1;
			intc = ' ';
		}
		ft_newrow(intc, extc1, extc2, x);
		ft_putchar('\n');
		fila--;
	}
}
