/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:22:40 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/06 14:22:48 by jgomez-b         ###   ########.fr       */
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

void	ft_print_number(int n)
{
	char *str;

	str = "0123456789";
	write(1, &str[n], 1);
}

void	ft_print_neg(void)
{
	write(1, "-", 1);
}

int		ft_get_n_digits(int n)
{
	int cont;

	cont = 1;
	while (n > 9)
	{
		n /= 10;
		cont++;
	}
	return (cont);
}

void	ft_putnbr(int nb)
{
	int		cont;
	int		n[ft_get_n_digits(nb)];
	char	c;

	cont = 0;
	while (nb > 9 || nb < -9)
	{
		n[cont] = ft_abs(nb % 10);
		nb /= 10;
		cont++;
	}
	n[cont] = ft_abs(nb);
	if (nb < 0)
	{
		ft_print_neg();
	}
	while (cont >= 0)
	{
		ft_print_number(n[cont]);
		cont--;
	}
}
