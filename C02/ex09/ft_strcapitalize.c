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

int		ft_c_is_numeric(char c)
{
	int		valid;

	valid = 1;
	if (c < '0' || c > '9')
	{
		valid = 0;
	}
	return (valid);
}

int		ft_c_is_alpha(char c)
{
	int		valid;

	valid = 1;
	if (c < 'A' || (c < 'a' && c > 'Z') || c > 'z')
	{
		valid = 0;
	}
	return (valid);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0 || !(ft_c_is_alpha(str[i - 1]) ||
			ft_c_is_numeric(str[i - 1])))
			{
				str[i] -= 32;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (i > 0 && (ft_c_is_alpha(str[i - 1]) ||
			ft_c_is_numeric(str[i - 1])))
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}
