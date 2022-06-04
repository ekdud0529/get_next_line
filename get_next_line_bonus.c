/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:10:50 by daykim            #+#    #+#             */
/*   Updated: 2022/06/04 17:10:50 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

static char	*get_remain(int index, char *backup)
{
	char	*remain;
	int		len;

	len = ft_strlen(backup + index);
	remain = (char *)malloc(sizeof(char) * (len + 1));
	if (!remain)
		return (0);
	ft_strlcpy(remain, backup + index, len + 1);
	free(backup);
	return (remain);
}

static char	*get_str(int fd, char *newstr)
{
	char		*buf;
	int			read_check;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	read_check = 1;
	while (!ft_strchr(newstr, '\n') && (read_check > 0))
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check < 0)
		{
			free(buf);
			return (0);
		}
		buf[read_check] = '\0';
		newstr = ft_linecat(newstr, buf, read_check);
	}
	free(buf);
	buf = 0;
	return (newstr);
}

static char	*get_line(char *data)
{
	char	*line;
	size_t	len;

	len = 0;
	if (ft_strchr(data, '\n'))
		len = ft_strchr(data, '\n') - data + 1;
	else
		len = ft_strchr(data, '\0') - data;
	if (*data == '\0' || len == 0)
		return (0);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (0);
	ft_strlcpy(line, data, len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	if (fd < 0)
		return (0);
	node = ft_setNode(&head, fd);
	if (!node)
		return (0);
	node -> data = get_str(fd, node -> data);
	if (!(node -> data))
		return (0);
	line = get_line(node -> data);
	if (!line)
	{
		ft_delNode(node);
		return (0);
	}
	node -> data = get_remain(ft_strlen(line), node -> data);
	if (!backup)
	{
		ft_delNode(node);
		return (0);
	}
	return (line);
}