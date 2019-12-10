/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:49:22 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/09 21:13:36 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		get_line(char **stat, char **line)
{
	int len;
	char *temp_line;

	len = 0;
	while ((*stat)[len] != '\n' && (*stat)[len] != '\0')
		len++;
	if ((*stat)[len] == '\n')
	{
		*line = ft_substr(*stat, 0, len);
		temp_line = ft_strdup(&(*stat)[len + 1]);
		ft_free_if_alloc(stat);
		*stat = temp_line;
		if ((*stat)[0] == '\0')
			ft_free_if_alloc(stat);
	}
	else
	{
		*line = ft_strdup(*stat);
		ft_free_if_alloc(stat);
	}
	return (1);
}

static int		ft_returns(char **stat, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stat[fd] == NULL)
		return (0);
	return (get_line(&stat[fd], line));
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char *stat[1600];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (stat[fd] == NULL)
			stat[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(stat[fd], buf);
			ft_free_if_alloc(&stat[fd]);
			stat[fd] = temp;
		}
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	return (ft_returns(stat, line, fd, ret));
}

/*
//MULTIPLE FDS
int   main(void)
{
	char	*line;
	int		fd1;
	int		fd2;

	fd1 = open("42", O_RDONLY);
	fd2 = open("21", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	return (0);
}
*/

//ONE FDS
int   main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("42", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%d\n", get_next_line(fd1, &line));
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	return (0);
}
