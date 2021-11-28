/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:27:38 by Jraye             #+#    #+#             */
/*   Updated: 2020/11/11 21:10:52 by Jraye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;

	tmp1 = *lst;
	while (tmp1)
	{
		*lst = tmp1->next;
		ft_lstdelone(tmp1, del);
		tmp1 = *lst;
	}
	*lst = NULL;
}
