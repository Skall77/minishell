/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:30:04 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/03/22 12:12:43 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_refil_helper(char **env)
{
	char	**new_env;
	int		len;

	len = 0;
	while (env[len])
		len++;
	new_env = malloc(sizeof(char *) * (len + 1));
	if (!new_env)
		return (NULL);
	return (new_env);
}

char	**ft_refill_env(char **env, char *line)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_refil_helper(env);
	if (!new_env)
		return (NULL);
	while (env[i])
	{
		if (ft_strcmp(env[i], line) == 0)
			i++;
		if (env[i])
		{
			new_env[j++] = ft_strdup(env[i]);
			i++;
		}
	}
	new_env[j] = NULL;
	ft_freetab(env, 1);
	return (new_env);
}

char	**unset_remove(char **env, char *arg)
{
	char	*line;

	line = NULL;
	line = get_path(env, arg);
	if (line != NULL)
		env = ft_refill_env(env, line);
	return (env);
}

int	ft_unset(t_data *data, char **var)
{
	int		i;

	i = -1;
	while (var[++i])
		data->env = unset_remove(data->env, var[i]);
	return (0);
}
