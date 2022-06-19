/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_pipe_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:58 by Loui :)           #+#    #+#             */
/*   Updated: 2022/04/03 17:05:20 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_fds(t_pipex *ptr, char **argv)
{
	ptr->infile = open(argv[1], O_RDONLY);//input only
	ptr->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ptr->infile < 0 || ptr->outfile < 0)
	{
		if (ptr->infile < 0)
		{
			ft_putstr_fd("Error: no infile\n", 2);
			free_everything(ptr);
			exit(EXIT_FAILURE);
		}
		else if (ptr->outfile < 0)
		{
			ft_putstr_fd("Error occurred while writing to the file\n", 2);
			free_everything(ptr);
			exit(EXIT_FAILURE);
		}
	}
}

void	pipex2(t_pipex *ptr, int rd_pipe, int ofd)
{
	int		p2[2];
	pid_t	child;

	if (pipe(p2) < 0)
	{
		perror("Pipe error\n");
		exit(EXIT_FAILURE);
	}
	dup2(rd_pipe, STDIN);
	close(rd_pipe);
	dup2(ofd, STDOUT);
	child = fork();
	if (child == 0)
	{
		execve(ptr->cmd_p[1], ptr->cmds[1], ptr->envp);
		perror("execve2 didn't work");
	}
	else
	{
		close(p2[WRITE]);
		waitpid(child, NULL, 0);
	}
}

void	pipex(t_pipex *ptr, int ifd, int ofd)
{
	int		p1[2];
	pid_t	child;

	if (pipe(p1) < 0)
	{
		perror("Pipe error\n");
		exit(EXIT_FAILURE);
	}
	dup2(ifd, STDIN);
	close(ifd);
	dup2(p1[WRITE], STDOUT);
	child = fork();
	if (child == -1)
	{
		perror("Fork error\n");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
		execve(ptr->cmd_p[0], ptr->cmds[0], ptr->envp);
	else
	{
		close(p1[WRITE]);
		waitpid(child, NULL, 0);
		pipex2(ptr, p1[READ], ofd);
	}
}
