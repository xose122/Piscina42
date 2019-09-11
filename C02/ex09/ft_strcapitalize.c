/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:58:38 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/11 14:58:41 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i > 0 &&
			(str[i - 1] < 'A' ||
			(str[i - 1] < 'a' && str[i - 1] > 'Z') ||
			str[i - 1] > 'z'))
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}

void main(){
	char aux[] = "hola, ¿cómo estás? 42palabras cuarenta-y-dos; cincuenta+y+uno";
	printf("%s", ft_strcapitalize(aux));
}