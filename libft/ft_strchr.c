/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:48:42 by kfum              #+#    #+#             */
/*   Updated: 2021/11/29 11:18:16 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int x)
{
	char	*p;

	p = (char *)str;
	while (*p != x)
	{
		if (*p == '\0')
		{
			return (0);
		}
		p++;
	}
	return (p);
}
