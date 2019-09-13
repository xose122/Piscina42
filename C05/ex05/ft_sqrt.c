/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:14:24 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 13:14:25 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
	{
		return (1);
	}
	else if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	else
	{
		return (0);
	}
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < nb)
	{
		if (ft_recursive_power(i, 2) == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
