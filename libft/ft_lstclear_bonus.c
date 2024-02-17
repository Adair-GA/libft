/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:47:19 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/11 14:40:49 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*act;

	if (!lst || !(*lst))
		return ;
	act = *lst;
	next = (*lst)->next;
	while (act)
	{
		del(act->content);
		free(act);
		act = next;
		if (!next)
			break ;
		next = next->next;
	}
	*lst = NULL;
}

// void del(void *p)
// {

// }

// int main()
// {
// 	t_list	*lst;
// 	int		n;

// 	n = 0;
// 	lst = ft_lstnew(&n);
// 	n++;
// 	while (n < 5)
// 	{
// 		ft_lstadd_back(&lst, ft_lstnew(&n));
// 		n++;
// 	}
// 	ft_lstclear(&lst, del);
// }
