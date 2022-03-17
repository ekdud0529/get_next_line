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

// 1. file open
// 2. buf size 만큼 읽고 저장
// -> size 보다 적게 남아서 에러 발생시? errno
// 3. buf에서 개행문자 찾기
// 4. 개행문자 있으면 거기까지 리턴 없으면 저장
// 5. file 다 읽을때까지  2 ~ 4 반복
// 6. 파일 다 읽었으면 3 ~ 4 반복

int	find_newline(char *buf)
{
	int	index;

	index = 0;
	while (*(buf + index))
	{
		if ((*buf == '\n') || (*buf == '\0'))
		{
			return (index);
		}
	}
	return (-1);
}

char	*get_str(int fd)
{
	char	*buf;
	int		find;

	find = -1;
	while (find < 0)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		buf = read(fd, *buf, BUFFER_SIZE);
		find = find_newline(buf);
		if(find >= 0)
		{
			
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*str_save;

	str_save = get_str(fd);
	return ;
}