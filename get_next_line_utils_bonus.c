/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:12:16 by daykim            #+#    #+#             */
/*   Updated: 2022/06/04 17:12:16 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (*(str + index))
	{
		if (*(str + index) == (char)c)
		{
			return ((char *)str + index);
		}
		index++;
	}
	if ((char)c == '\0')
		return ((char *)str + index);
	return (0);
}

char	*ft_linecat(char *newstr, char *buf, size_t len)
{
	char	*catstr;

	if (len == 0)
		return (newstr);
	if (!newstr)
	{
		catstr = (char *)malloc(sizeof(char) * (len + 1));
		if (!catstr)
			return (0);
		ft_strlcpy(catstr, buf, len + 1);
		return (catstr);
	}
	catstr = (char *)malloc(sizeof(char) * (len + ft_strlen(newstr) + 1));
	if (!catstr)
		return (0);
	ft_strlcpy(catstr, newstr, ft_strlen(newstr) + 1);
	ft_strlcpy(catstr + ft_strlen(newstr), buf, len + 1);
	free(newstr);
	return (catstr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			len;
	size_t			index;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	index = 0;
	while ((index + 1 < size) && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (len);
}

t_list	*ft_setnode(t_list *head, int fd)
{
	t_list	*node;

	node = head -> next;
	while (node)
	{
		if (node -> fd == fd)
			return (node);
		else
			node = node -> next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node -> fd = fd;
	node -> data = 0;
	node -> pre = head;
	node -> next = head -> next;
	head -> next = node;
	if (head -> next)
		head -> next -> pre = node;
	return (node);
}

void	ft_delnode(t_list *node)
{
	free(node -> data);
	if (node -> next)
		node -> next -> pre = node -> pre;
	node -> pre -> next = node -> next;
	free(node);
	node = 0;
}
