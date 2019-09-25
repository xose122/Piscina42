/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:00:05 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/25 18:00:06 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		word_size(char *str, int start, int *end, char sep)
{
	int i;

	i = start;
	while (str[i] != '\0' && str[i] != sep)
	{
		i++;
	}
	*end = i;
	return (i - start);
}

int		n_words(char *str, char sep)
{
	int cont;
	int i;

	i = 0;
	if (str[0] == '\0')
	{
		return (0);
	}
	cont = 1;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i - 1] != sep)
		{
			cont++;
		}
		i++;
	}
	return (cont);
}

char	*get_word(char *str, int start, int word_size)
{
	int		i;
	char	*ret;

	ret = (char*)malloc(word_size * sizeof(char));
	i = 0;
	while (i < word_size)
	{
		ret[i] = str[start + i];
		i++;
	}
	return (ret);
}

char	**ft_split(char *str, char sep)
{
	char	**splitret;
	int		i;
	int		n;
	int		end;
	int		start;

	*n_str = 0;
	end = 0;
	start = 0;
	n = n_words(str, sep);
	splitret = (char **)malloc(sizeof(char *) * n);
	i = 0;
	while (i < n)
	{
		splitret[i] = get_word(str, start, word_size(str, start, &end, sep));
		*n_str = *n_str + 1;
		start = end + 1;
		i++;
	}
	return (splitret);
}
