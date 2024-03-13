/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:59:32 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/21 13:57:22 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;
	int		file_1;
	int		file_2;

	if (ac != 5)
	{
		ft_printf("To run program, type: ");
		ft_printf("./pipex infile \"cmd\" \"cmd\" outfile \n");
		exit (3);
	}
	file_1 = open(av[1], O_RDONLY);
	file_2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_file_error(file_1, file_2, av);
	p = (t_pipex *)malloc (sizeof (t_pipex));
	if (!p)
		return (2);
	if (pipe(p->pipefd) == -1 || init(p, av, envp) != 0
		|| do_fork(p, envp, file_1, file_2) != 0)
	{
		free_funk(p);
		return (127);
	}
	free_funk(p);
	return (0);
}
