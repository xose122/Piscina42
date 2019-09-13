/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:44:05 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 13:44:06 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_prime(int nb)
{
	int i;
	int prime;

	prime = 1;
	i = 2;
	while (prime && i < nb / 2)
	{
		if (nb % i == 0)
		{
			prime = 0;
		}
		i++;
	}
	if (nb < 2)
	{
		prime = 0;
	}
	return (prime);
}

int		ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}
