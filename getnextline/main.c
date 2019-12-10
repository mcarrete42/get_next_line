/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:36:21 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/09 18:11:24 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 10

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}


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
	return (0);
}


/* OPEN & CLOSE MAIN
int     main ()
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open failed\n"); // check the fd for errors
		return(1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))  //while read != 0
	{
		buf[ret] = '\0';
		ft_putnbr(ret); //print the number of bytes that has been read
		ft_putstr(buf); //print what has been read
	}
	if (close(fd) == -1)
	{
		ft_putstr("Close failed\n"); // putstr to write in the fd
		return (1);
	}
	return(0);
}

*/


/*
int		main(void)
{
	int fd;
	char *line;
	fd = open("42", O_RDONLY);

	if (fd == -1)
	{
		ft_putstr("Open failed\n"); // check the fd for errors
		return(1);
	}
	printf("fd = %d\n", fd);
	while (get_next_line(fd, &line))
		printf("\nReturn= %d\n", get_next_line(fd, &line));
	if (close(fd) == -1)
	{
		ft_putstr("Close failed\n"); // putstr to write in the fd
		return (1);
	}
	return(0);
}
*/

