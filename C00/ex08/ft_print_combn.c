/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:32:31 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/06 14:32:36 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_arr(int ndigit, int nb[ndigit])
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (i < ndigit)
	{
		ft_putchar(nb[i] + 48);
		i++;
	}
	if (nb[0] != 10 - ndigit)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int		ft_is_valid(int ndigit, int nb[ndigit])
{
	int i;
	int valid;
	int aux[10];

	i = 0;
	while (i < 10)
	{
		aux[i] = 0;
		i++;
	}
	valid = 1;
	i = 0;
	while (i < ndigit && valid)
	{
		if (aux[nb[i]] == 0)
		{
			aux[nb[i]] = 1;
		}
		else
		{
			valid = 0;
		}
		i++;
	}
	return (valid);
}

void	ft_rec_comb(int ndigit, int nb[ndigit], int digit)
{
	while (nb[digit] < 9)
	{
		if (digit + 1 < ndigit)
		{
			nb[digit + 1] = nb[digit];
			ft_rec_comb(ndigit, nb, digit + 1);
		}
		nb[digit]++;
		if (ft_is_valid(ndigit, nb))
		{
			ft_write_arr(ndigit, nb);
		}
	}
	nb[digit] = nb[digit - 1] + 1;
}

void	ft_print_combn(int n)
{
	int nb[n];
	int i;

	i = 0;
	while (i < n)
	{
		nb[i] = 0;
		i++;
	}
	ft_rec_comb(n, nb, 0);
}

int main(){
	ft_print_combn(9);
}