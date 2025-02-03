/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:23:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:46:57 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *s)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (s && *s)
	{
		if (*s == 32 || (*s >= 9 && *s <= 13))
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count);
}

static void	free_all(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		res[i] = NULL;
		i--;
	}
	free(res);
}

static char	**ft_fill(char **arr, char *s, char c)
{
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	while (s[end] && i < count_words(s))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		arr[i] = ft_substr(s, start, end - start);
		if (arr[i] == NULL)
		{
			free_all(arr, i - 1);
			arr = NULL;
			return (arr);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((count_words(s) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = ft_fill(arr, s, c);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
