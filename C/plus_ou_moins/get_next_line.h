/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:30:44 by cdapurif          #+#    #+#             */
/*   Updated: 2020/03/02 10:37:13 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len, int set);
char	*ft_strjoin(char *s1, char *s2, int free);

#endif
