/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:36:47 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 15:31:53 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	handle_signal(int signum)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;

	current_char <<= 1;
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_msg;

	ft_printf("This is Tudor's server.\n");
	ft_printf("PID: %d\n", getpid());
	sa_msg.sa_handler = handle_signal;
	sa_msg.sa_flags = 0;
	sigaction(SIGUSR1, &sa_msg, NULL);
	sigaction(SIGUSR2, &sa_msg, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
