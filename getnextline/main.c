/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:11:38 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/11 19:48:59 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;
	int 	i;

	line = 0;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			printf("%d- archivo: %s\n",i, argv[i]);
			while ((ret = get_next_line(fd, &buff)) > 0)
			{
				printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
				free(buff);
			}
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			if (ret == -1)
				printf("-----------\nError\n");
			else if (ret == 0)
				printf("-----------\nEnd of file\n");
			free(buff);
		}
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		free(buff);
		close(fd);
	}
	return (0);
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
/*
//ONE FDS
int   main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("42", O_RDONLY);
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
	get_next_line(fd1, &line);
	printf("%s\n", line);
	return (0);
}
*/
