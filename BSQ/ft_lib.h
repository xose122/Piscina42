/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:59:54 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/24 13:59:56 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H

# define FT_LIB_H

typedef	struct	s_point
{
	int i;
	int j;
    int value;
}				t_point;
int		**parse_file(char *pathname, int *ncol, int *nrow, char **cset);
char	**ft_split(char *str, int *n_str, char sep);
#endif
