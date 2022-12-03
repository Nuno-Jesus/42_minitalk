/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:26:58 by marvin            #+#    #+#             */
/*   Updated: 2022/11/29 22:26:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_letter(pid_t spid, unsigned char c)
{
	int	i;

	i = 0;
	ft_printf("Sending 0x%X (%c)\n", c, c);
	while (i++ < 8)
	{
		if (c & 0b00000001)
			kill(spid, SIGUSR1);
		else
			kill(spid, SIGUSR2);
		c >>= 1;
		usleep(100);
	}
}

void	send_message(pid_t spid, char *msg)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(msg);
	while (i <= len)
		send_letter(spid, msg[i++]);
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
		print_usage(argv[0]);
	spid = ft_atoi(argv[1]);
	send_message(spid, argv[2]);
	return (EXIT_SUCCESS);
}
