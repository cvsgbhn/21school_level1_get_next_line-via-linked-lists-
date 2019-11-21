/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:35 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		w_a;
	int		chars_in_word;
	int		index;
	char	**main_array;

	index = -1;
	w_a = ft_count_words(s, c);
	if (!s || !(main_array = (char **)malloc(sizeof(char *) * (w_a + 1))))
		return (0);
	while (index++ < w_a && *s)
	{
		while (*s == c)
			s++;
		chars_in_word = ft_count_chars(s, c);
		if (!(main_array[index] = (char *)malloc(sizeof(char) * chars_in_word)))
		{
			ft_freearr(main_array);
			return (0);
		}
		ft_strncpy(main_array[index], s, chars_in_word);
		s += chars_in_word;
	}
	main_array[index] = NULL;
	return (main_array);
}
