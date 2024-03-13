/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:35:42 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/18 15:39:05 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	do_fork(t_pipex *p, char **envp, int file_1, int file_2)
{
	int		pid1;
	int		pid2;

	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
		child_process1(p, envp, file_1);
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
		child_process2(p, envp, file_2);
	close(p->pipefd[1]);
	close(p->pipefd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

void	child_process1(t_pipex *p, char **envp, int x)
{
	close(p->pipefd[0]);
	dup2(x, STDIN_FILENO);
	dup2(p->pipefd[1], STDOUT_FILENO);
	close(x);
	close(p->pipefd[1]);
	execve(p->cmd_path1, p->cmd1, envp);
}

void	child_process2(t_pipex *p, char **envp, int x)
{
	close(p->pipefd[1]);
	dup2(p->pipefd[0], STDIN_FILENO);
	dup2(x, STDOUT_FILENO);
	close(x);
	close(p->pipefd[0]);
	execve(p->cmd_path2, p->cmd2, envp);
}
