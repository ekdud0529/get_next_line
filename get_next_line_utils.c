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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	index;
	char	*newstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (0);
	index = 0;
	while (*s1)
	{
		newstr[index] = *s1;
		s1++;
		index++;
	}
	while (*s2)
	{
		newstr[index] = *s2;
		s2++;
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
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