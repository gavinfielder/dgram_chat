/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:45:42 by gfielder          #+#    #+#             */
/*   Updated: 2019/02/22 01:47:33 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memdelr(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return (NULL);
	free(*ap);
	*ap = NULL;
	return (NULL);
}
