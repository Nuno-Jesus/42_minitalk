/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:48:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/06 17:47:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_letter(pid_t spid, unsigned char c)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if (c & 0b00000001)
		{
			if (kill(spid, SIGUSR1) == -1)
				print_error("kill(): couldn't transmit bit to server\n");
		}
		else
		{
			if (kill(spid, SIGUSR2) == -1)
				print_error("kill(): couldn't transmit bit to server\n");
		}
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

void	handler(int signal)
{
	(void)signal;
	ft_printf("\n\t======= ACK: end of transmission =======\n\n");
}

void	install_handlers(void)
{
	struct sigaction	act;

	act.sa_handler = &handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		print_error("sigaction(): failed handler installing\n");
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
		print_usage(argv[0]);
	install_handlers();
	spid = ft_atoi(argv[1]);
	send_message(spid, argv[2]);
	return (EXIT_SUCCESS);
}
