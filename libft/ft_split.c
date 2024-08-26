/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:00:52 by sanbaek           #+#    #+#             */
/*   Updated: 2024/04/09 13:08:50 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_info_length(char const *s, char c)
{
	size_t	i_i;
	size_t	s_i;

	s_i = 0;
	i_i = 1;
	while (s[s_i] != '\0')
	{
		while (s[s_i] == c)
			s_i++;
		if (s[s_i] != '\0')
		{
			i_i++;
			while (s[s_i] != c && s[s_i] != '\0')
				s_i++;
			if (s[s_i] != '\0')
				i_i++;
		}
	}
	return (i_i);
}

static size_t	*calloc_info(char const *s, char c)
{
	size_t	*info;
	size_t	i_i;

	i_i = get_info_length(s, c);
	info = (size_t *)ft_calloc(i_i + 1, sizeof(size_t));
	if (info == NULL)
		return (NULL);
	info[0] = 0;
	if (i_i > 1)
		info[0] = i_i;
	return (info);
}

static size_t	*set_info(size_t *info, char const *s, char c)
{
	size_t	i_i;
	size_t	s_i;

	if (info == NULL)
		return (NULL);
	s_i = 0;
	i_i = 1;
	while (s[s_i] != '\0')
	{
		while (s[s_i] == c)
			s_i++;
		if (s[s_i] != '\0')
		{
			info[i_i++] = s_i;
			while (s[s_i] != c && s[s_i] != '\0')
				s_i++;
			info[i_i++] = s_i - 1;
		}
	}
	return (info);
}

static char	**set_words(char const *s, char **words, size_t *info)
{
	size_t	i_i;
	size_t	w_i;

	i_i = 1;
	w_i = 0;
	while (i_i < info[0])
	{
		words[w_i] = (char *)ft_calloc((info[i_i + 1] - info[i_i] + 1) + 1, 1);
		if (words[w_i] == NULL)
		{
			free(info);
			while (w_i)
				free(words[w_i--]);
			free(words[0]);
			free(words);
			return (NULL);
		}
		ft_memmove(words[w_i++], s + info[i_i], info[i_i + 1] - info[i_i] + 1);
		i_i += 2;
	}
	free(info);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	*info;

	info = set_info(calloc_info(s, c), s, c);
	if (info == NULL)
		return (NULL);
	words = (char **)ft_calloc((info[0] / 2 + 1), sizeof(char *));
	if (words == NULL)
		return (NULL);
	return (set_words(s, words, info));
}
