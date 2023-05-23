/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:06:55 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/10 16:12:50 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	handler(int sig);
void	ft_send(int pid, char msg);
int		binary_to_decimal(int binary);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *source);
void	ft_putchar_fd(int c);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int nb);
void	ft_putstr_fd(char *s);
int		ft_strlen(const char *s);

#endif