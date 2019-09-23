/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:35:15 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/23 14:35:16 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int		ft_strcmp(char *s1, char *s2)
{
	char	c1;
	char	c2;
	int		i;

	i = 0;
	c1 = s1[i];
	c2 = s2[i];
	while (c1 == c2 && c1 != '\0' && c2 != '\0')
	{
		i++;
		c1 = s1[i];
		c2 = s2[i];
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr_nl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_printn(int n)
{
	char *str;

	str = "0123456789";
	write(1, &str[n], 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(8);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb < 10)
	{
		ft_printn(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (ft_strcmp(par[i].str, "0") != 0)
	{
		ft_putstr_nl(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr_nl(par[i].copy);
		i++;
	}
}
