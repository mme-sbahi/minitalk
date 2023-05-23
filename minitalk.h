/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:48:21 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/10 16:16:24 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	ft_putstr_fd(char *s);
void	ft_putnbr_fd(int nb);
int		ft_atoi(const char *str);
void	ft_send(int signal, char msg);
void	ft_putchar_fd(int c);
int		ft_strlen(const char *s);
int		binary_to_decimal(int binary);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup( const char *source);

#endif
