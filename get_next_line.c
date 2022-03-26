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

static char	*get_remain(size_t index, char **str_save)
{
	size_t	len;
	char	*remain;

	len = ft_strlen(*str_save + index);
	remain = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(remain, *str_save + index, len + 1);
	return (remain);
}

static void	get_str(int fd, char **newstr)
{
	char	*buf;
	char	*tmp;
	size_t	read_check;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n'))
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check <= 0)
			break ;
		buf[read_check] = '\0';
		tmp = *newstr;
		*newstr = ft_strconcat(*newstr, buf, read_check);
		free(tmp);
	}
	free(buf);
	buf = 0;
	tmp = 0;
}

char	*get_next_line(int fd)
{
	static char	*str_save;
	char		*line;
	size_t		remain;

	get_str(fd, &str_save);
	if (ft_strchr(str_save, '\n'))
	{
		remain = ft_strchr(str_save, '\n') - str_save;
		line = (char *)malloc(sizeof(char) * (remain + 1));
		ft_strlcpy(line, str_save, remain + 1);
	}
	else
	{
		return (0);
	}
	str_save = get_remain(remain + 1, &str_save);
	return (line);
}
