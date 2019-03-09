/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:10:48 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/08 19:38:01 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dgram_chat_server.h"
#include <stdarg.h>

void	broadcast_message(t_server *server, const char *fmt, ...)
{
	va_list	args;
	int		success;
	int		sent_bytes;
	t_user	*user;

	va_start(args, fmt);
	success = ft_vsnprintf(server->send_buff, BUFF_SIZE, fmt, args);
	va_end(args);
	if (success < 0)
	{
		ft_printf("Error sending packet of bytes=%i\n", success);
		return ;
	}
	user = server->users;
	while (user)
	{
		sent_bytes = sendto(server->sock, server->send_buff, success, 0,
				((struct sockaddr *)(&(user->client_address))),
				user->client_address_len);
		if (sent_bytes < 0)
			ft_printf("Error sending packet.\n");
		user = user->next;
	}
}

void	send_message(t_server *server, t_user *user,
		const char *fmt, ...)
{
	va_list	args;
	int		success;
	int		sent_bytes;

	if (user == NULL)
	{
		ft_printf("Error sending packet: user is null\n");
		return ;
	}
	va_start(args, fmt);
	success = ft_vsnprintf(server->send_buff, BUFF_SIZE, fmt, args);
	va_end(args);
	if (success < 0)
	{
		ft_printf("Error sending packet of bytes=%i to user.\n", success);
		return ;
	}
	ft_printf("Sending message of %i bytes to %s. The message is \"%.30s\"\n",
			success, inet_ntoa(user->client_address.sin_addr), server->send_buff);
	sent_bytes = sendto(server->sock, server->send_buff, success, 0,
			((struct sockaddr *)(&(user->client_address))),
			user->client_address_len);
	if (sent_bytes < 0)
		ft_printf("Error sending packet to user.\n");
}
