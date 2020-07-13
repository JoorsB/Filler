/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 16:25:16 by jboer          #+#    #+#                */
/*   Updated: 2019/02/05 23:13:07 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*newlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = f(lst);
	newlst = ret;
	if (newlst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
		ret->next = tmp;
		ret = ret->next;
	}
	return (newlst);
}
