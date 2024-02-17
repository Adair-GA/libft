/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:23 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/12 17:22:17 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*act;
	t_list	*new;

	act = lst;
	if (!act)
		return (NULL);
	new = ft_lstnew(f(act->content));
	act = act->next;
	if (!act)
		return (new);
	while (act->next)
	{
		ft_lstadd_back(&new, ft_lstnew(f(act->content)));
		act = act->next;
		if (!new->next)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
	}
	ft_lstadd_back(&new, ft_lstnew(f(act->content)));
	return (new);
}
// void	*fun(void *v)
// {
// 	int	*n;

// 	n = v;
// 	*n = *n + 1;
// 	return (n);
// }

// void	*none(void *a)
// {
// }

// int	main(void)
// {
// 	int		n;
// 	t_list	*lst;

// 	n = 0;
// 	lst = ft_lstnew(&n);
// 	while (n++ < 5)
// 	{
// 		ft_lstadd_back(&lst, ft_lstnew(&n));
// 		n++;
// 	}
// 	ft_lstmap(lst, fun, none);
// }
