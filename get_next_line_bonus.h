/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:10:45 by daykim            #+#    #+#             */
/*   Updated: 2022/06/04 17:10:45 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_linkedlist
{
	int					fd;
	char				*data;
	struct s_linkedlist	*pre;
	struct s_linkedlist	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_linecat(char *newline, char *buf, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
t_list	*ft_setnode(t_list *head, int fd);
char	*ft_delnode(t_list *node);

#endif