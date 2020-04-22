/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/04/22 16:39:00 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(int ac, char const **av)
{
	int ret;
	int fd;
	char buf[BUFFER_SIZE + 1];
	char *dest;
	char *src = "copy";

	if (ac == 1)
	{
		// dest = strdup("DESTINATION");
		// printf("dest avant cpy: %s\n", dest);
		// ft_strcpy(dest, src);
		// printf("dest apres cpy: %s\n", dest);

		ret = ft_strcmp(src, "copy");
		printf("%d\n", ret);
	}
	if (ac == 2)
	{
		printf("%zu\n", ft_strlen(av[1]));
		ret = ft_write(1, av[1], ft_strlen(av[1]));
		if (ret < 0)
			perror("error");
		fd = open("text.txt", O_RDONLY);
		if (fd != -1)
		{
			ret = ft_read(fd, buf, BUFFER_SIZE);
			if (ret < 0)
				perror("error");
			// ret = ft_write(1, buf, ft_strlen(buf));
		}
	}
	return (0);
}