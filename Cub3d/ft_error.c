/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:05:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/14 14:43:47 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		write(2, &src[i], 1);
}

int	print_error_message2(int error_code)
{
	if (error_code == ERRCODE_PLAYEUR_MAP)
		ft_print_error(ERRMSG_PLAYEUR_MAP);
	else if (error_code == ERRCODE_INVALID_MAP)
		ft_print_error(ERRMSG_INVALID_MAP);
	else if (error_code == ERRCODE_SAME_LINE)
		ft_print_error(ERRMSG_SAME_LINE);
	else if (error_code == ERRCODE_SIZE_IMG)
		ft_print_error(ERRMSG_SIZE_IMG);
	return (1);
}

int	print_error_message(int error_code)
{
	if (error_code == ERRCODE_MALLOC)
		ft_print_error(ERRMSG_MALLOC);
	else if (error_code == ERRCODE_NB_ARG)
		ft_print_error(ERRMSG_NB_ARG);
	else if (error_code == ERRCODE_OPEN)
		ft_print_error(ERRMSG_OPEN);
	else if (error_code == ERRCODE_CUB)
		ft_print_error(ERRMSG_CUB);
	else if (error_code == ERRCODE_READ)
		ft_print_error(ERRMSG_READ);
	else if (error_code == ERRCODE_MAP_VOID)
		ft_print_error(ERRMSG_MAP_VOID);
	else if (error_code == ERRCODE_XPM_FILE)
		ft_print_error(ERRMSG_XPM_FILE);
	else if (error_code == ERRCODE_NB_MAX_COLOR)
		ft_print_error(ERRMSG_NB_MAX_COLOR);
	else if (error_code == ERRCODE_NB_NEG_COLOR)
		ft_print_error(ERRMSG_NB_NEG_COLOR);
	else if (error_code == ERRCODE_COLOR_NO)
		ft_print_error(ERRMSG_COLOR_NO);
	else if (error_code == ERRCODE_LINE)
		ft_print_error(ERRMSG_LINE);
	else
		return (print_error_message2(error_code));
	return (1);
}

int	print_error_message_val(int error_code, int code)
{
	print_error_message(error_code);
	return (code);
}
