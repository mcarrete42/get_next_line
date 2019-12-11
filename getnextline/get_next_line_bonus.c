/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:49:22 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/11 21:20:21 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (j < ft_strlen(s1))
	{
		str[j] = s1[j];
		j++;
	}
	i = j;
	j = 0;
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

int			get_line(char **stat, char **line, int fd)
{
	int		len;
	char	*temp_line;

	len = 0;
	while (stat[fd][len] != '\n' && stat[fd][len] != '\0')
		len++;
	if (stat[fd][len] == '\n')
	{
		*line = ft_substr(stat[fd], 0, len);
		temp_line = ft_strdup(stat[fd] + len + 1);
		free(stat[fd]);
		stat[fd] = temp_line;
		return (1);
	}
	else
	{
		*line = ft_strdup(stat[fd]);
		free(stat[fd]);
		stat[fd] = NULL;
		return (0);
	}
}

int			ft_returns(char **stat, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stat[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (get_line(stat, line, fd));
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char *stat[1600];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (stat[fd] == NULL)
			stat[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(stat[fd], buf);
			free(stat[fd]);
			stat[fd] = temp;
		}
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	return (ft_returns(stat, line, fd, ret));
}
