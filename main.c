/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/04/25 14:06:25 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


// extern int *__errno_location(void);

int main(int ac, char const **av)
{
	int ret;
	int fd;
	char buf[BUFFER_SIZE + 1];
	char *dest;
	char *src = "copy";

	ret = 1;
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
		// printf("%zu\n", ft_strlen(av[1]));
		// ret = ft_write(1, av[1], ft_strlen(av[1]));
		// if (ret == -1)
		// 	perror("error write");
		// else
		// 	printf("\n");		

		fd = open(av[1], O_RDONLY);
		if (fd != -1)
		{
			while ((ret = ft_read(fd, buf, BUFFER_SIZE)) > 0)
			{
				printf("ret: %d\n", ret);
				buf[ret] = '\0';
				ret = ft_write(1, buf, ft_strlen(buf));
			}
			if (ret == -1)
			{
				printf("ret   = %d\n", ret);
				printf("errno = %d\n", errno);
				perror("error");
			}
			ret = ft_write(1, "", 0);
			if (ret == -1)
				perror("error open");
		}
		else
			perror("error open");
	}
	return (0);
}