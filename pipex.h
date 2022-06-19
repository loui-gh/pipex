/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:23:47 by Loui :)           #+#    #+#             */
/*   Updated: 2022/02/25 00:58:08 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# define READ 0
# define STDIN 0
# define WRITE 1
# define STDOUT 1

typedef struct s_pipex
{
	char	***cmds;
	char	**cmd_p;
	char	**envp;
	int		infile;
	int		outfile;
	size_t	lazy;
	char	**sh_p;
}	t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strjoin_mod(char const *s1, char const *s2, size_t lazy);
char	*check_path_exists(char **envp);
int		find_cmd_path(t_pipex *ptr, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	cmd_array(t_pipex *ptr, char **argv);
void	cmd_paths_valid(t_pipex *ptr, char **argv, char **envp);
void	create_fds(t_pipex *ptr, char **argv);
void	parent(t_pipex *ptr);
void	child(t_pipex *ptr);
void	pipex(t_pipex *ppx, int ifd, int ofd);
void	pipex2(t_pipex *ptr, int ifd, int ofd);
void	free_dbl_ptr(char	**array);
void	free_everything(t_pipex *ptr);

#endif