/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:00 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/21 11:20:31 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_cmd_path(char **envp, char **cmd)
{
	char	*path;

	path = find_path(envp, cmd);
	return (path);
}

char	*find_path(char **envp, char **cmd)
{
	char	*path;
	char	*temp;

	path = NULL;
	temp = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			temp = *envp;
			break ;
		}
		envp++;
	}
	temp = ft_substr(temp, 5, (ft_strlen(temp) - 5));
	path = exact_path(temp, cmd);
	free (temp);
	return (path);
}

void	test_break(char **with_slash, char **path_final)
{
	if (!*with_slash || !*path_final)
		return ;
	free_str(*with_slash, *path_final);
	*with_slash = NULL;
	*path_final = NULL;
}

char	*exact_path(char *path, char **cmd)
{
	char	**dif_dir;
	char	*with_slash;
	char	*path_final;
	int		i;
	char	*p;

	if (!cmd || !cmd[0])
		return (NULL);
	p = NULL;
	dif_dir = ft_split(path, ':');
	i = 0;
	while (dif_dir[i])
	{
		with_slash = ft_strjoin(dif_dir[i++], "/");
		path_final = ft_strjoin(with_slash, cmd[0]);
		if (access(path_final, F_OK) == 0)
		{
			p = ft_strdup(path_final);
			break ;
		}
		test_break(&with_slash, &path_final);
	}
	free_str(with_slash, path_final);
	free_array(dif_dir);
	return (p);
}
