/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:19:55 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/14 14:30:46 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_skip_line(char *dest, int i)
{
	while (dest[i] == '\n')
		i++;
	return (i);
}

char	*ft_chr_line(char *dest, int *i)
{
	char	*line;
	int		j;

	j = 0;
	line = malloc(sizeof(char) * (ft_strlen_char(dest + *i, '\n') + 1));
	if (line)
	{
		while (dest[j + *i] && dest[j + *i] != '\n')
		{
			line[j] = dest[j + *i];
			j++;
		}
		line[j] = '\0';
	}
	*i += j;
	return (line);
}

int	ft_fill_arg_2(char *line, t_info *info)
{
	if (line[0] == 'S' && line[1] == '4' && line[2] == ' ')
		return (ft_charg_img(&info->spri, line, info));
	free(line);
	if (!info->no.img || !info->so.img || !info->we.img || !info->ea.img
		|| !info->door.img || !info->r.img || !info->s.img || !info->sp.img
		|| !info->spr.img || !info->spri.img || info->ceiling.b == -1
		|| info->ground.b == -1)
		return (print_error_message(ERRCODE_LINE));
	return (-1);
}

int	ft_fill_arg(char *line, t_info *info)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (ft_charg_img(&info->no, line, info));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (ft_charg_img(&info->so, line, info));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (ft_charg_img(&info->we, line, info));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (ft_charg_img(&info->ea, line, info));
	else if (line[0] == 'D' && line[1] == ' ')
		return (ft_charg_img(&info->door, line, info));
	else if (line[0] == 'F' && line[1] == ' ')
		return (ft_charg_color(&info->ground, line));
	else if (line[0] == 'C' && line[1] == ' ')
		return (ft_charg_color(&info->ceiling, line));
	else if (line[0] == 'S' && line[1] == '0' && line[2] == ' ')
		return (ft_charg_img(&info->r, line, info));
	else if (line[0] == 'S' && line[1] == '1' && line[2] == ' ')
		return (ft_charg_img(&info->s, line, info));
	else if (line[0] == 'S' && line[1] == '2' && line[2] == ' ')
		return (ft_charg_img(&info->sp, line, info));
	else if (line[0] == 'S' && line[1] == '3' && line[2] == ' ')
		return (ft_charg_img(&info->spr, line, info));
	return (ft_fill_arg_2(line, info));
}

int	ft_init_arg(t_info *info, char *dest)
{
	int		i;
	int		tmp;
	char	*line;

	i = 0;
	while (dest[i])
	{
		i = ft_skip_line(dest, i);
		if (!dest[i])
			break ;
		line = ft_chr_line(dest, &i);
		if (!line)
			return (print_error_message_val(ERRCODE_MALLOC, -1));
		tmp = ft_fill_arg(line, info);
		if (tmp == 1)
			return (-1);
		if (tmp == -1 || !dest[i])
			break ;
		i++;
	}
	while (i > 0 && --i >= 0 && dest[i] != '\n')
		;
	if (!dest[i])
		return (print_error_message_val(ERRCODE_MAP_VOID, -1));
	return (i);
}
