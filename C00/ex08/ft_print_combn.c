
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
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_pow(int b, int e)
{
	int n;

	if (e == 0)
	{
		return 1;
	}
	else if (e == 1)
	{
		return b;
	}
	else if (e%2)
	{
		n = ft_pow(b, e/2);
		return (n*n*b);
	}
	else
	{
		n = ft_pow(b, e/2);
		return (n*n);
	}
}

void	ft_write_arr(int ndigit, int nb[ndigit])
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (i < ndigit)
	{
		ft_putchar(nb[i]+48);
		i++;
	}
	if (nb[0] != 10-ndigit)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_arr_inic(int ndigit, int (*nb)[ndigit])
{
	int i;

	i = 0;
	while (i < ndigit)
	{
		(*nb)[i] = 0;
		i++;
	}
}

int		ft_is_valid(int ndigit, int nb[ndigit])
{
	int i;
	int aux[10];
	int valid;

	ft_arr_inic(10, &aux);
	valid = 1;
	i = ndigit - 1;
	while (i >= 0 && valid)
	{
		if(aux[nb[i]] == 0){
			aux[nb[i]] = 1;
		}
		else
		{
			valid = 0;
		}
		i--;
	}
	return (valid);
}

void	ft_rec_comb(int ndigit, int nb[ndigit], int digit)
{
	if (digit == -1)
	{
		return ;
	}
	else
	{
		while (nb[digit] < 9)
		{
			nb[digit]++;
			if (ft_is_valid(ndigit, nb))
			{
				ft_write_arr(ndigit, nb);
			}
			if (digit + 1 < ndigit)
			{
				nb[digit+1] = nb[digit];
				ft_rec_comb(ndigit, nb, digit + 1);
			}
		}
		nb[digit] = nb[digit-1] + 1;
		ft_rec_comb(ndigit, nb, digit - 1);
	}
}

void	ft_print_combn(int n)
{
	int nb[n];

	ft_arr_inic(n, &nb);
	ft_rec_comb(n, nb, n-1);
}

int		main(void)
{
	ft_print_combn(9);
}