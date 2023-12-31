/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:36:55 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/12 15:15:06 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spawn_dir(t_aff *aff, char player)
{
	if (player == 'N')
	{
		aff->dir_x = -1;
		aff->plan_y = 0.66;
	}
	if (player == 'S')
	{
		aff->dir_x = 1;
		aff->plan_y = -0.66;
	}
	if (player == 'E')
	{
		aff->dir_y = 1;
		aff->plan_x = 0.66;
	}
	if (player == 'W')
	{
		aff->dir_y = -1;
		aff->plan_x = -0.66;
	}
}

void	spawn_player(t_aff *aff)
{
	int	i;
	int	j;

	i = 0;
	while (aff->info->map[i])
	{
		j = -1;
		while (aff->info->map[i][++j])
			if (aff->info->map[i][j] == 'N' || aff->info->map[i][j] == 'S'
				|| aff->info->map[i][j] == 'E' || aff->info->map[i][j] == 'W')
				break ;
		if (aff->info->map[i][j] != '\0')
			break ;
		i++;
	}
	aff->pos_x += i;
	aff->pos_y += j;
	spawn_dir(aff, aff->info->map[i][j]);
	aff->info->map[i][j] = '0';
}

int	ft_init_aff(t_aff *aff, t_info *info)
{
	aff->plan_x = 0;
	aff->plan_y = 0;
	aff->dir_x = 0;
	aff->dir_y = 0;
	aff->info = info;
	aff->pos_x = 0.5;
	aff->pos_y = 0.5;
	aff->w = WIDTH;
	aff->h = HEIGHT;
	aff->c = (0 << 24 | info->ceiling.r << 16 | info->ceiling.g << 8
			| info->ceiling.b);
	aff->f = (0 << 24 | info->ground.r << 16 | info->ground.g << 8
			| info->ground.b);
	aff->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!aff->img)
	{
		ft_free_img(aff->info);
		ft_free_map(aff->info->map);
		mlx_destroy_display(aff->info->mlx);
		free(aff->info->mlx);
		free(aff->info);
		free(aff);
		return (print_error_message(ERRCODE_NEW_IMAGE));
	}
	return (0);
}

int	ft_start(int argc, char **argv, t_info **info, t_aff **aff)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (print_error_message(ERRCODE_MALLOC));
	*aff = malloc(sizeof(t_aff));
	if (!*aff)
	{
		free(*info);
		return (print_error_message(ERRCODE_MALLOC));
	}
	(*info)->mlx = mlx_init();
	if (!(*info)->mlx)
	{
		free(*aff);
		free(*info);
		return (print_error_message(ERRCODE_MLX));
	}
	if (ft_parsing(argc, argv, *info) == 1)
	{
		free(*aff);
		mlx_destroy_display((*info)->mlx);
		free((*info)->mlx);
		free(*info);
		return (1);
	}
	return (ft_init_aff(*aff, *info));
}
