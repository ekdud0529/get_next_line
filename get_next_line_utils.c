/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:33 by daykim            #+#    #+#             */
/*   Updated: 2022/02/06 22:52:33 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
