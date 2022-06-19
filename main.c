/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:45:55 by Loui :)           #+#    #+#             */
/*   Updated: 2022/02/25 00:54:48 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_everything(t_pipex *ptr)
{
	int	i;

	i = 0;
	free_dbl_ptr(ptr->sh_p);
	while (i < 2)
		free(ptr->cmd_p[i++]);
	free(ptr->cmd_p);
	i = 0;
	while (ptr->cmds[i])
		free_dbl_ptr(ptr->cmds[i++]);
	free(ptr->cmds);
	free(ptr);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*ptr;

	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments entered", 2);
		exit(EXIT_FAILURE);
	}
	ptr = malloc(sizeof(t_pipex));
	ptr->cmds = malloc(sizeof(char **) * 3);
	ptr->cmd_p = malloc(sizeof(char *) * 3);
	ptr->envp = envp;
	cmd_paths_valid(ptr, argv, envp);
	create_fds(ptr, argv);
	pipex(ptr, ptr->infile, ptr->outfile);
	free_everything(ptr);
	return (0);
}
