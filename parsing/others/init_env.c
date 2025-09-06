/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:33:34 by abdo              #+#    #+#             */
/*   Updated: 2025/09/06 14:27:31 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	add_shlvl_if_missing(t_env **head)
{
	t_env	*tmp;
	t_env	*new;

	tmp = *head;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "SHLVL") == 0)
			return ;
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup("SHLVL");
	new->value = ft_strdup("1");
	new->eg = true;
	new->next = *head;
	*head = new;
}

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*new;
	char	*entry;
	char	*equal;

	head = NULL;
	while (*envp)
	{
		entry = *envp;
		equal = ft_strchr(entry, '=');
		if (equal)
		{
			new = malloc(sizeof(t_env));
			if (!new)
				return (NULL);
			new->key = ft_substr(entry, 0, equal - entry);
			new->value = ft_strdup(equal + 1);
			new->next = head;
			new->eg = true;
			head = new;
		}
		envp++;
	}
	return (head);
}
