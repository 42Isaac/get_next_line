/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:02:21 by iperez            #+#    #+#             */
/*   Updated: 2019/01/29 14:24:36 by iperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);

#endif