/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:47:45 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/11 22:43:03 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit (1);
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
}
