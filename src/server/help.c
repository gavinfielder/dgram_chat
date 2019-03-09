/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 20:33:09 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/08 21:14:59 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dgram_chat_server.h"

char	*get_help(void)
{
	t_stringbuilder *sb;
	char			*ret;

	sb = ft_sbnew();
	ft_sbwrite(sb, "DGram Chat Server: Available Commands:\n");
	ft_sbwrite(sb, "   \\q                 leaves chat.\n");
	ft_sbwrite(sb, "   \\username  name    changes username.\n");
	ft_sbwrite(sb, "   \\style ...         changes text style.\n");
	ft_sbwrite(sb, "\n");
	ft_sbwrite(sb, "        see readme for style options.\n");
	ret = ft_sbtostr(sb);
	ft_sbdel(&sb);
	return (ret);
}
