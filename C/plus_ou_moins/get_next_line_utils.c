/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:05:28 by cdapurif          #+#    #+#             */
/*   Updated: 2019/11/08 12:03:53 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char *s1, char *s2, int lib)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	if ((ret = malloc(i + ft_strlen(s2) + 1)) == 0)
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
	}
	a = -1;
	while (s2[++a])
		ret[i + a] = s2[a];
	ret[i + a] = '\0';
	if (s1)
		free(s1);
	if (lib)
		free(s2);
	return (ret);
}

char		*ft_substr(char *s, int start, int len, int set)
{
	int		i;
	int		size;
	char	*ret;

	if (!s[0] || start > ft_strlen(s) - 1)
	{
		if ((ret = malloc(1)) == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	i = start;
	while (i - start < len && s[i])
		i++;
	size = i - start;
	if ((ret = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ret[size] = '\0';
	i = -1;
	while (++i < size)
		ret[i] = s[start + i];
	if (set)
		s = NULL;
	return (ret);
}
