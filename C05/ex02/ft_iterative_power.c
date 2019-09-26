/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:48:24 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 12:48:26 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_power(int nb, int power)
{
	int result;

	if (power < 0)
	{
		return (0);
	}
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
