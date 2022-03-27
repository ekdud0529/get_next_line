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

static char	*get_remain(int index, char **backup)
{
	char	*remain;
	int		len;

	len = ft_strlen(*backup + index);
	remain = (char *)malloc(sizeof(char) + (len + 1));
	if (!remain)
		return (0);
	ft_strlcpy(remain, *backup + index, len + 1);
	free(*backup);
	return (remain);
}

static char	*get_line(int fd, char **newstr)
{
	char		*buf;
	int			read_check;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (!ft_strchr(*newstr, '\n'))
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check <= 0)
			break ;
		buf[read_check] = '\0';
		*newstr = ft_linecat(*newstr, buf, read_check);
	}
	free(buf);
	buf = 0;
	if ((read_check < 0) || (**newstr == '\0'))
		return (0);
	return (*newstr);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	int			str_len;
	
	backup = get_line(fd, &backup);
	if (!backup)
	{
		free(backup);
		return (0);
	}
	if (ft_strchr(backup, '\n'))
		str_len = ft_strchr(backup, '\n') - backup + 1;
	else
		str_len = ft_strchr(backup, '\0') - backup;
	line = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!line)
		return (0);
	ft_strlcpy(line, backup, str_len + 1);
	backup = get_remain(str_len, &backup);
	if (!backup)
		return (0);
	return (line);
}
