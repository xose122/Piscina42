/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:27:20 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 13:27:22 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		compare(const char *str, const char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (*to_find == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str != '\0')
	{
		if (compare(str, to_find))
			return (str);
		str++;
	}
	return (NULL);
}

int main()
{
	char *X = "Hola que tal - 42 Madrid";
	char *Y = "Madrid";

	printf("%s\n", ft_strstr(X, Y));

	return 0;
}