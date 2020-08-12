/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/12 10:56:12 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


int main(int ac, char const **av)
{
	int ret;
	int fd;
	char buf[BUFFER_SIZE + 1];

	if (ac == 1)
	{
		printf("====== Test ft_strlen ======\n"); 
		PRINT_FT_STRLEN("Bonjour");
		PRINT_FT_STRLEN("");
		PRINT_FT_STRLEN("Ecole 42 Paris");
		printf("\n====== Test ft_strcmp ======\n");
		PRINT_FT_STRCMP("Bonjour", "Hey");
		PRINT_FT_STRCMP("Hey", "Bonjour");
		PRINT_FT_STRCMP("Bonjour", "Bonjour");
		PRINT_FT_STRCMP("Bonjour", "");
		printf("\n====== Test ft_strdup ======\n");
		PRINT_FT_STRDUP("Bonjour");
		PRINT_FT_STRDUP("");
		printf("\n====== Test ft_strcpy ======\n");
		PRINT_FT_STRCPY("Bonjour", "Hey");
		PRINT_FT_STRCPY("Hey", "Bonjour");
		PRINT_FT_STRCPY("Bonjour", "Bonjour");
		PRINT_FT_STRCPY("Bonjour", "");

		printf("\n====== Test ft_write with error ======\n");
		ret = 0;
		errno = 0;
		close(1);
		ret = write(1, "Bonjour", strlen("Bonjour"));
		if (ret == -1)
			perror("error write");
		ret = 0;
		errno = 0;
		ret = ft_write(1, "Bonjour", strlen("Bonjour"));
		if (ret == -1)
			perror("error ft_write");
	}
	if (ac == 2)
	{
		printf("\n====== Test ft_read & ft_write======\n\n");
		printf("------Output with READ an WRITE------\n");

		ret = 1;
		errno = 0;
		fd = open(av[1], O_RDONLY);

		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			ret = write(1, buf, ft_strlen(buf));
			printf("\nret: %d\n", ret);
		}
		if (ret == -1)
		{
			printf("ret   = %d\n", ret);
			printf("errno = %d\n", errno);
			perror("error");
		}
		ret = write(1, "", 0);
		if (ret == -1)
			perror("error write");
		close(fd);

		printf("------Output with FT_READ & FT_WRITE------\n");

		ret = 1;
		errno = 0;
		fd = open(av[1], O_RDONLY);

		while ((ret = ft_read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			ret = ft_write(1, buf, ft_strlen(buf));
			printf("\nret: %d\n", ret);
		}
		if (ret == -1)
		{
			printf("ret   = %d\n", ret);
			printf("errno = %d\n", errno);
			perror("error");
		}
		ret = ft_write(1, "", 0);
		if (ret == -1)
			perror("error ft_write");
		close(fd);

	}
	return (0);
}
