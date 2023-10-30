/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:07:12 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 12:21:03 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_getenv(t_data *data, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	data->env = ft_calloc(sizeof(char *), i + 1);
	if (!data->env)
		ft_bad_malloc(data);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		if (!data->env[i])
			ft_bad_malloc(data);
		i++;
	}
	data->env[i] = NULL;
}

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	return (0);
}
