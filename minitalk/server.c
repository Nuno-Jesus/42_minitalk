/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:27:45 by marvin            #+#    #+#             */
/*   Updated: 2022/11/29 22:27:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned char	*g_msg = NULL;

void	handler(int signal)
{
	static int				count = 0;
	static unsigned char	c = 0;
	unsigned char			bit;

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
			g_msg = NULL;
		}
		count = 0;
		c = 0;
	}
}

void	install_handlers(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	act1.sa_handler = &handler;
	act2.sa_handler = &handler;
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
