/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:32:21 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/21 15:35:13 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"

typedef struct s_pipex{
	char	*cmd_path1;
	char	*cmd_path2;
	char	**cmd1;
	char	**cmd2;
	int		pipefd[2];
}t_pipex;

// finding path of commands
char	*find_cmd_path(char **envp, char **cmd);
char	*find_path(char **envp, char **cmd);
char	*exact_path(char *path, char **cmd);
void	free_array(char **diff);
void	free_str(char *str1, char *str2);
void	test_break(char **with_slash, char **path_final);

// forking
int		do_fork(t_pipex *p, char **envp, int file_1, int file_2);
void	child_process1(t_pipex *p, char **envp, int x);
void	child_process2(t_pipex *p, char **envp, int x);

// init
int		init(t_pipex *p, char **av, char **envp);
void	free_funk(t_pipex *p);
void	check_file_error(int file_1, int file_2, char **av);
void	check_conditions(t_pipex *p, char **av);

//withoutpipe
void	init_one(t_pipex *p, char **av, char **envp);
void	do_fork_sp(t_pipex *p, char **envp, int file_1, int file_2);
void	child_process_sp(t_pipex *p, char **envp, int x, int y);

#endif
