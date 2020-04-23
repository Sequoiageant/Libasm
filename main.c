/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/04/23 17:53:12 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
extern int ___error;

int main(int ac, char const **av)
{
	int ret;
	int fd;
	char buf[BUFFER_SIZE + 1];
	char *dest;
	char *src = "copy";

	if (ac == 1)
	{
		dest = ft_strdup("DESTINATION");
		printf("dest avant cpy: %s\n", dest);
		ft_strcpy(dest, src);
		printf("dest apres cpy: %s\n", dest);
		free(dest);
		ret = ft_strcmp(src, "copy");
		printf("strcmp dest with \"copy\": %d\n", ret);
	}
	if (ac == 2)
	{
		printf("%zu\n", ft_strlen(av[1]));
		ret = ft_write(1, av[1], ft_strlen(av[1]));
		printf("\n");
		if (ret < 0)
			perror("error");
		fd = open("text.txt", O_RDONLY);
		if (fd != -1)
		{
			ret = ft_read(-1, buf, BUFFER_SIZE);
			if (ret < 0)
			{
				printf("ret   = %d\n", ret);
				printf("errno = %d\n", errno);
				printf("%s\n", strerror(-ret));
			}
			ret = ft_write(1, buf, ft_strlen(buf));
		}
	}
	return (0);
}