/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:28:49 by abdo              #+#    #+#             */
/*   Updated: 2025/08/24 15:56:40 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	g_var = 0;

void	ft_change_global(int flag)
{
	g_var = flag;
}

t_data	*sig_data(t_data *new_dt)
{
	static t_data	*dt = NULL;

	if (new_dt)
		dt = new_dt;
	return (dt);
}

void	ctld_handler(void)
{
	t_data	*dt;

	dt = sig_data(NULL);
	printf("\033[1A");
	printf("\033[12C");
	printf("exit\n");
	if (dt)
		dt->exit_status = 0;
	if (dt)
		exit(dt->exit_status);
	else
		exit(0);
}

void	ctlc_handler(int sig)
{
	t_data	*dt;

	(void)sig;
	dt = sig_data(NULL);
	if (dt)
		dt->exit_status = 130;
	if (g_var == 0)
		write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_var == 0)
		rl_redisplay();
}

void	ft_signals(void)
{
	signal(SIGINT, ctlc_handler);
	signal(SIGQUIT, SIG_IGN);
}
