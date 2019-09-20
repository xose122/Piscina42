/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:27:33 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 13:32:05 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int prime;

	prime = 1;
	i = 2;
	while (prime && i <= nb / i)
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
