/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:06:32 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/11 22:43:19 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig)
{
	(void) sig;
	write(1, "message arrived", 15);
}

void	ft_send(int pid, char msg)
{
	static int	bit;
	int			n;

	while (bit < 8)
	{
		n = 128 >> bit;
		if ((n & msg) == 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(800);
		bit++;
	}
	if (bit == 8)
		bit = 0;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		exit (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit(1);
	signal (SIGUSR1, handler);
	ft_send(pid, 1);
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\0');
}
