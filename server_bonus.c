/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:48:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/04 00:27:01 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned char	*g_msg = NULL;

void	handler(int signal, siginfo_t *info, void *ucontent)
{
	static int				count = 0;
	static unsigned char	c = 0;
	unsigned char			bit;

	(void) ucontent;
	bit = (signal == SIGUSR1);
	c |= (bit << count++);
	if (count == 8)
	{
		g_msg = ft_strjoin_mod(g_msg, &c);
		if (!g_msg)
			exit(EXIT_FAILURE);
		if (c == '\0')
		{
			ft_printf("%s\n", g_msg);
			free(g_msg);
			if (kill(info->si_pid, SIGUSR1) == -1)
				print_error("kill(): could't send ACK back to client\n");
			exit(EXIT_SUCCESS);
		}
		count = 0;
		c = 0;
	}
}

void	install_handlers(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	ft_memset(&act1.sa_flags, 0, sizeof(int));
	ft_memset(&act2.sa_flags, 0, sizeof(int));
	act1.sa_flags |= SA_SIGINFO;
	act2.sa_flags |= SA_SIGINFO;
	act1.sa_sigaction = &handler;
	act2.sa_sigaction = &handler;
	sigemptyset(&act1.sa_mask);
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigemptyset(&act2.sa_mask);
	sigaddset(&act2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &act1, NULL) == -1)
		print_error("sigaction(): failed handler installing\n");
	if (sigaction(SIGUSR2, &act2, NULL) == -1)
		print_error("sigaction(): failed handler installing\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("PID: %d\n", getpid());
	install_handlers();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
