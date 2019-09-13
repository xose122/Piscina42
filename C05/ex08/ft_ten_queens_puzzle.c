/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:55:32 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 13:55:34 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_abs(int n)
{
	if (n < 0)
	{
		n *= -1;
	}
	return (n);
}

void	ft_pintar_arr(int *reinas, int n)
{
	int i;
	char c;

	i = 0;
	while (i < n)
	{
		c = reinas[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_is_valid(int *reinas, int fila)
{
	int valido;
	int i;

	valido = 1;
	i = 0;
	while (i < fila)
	{
		if (reinas[fila] == reinas[i] ||
		ft_abs(i - fila) == ft_abs(reinas[i] - reinas[fila]))
		{
			valido = 0;
		}
		i++;
	}
	return (valido);
}

void	ft_rec_nreinas(int reinas[], int fila, int n, int soluc)
{
	int i;

	if (fila < n)
	{
		i = 0;
		while (i < n)
		{
			reinas[fila] = i;
			if (ft_is_valid(reinas, fila))
			{
				ft_rec_nreinas(reinas, fila + 1, n, soluc);
			}
			i++;
		}
	}
	else
	{
		ft_pintar_arr(reinas, n);
	}
}

int		ft_ten_queens_puzzle(void)
{
	int reinas[10];
	int i;
	int n;

	i = 0;
	while (i < 10)
	{
		reinas[i] = -1;
		i++;
	}
	return (724);
}

int main(){
	printf("%d", ft_ten_queens_puzzle());
}
