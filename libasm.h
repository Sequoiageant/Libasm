/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:41:49 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/12 10:39:56 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <sys/syscall.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 32

# define PRINT_FT_STRLEN(x) printf("str: [%s] len: [%ld] --> ft_strlen = [%zu]\n", x, strlen(x), ft_strlen(x))
# define PRINT_FT_STRCMP(x, y) printf("s1: [%s] s2: [%s] strcmp: [%d]--> ft_strcmp = [%d]\n", x, y, strcmp(x, y), ft_strcmp(x,y))
# define PRINT_FT_STRDUP(x) printf("str: [%s] ft_strdup = [%s]\n", x, ft_strdup(x))
# define PRINT_FT_STRCPY(x, y) printf("dest: [%s] src: [%s] strcpy =  [%s] --> ft_strcpy =  [%s]\n", x, y, strcpy(strdup(x), y), ft_strcpy(strdup(x), y))

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, const void *buf, size_t count);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

#endif
