/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:19 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/16 15:59:43 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_funk(t_pipex *p)
{
	free_array(p->cmd1);
	free_array(p->cmd2);
	if (p->cmd_path1)
		free (p->cmd_path1);
	if (p->cmd_path2)
		free (p->cmd_path2);
	if (p)
		free (p);
}

void	free_array(char **diff)
{
	char	**temp;

	temp = NULL;
	if (diff)
	{
		temp = diff;
		while (*diff)
		{
			free(*diff);
			*diff = NULL;
			diff++;
		}
		free(temp);
		temp = NULL;
	}
}

void	free_str(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
}
