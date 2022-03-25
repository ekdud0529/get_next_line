/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:30 by daykim            #+#    #+#             */
/*   Updated: 2022/02/06 22:52:30 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_str(int fd, char *newline)
{
	char	*buf;
	char	*tmp;
	int		read_check;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!ft_strchr(buf, '\n'))
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check <= 0)
			break ;
		buf[read_check] = '\0';
		tmp = newline;
		newline = ft_strjoin(newline, buf);
		free(tmp);
	}
	free(buf);
	buf = 0;
	tmp = 0;
}

static int	get_line(char *str_save, char *line)
{
	int	index;

	index = 0;
	while (*(str_save + index) != '\n')
	{
		*line = *str_save;
		index++;
	}
	return (index);
}

static char	*get_remain(int index, char *save)
{
	int		len;
	int		ind;
	char	*remain;

	len = ft_strlen(save + index);
	remain = malloc(len + 1);
	ind = 0;
	while (*(save + index))
	{
		*(remain + ind) = *(save + index);
		index++;
		ind++;
	}
	*(remain + ind) = '\0';
	free(save);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*str_save;
	char		*line;
	int			remain;

	get_str(fd, str_save);
	if (ft_strchar(str_save, '\n'))
		remain = get_line(str_save, line);
	else
		return (0);
	str_save = get_remain(remain, str_save);
	return (line);
}
