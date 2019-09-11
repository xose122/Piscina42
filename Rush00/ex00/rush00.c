/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:04:27 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/07 12:03:19 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_newrow(char intc, char extc, int x)
{
	int aux;

	aux = x;
	while (x >= 1)
	{
		if (x == aux || x == 1)
		{
			ft_putchar(extc);
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
	char	extc;
	char	intc;

	fila = y;
	while (fila > 0)
	{
		if (y == fila || fila == 1)
		{
			intc = '-';
			extc = 'o';
		}
		else
		{
			intc = ' ';
			extc = '|';
		}
		ft_newrow(intc, extc, x);
		ft_putchar('\n');
		fila--;
	}
}
