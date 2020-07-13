/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 13:55:31 by jboer          #+#    #+#                */
/*   Updated: 2019/08/09 16:01:41 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getline(t_get *current, char **line)
{
	int			i;
	char		*temp;

	i = ft_charindex(current->content, '\n');
	if (i == -1)
		i = 0;
	temp = ft_strnew(0);
	if (!temp)
		return (NULL);
	*line = ft_strndup(current->content, i);
	if (!*line)
		return (NULL);
	if (current->content[i] != '\0')
	{
		ft_strdel(&temp);
		temp = ft_strdup(&current->content[i + 1]);
		if (!temp)
			return (NULL);
	}
	ft_strdel(&(current->content));
	return (temp);
}

static char		*ft_readandjoin(t_get *current, int fd)
{
	char		buf[BUFF_SIZE + 1];
	char		*temp;

	while (current->ret > 0 && ft_strchr(current->content, '\n') == NULL)
	{
		current->ret = (int)read(fd, buf, BUFF_SIZE);
		if (current->ret == -1)
		{
			ft_strdel(&(current->content));
			return (NULL);
		}
		buf[current->ret] = '\0';
		temp = ft_strjoin(current->content, buf);
		ft_strdel(&(current->content));
		current->content = ft_strdup(temp);
		ft_strdel(&temp);
	}
	return (current->content);
}

static t_get	*ft_getget(const int fd, t_get *head)
{
	while (head)
	{
		if (head->file == fd)
			return (head);
		if (!head->next)
			break ;
		head = head->next;
	}
	head->next = (t_get *)malloc(sizeof(t_get));
	if (head->next == NULL)
		return (NULL);
	head = head->next;
	head->next = NULL;
	head->file = fd;
	head->ret = 1;
	head->content = ft_strnew(0);
	if (!head->content)
		return (NULL);
	return (head);
}

static int		ft_getreturn(char **line, int ret)
{
	if (ft_strlen(*line) == 0 && ret == 0)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_get	*head;
	t_get			*current;

	if (fd < 0 || !line)
		return (-1);
	if (!head)
	{
		head = (t_get *)malloc(sizeof(t_get));
		if (!head)
			return (-1);
		head->next = NULL;
		head->file = -1;
	}
	current = ft_getget(fd, head);
	current->content = ft_readandjoin(current, fd);
	if (current->content == NULL)
		return (-1);
	current->content = ft_getline(current, line);
	if (!current->content)
		return (-1);
	return (ft_getreturn(line, current->ret));
}
