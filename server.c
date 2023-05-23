/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:48:11 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/11 22:48:51 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*check_signals(int signal)
{
	char	*str;

	if (signal == SIGUSR1)
		str = ft_strjoin(str, "0");
	if (signal == SIGUSR2)
		str = ft_strjoin(str, "1");
	return (str);
}

void	handler(int signal, siginfo_t *info, void *s)
{
	static char	*bit;
	static int	pid;
	static int	i;

	(void)s;
	if (!bit)
		bit = ft_strdup("");
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		bit = 0;
	}
	if (signal == SIGUSR1 || signal == SIGUSR2)
		bit = check_signals(signal);
	if (++i == 8)
	{
		ft_putchar_fd(binary_to_decimal(ft_atoi(bit)));
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	write (1, "PID : ", 6);
	pid = getpid();
	ft_putnbr_fd(pid);
	ft_putchar_fd('\n');
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
