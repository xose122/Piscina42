/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:17:15 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/23 13:17:16 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ptint_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_swap(char **a, char **b)
{
	char *aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	bubble_sort(char **arr, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				ft_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		ft_swap(&argv[i + 1], &argv[i]);
		i++;
	}
	argc--;
	bubble_sort(argv, argc);
	i = 0;
	while (i < argc)
	{
		ft_ptint_str(argv[i]);
		i++;
	}
}
