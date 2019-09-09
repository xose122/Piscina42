/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:19:16 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/09 10:19:21 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	char c;
	int i;

	i = 0;
	c = str[i];
	while (c != '\0'){
		write(1, &c, 1);
		i++;
		c = str[i];
	}
}
