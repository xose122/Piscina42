/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:04:27 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/07 12:55:17 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_newrow(char intc, char extc1, int x)
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
			ft_putchar(extc1);
		}
		else
		{
			ft_putchar(intc);
		}
		x--;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		fila;
	char	intc;
	char	extc1;

	fila = y;
	while (fila > 0)
	{
		if (fila == 1)
		{
			extc1 = 'C';
			intc = 'B';
		}
		else if (y == fila)
		{
			intc = 'B';
			extc1 = 'A';
		}
		else
		{
			extc1 = 'B';
			intc = ' ';
		}
		ft_newrow(intc, extc1, x);
		fila--;
	}
}
