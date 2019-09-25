/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:54:18 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/13 10:54:20 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int		len;
	char	c;

	len = 0;
	c = str[len];
	while (c != '\0')
	{
		len++;
		c = str[len];
	}
	return (len);
}

int		ft_contains(char *str, char coincidence, int n)
{
	int found;
	int i;

	i = n;
	found = -1;
	while (str[i] != '\0' && found == -1)
	{
		if (str[i] == coincidence)
		{
			found = i;
		}
		i++;
	}
	return (found);
}

int		ft_valid_base(char *base)
{
	int i;
	int valid;

	valid = 1;
	i = 0;
	if (ft_contains(base, '+', 0) != -1 || ft_contains(base, '-', 0) != -1 ||
	ft_strlen(base) < 2)
	{
		valid = 0;
	}
	while (valid && base[i] != '\0')
	{
		if (ft_contains(base, base[i], i + 1) != -1)
		{
			valid = 0;
		}
		i++;
	}
	return (valid);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int mult;
	int result;
	int pos;

	if (!ft_valid_base(base))
		return (0);
	result = 0;
	mult = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while ((pos = ft_contains(base, str[i], 0)) != -1)
	{
		result = result * ft_strlen(base) + pos;
		i++;
	}
	return (result * mult);
}
