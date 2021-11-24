/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:24 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 12:00:34 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		return_error(t_main **main, char **tab)
{
	if (tab[0] && tab[1] && tab[2])
		free_everything(&(*main), tab);
	if (errno == EACCES)
		ft_putstr("Permission denied\n");
	else if (errno == EBADF)
		ft_putstr("Bad file descriptor\n");
	else if (errno == EISDIR)
		ft_putstr("Is a directory\n");
	else if (errno == ENOENT)
		ft_putstr("No such file or directory\n");
	else
		ft_putstr("ASM couldn't compile.\n");
	return (0);
}

int		check_argv(char **argv)
{
	int		i;

	i = 1;
	if (argv == NULL)
		return (0);
	while (argv[i])
	{
		if (check_name(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*create_name(char *argv)
{
	char	*name;
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(argv);
	if ((name = malloc(sizeof(char) * (len + 2))) == NULL)
		return (NULL);
	while (i < len - 1)
	{
		name[i] = argv[i];
		i++;
	}
	name[i] = 'c';
	name[i + 1] = 'o';
	name[i + 2] = 'r';
	name[i + 3] = '\0';
	return (name);
}

int		main_bis(t_main **main, char *argv)
{
	char	*str;
	char	*name;
	char	**tab;
	int		fd;

	if ((str = get_lines(argv)) == NULL)
		return (return_main(&(*main)));
	if (!(tab = ft_strsplit(str, '\n')))
		return (empty_file(&(*main), tab));
	ft_strdel(&str);
	if (check_s(tab, &ME) == 0)
		return (return_error(&(*main), tab));
	if ((name = create_name(argv)) == NULL)
		return (return_error(&(*main), tab));
	if ((fd = open(name, O_CREAT | O_WRONLY, S_IRWXU)) == -1)
		return (return_error(&(*main), tab));
	if (!compile(main, fd, name))
		return (return_error(&(*main), tab));
	if (close(fd) == -1)
		return (return_error(&(*main), tab));
	free_everything(&(*main), tab);
	free(name);
	return (1);
}

int		main(int argc, char **argv)
{
	t_main		*main;
	int			i;

	i = 1;
	errno = 0;
	if ((main = malloc(sizeof(t_main))) == NULL)
	{
		ft_putstr("\x1b[31mmalloc not possible.\x1b[0m\n");
		return (0);
	}
	if (argc < 2)
	{
		ft_putstr("\x1b[31mError: not enough arguments.\x1b[0m\n");
		return (0);
	}
	if (check_argv(argv) == 0)
		return (0);
	while (argv[i])
	{
		if (main_bis(&main, argv[i]) == 0)
			return (0);
		i++;
	}
}
