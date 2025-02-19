/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:02:10 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/19 06:04:24 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(t_data *data)
{
	int	w;
	int	h;
	data->player.img = mlx_xpm_file_to_image(data->mlx.mlx, "./xpm/player.xpm", &w, &h);
	data->wall.img = mlx_xpm_file_to_image(data->mlx.mlx, "./xpm/mur.xpm", &w, &h);
	data->bg.img = mlx_xpm_file_to_image(data->mlx.mlx, "./xpm/fond.xpm", &w, &h);
	data->collec.img = mlx_xpm_file_to_image(data->mlx.mlx, "./xpm/mush.xpm", &w, &h);
	data->exit.img = mlx_xpm_file_to_image(data->mlx.mlx, "./xpm/exit.xpm", &w, &h);
}

void	set_1st_image(t_data *data)
{
	data->val.k = 0;
	data->val.i = 0;
	while (data->map.map[data->val.k])
	{
		while (data->map.map[data->val.k][data->val.i])
		{
			if(data->map.map[data->val.k][data->val.i] == '0')
				put_bg(data);
			else if(data->map.map[data->val.k][data->val.i] == '1')
				put_wall(data);
			else if(data->map.map[data->val.k][data->val.i] == 'P')
				put_player(data);
			else if(data->map.map[data->val.k][data->val.i] == 'C')
				put_collec(data);
			else if(data->map.map[data->val.k][data->val.i] == 'E')
				put_exit(data);
			data->val.i++;
		}
		data->val.i = 0;
		data->val.k += 1;
	}
}
