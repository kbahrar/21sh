/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:12:18 by oboualla          #+#    #+#             */
/*   Updated: 2019/12/09 16:06:52 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

size_t	get_next_index(const char *cmd, size_t index)
{
	char	c;

	c = cmd[index++];
	while (cmd[index])
	{
		if (cmd[index] == c && cmd[index - 1] != '\\')
			break ;
		index++;
	}
	return (index);
}

char	**save_prompt(char *prompt)
{
	static char *sprom;

	if (!sprom && prompt)
		sprom = prompt;
	return (&sprom);
}

char	*prompt(void)
{
	char *prompt;
	char *tmp;
	char *cwd;

	prompt = ft_strjoin(BGREEN, "user@");
	tmp = prompt;
	prompt = ft_strjoin(tmp, getenv("USER"));
	ft_strdel(&tmp);
	tmp = ft_strjoin(prompt, ":\033[0m<");
	ft_strdel(&prompt);
	prompt = tmp;
	tmp = ft_strjoin(prompt, BBLUE);
	ft_strdel(&prompt);
	prompt = tmp;
	cwd = getcwd(NULL, 0);
	tmp = ft_strjoin(prompt, ft_strrchr(cwd, '/'));
	ft_strdel(&prompt);
	ft_strdel(&cwd);
	prompt = ft_strjoin(tmp, "\033[0m>");
	ft_strdel(&tmp);
	save_prompt(prompt);
	return (prompt);
}
