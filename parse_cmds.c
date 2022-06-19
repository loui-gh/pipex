/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:46:00 by Loui :)           #+#    #+#             */
/*   Updated: 2022/02/25 22:42:07 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path_exists(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][6]);
		i++;
	}
	if (envp[i] == NULL)
	{
		perror("PATH not found\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	cmd_array(t_pipex *ptr, char **argv)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		ptr->cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	ptr->cmds[i] = NULL;
}

int	find_cmd_path(t_pipex *p, char **envp)
{
	int			i;
	int			j;
	int			cmd;

	i = 0;
	p->lazy = 0;
	p->sh_p = ft_split(check_path_exists(envp), ':');
	cmd = 0;
	while (cmd < 2)
	{
		j = 0;
		while (p->sh_p[j] != NULL)
		{
			p->cmd_p[i] = ft_strjoin_mod(p->sh_p[j], p->cmds[cmd][0], p->lazy);// /home/loui/.cargo.../ls
			if (access(p->cmd_p[i], X_OK) == 0)
			{
				i++;
				break ;
			}
			free(p->cmd_p[i]);
			j++;
		}
		cmd++;
	}
	return (i);
}

void	cmd_paths_valid(t_pipex *ptr, char **argv, char **envp)
{
	int	i;

	cmd_array(ptr, argv);
	i = find_cmd_path(ptr, envp);
	if (i != 2)
	{
		ft_putstr_fd("One or more cmds doesn't exist!\n", 1);
		exit(EXIT_FAILURE);
	}
}
