/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:20 by cdapurif          #+#    #+#             */
/*   Updated: 2019/11/08 14:33:02 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (i);
	}
	return (-1);
}

int		ft_get_rest(char *buff, char **line)
{
	int a;
	int i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			break ;
	buff[i] = '\0';
	if ((*line = malloc(i + 1)) == NULL)
		return (-1);
	a = -1;
	while (++a <= i)
		(*line)[a] = buff[a];
	a = 0;
	while (buff[++i])
	{
		buff[a] = buff[i];
		a++;
	}
	buff[a] = '\0';
	return (1);
}

int		ft_read_line(int fd, char *buff, char **line)
{
	char	*str;
	int		r;

	str = NULL;
	if (buff && buff[0] != '\0')
		if ((str = ft_substr(buff, 0, ft_strlen(buff), 1)) == NULL)
			return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if ((r = check_line(buff)) >= 0)
		{
			if ((r = ft_get_rest(buff, line)) == -1)
				return (-1);
			if (str)
				if ((*line = ft_strjoin(str, *line, 1)) == NULL)
					return (-1);
			return (1);
		}
		if ((str = ft_strjoin(str, buff, 0)) == NULL)
			return (-1);
	}
	*line = str;
	return (r);
}

int		get_next_line(int fd, char **line)
{
	static char buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (check_line(buff) >= 0)
		return (ft_get_rest(buff, line));
	if ((ret = ft_read_line(fd, buff, line)) == -1)
		return (-1);
	if (*line == NULL)
	{
		if ((*line = malloc(1)) == NULL)
			return (-1);
		*line[0] = '\0';
	}
	if (ret == 0)
		buff[0] = '\0';
	return (ret);
}
