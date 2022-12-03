/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:34:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/03 23:38:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_usage(char *command)
{
	ft_printf("Usage: %s [pid] [message]\n", command);
	exit(EXIT_FAILURE);
}

void	print_error(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

unsigned char	*ft_strjoin_mod(unsigned char *s1, unsigned char *s2)
{
	size_t			i;
	size_t			size;
	unsigned char	*res;

	i = 0;
	size = 0;
	if (s1)
		size = ft_strlen((char *)s1);
	size += ft_strlen((char *)s2) + 1;
	res = (unsigned char *)malloc(size);
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*(res++) = s1[i++];
		res -= ft_strlen((char *)s1);
	}
	while (*s2)
		res[i++] = *(s2++);
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}
