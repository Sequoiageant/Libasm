/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:41:48 by julnolle          #+#    #+#             */
/*   Updated: 2020/04/20 17:33:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(int ac, char const **av)
{
	int ret;

	if (ac == 2)
	{
		printf("%zu\n", ft_strlen(av[1]));
		ret = ft_write(1, av[1], ft_strlen(av[1]));
		if (ret < 0)
			perror("error");
	}
	return (0);
}