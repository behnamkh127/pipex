/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:35:29 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/21 15:38:10 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init(t_pipex *p, char **av, char **envp)
{
	p->cmd1 = ft_split(av[2], ' ');
	p->cmd2 = ft_split(av[3], ' ');
	if (p->cmd1 == NULL || p->cmd2 == NULL)
		return (1);
	p->cmd_path1 = find_cmd_path(envp, p->cmd1);
	p->cmd_path2 = find_cmd_path(envp, p->cmd2);
	check_conditions(p, av);
	return (0);
}

void	check_conditions(t_pipex *p, char **av)
{
	if (!(p->cmd_path2) && !(p->cmd_path1))
	{
		ft_printf("pipex: %s : command not found\n", av[2]);
		ft_printf("pipex: %s : command not found\n", av[3]);
		free_funk(p);
		exit (127);
	}
	if (!(p->cmd_path1))
	{
		ft_printf("pipex: %s : command not found\n", av[2]);
		free_funk(p);
		exit (0);
	}
	if (!(p->cmd_path2))
	{
		ft_printf("pipex: %s : command not found\n", av[3]);
		free_funk(p);
		exit (127);
	}
}

void	check_file_error(int file_1, int file_2, char **av)
{
	if (file_1 < 0)
	{
		if (access(av[1], F_OK) == 0)
		{
			ft_printf("pipex: %s: permission denied.\n", av[1]);
			if (file_2 < 0 && access(av[4], F_OK) == 0)
			{
				ft_printf("pipex: %s: permission denied.\n", av[4]);
				exit (1);
			}
			else
				exit (0);
		}
		else
			ft_printf("pipex: %s: no such file or directory\n", av[1]);
		exit (0);
	}
	if (file_2 < 0)
	{
		if (access(av[4], F_OK) == 0)
			ft_printf("pipex: %s: permission denied.\n", av[4]);
		exit (1);
	}
}
