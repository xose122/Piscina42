/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:29:42 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/14 11:29:44 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		word_size(char *str, int start, int *end)
{
	int i;

	i = start;
	while (str[i] != '\0' && str[i] != ' '){
		i++;
	}
	*end = i;
	return (i - start);
}

int		n_words(char *str)
{
	int cont;
	int i;

	i = 0;
	if (str[0] == '\0')
	{
		return (0);
	}
	cont = 1;
	while (str[i]!='\0')
	{
		if(str[i] == ' ' && str[i - 1] != ' ')
		{
			cont++;
		}
		i++;
	}
	return (cont);
}

char	*get_word(char *str, int start, int word_size){
	int 	i;
	char	*ret;

	ret = (char*)malloc(word_size*sizeof(char)); 
	i = 0;
	while (i < word_size)
	{
		ret[i] = str[start + i];
		i++;
	}
	return (ret);
}

char	**ft_split(char *str, int *n_str)
{
	char **splitret;
	int i;
	int n;
	int end;
	int start;

	end = 0;
	start = 0;
	n = n_words(str);
	splitret = (char **)malloc(sizeof(char *) * n);
	i = 0;
	while (i < n)
	{
		splitret[i] = get_word(str, start, word_size(str, start, &end));
		*n_str = *n_str + 1;
		start = end + 1;
		i++;
	}
	return (splitret);
}
