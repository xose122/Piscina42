/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:39:00 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 12:39:02 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int fact;

	fact = 1;
	if (nb >= 0)
	{
		while (nb > 1)
		{
			fact *= nb;
			nb--;
		}
		return (fact);
	}
	else
	{
		return (0);
	}
}
