/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_send.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:54:03 by mtshisw           #+#    #+#             */
/*   Updated: 2018/08/02 14:08:56 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"

void	copy_tmp_map(t_map_piece *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(info->temp_map = (char**)malloc(sizeof(char *) * info->y_rows)))
		return ;
	while (y < info->y_rows)
	{
		x = 0;
		info->temp_map[y] = (char *)malloc(sizeof(char) * info->x_cols);
		while (x < info->x_cols)
		{
			info->temp_map[y][x] = info->map[y][x];
			x++;
		}
		y++;
	}
}

int		check_placement(t_map_piece *p_info, t_player *shape)
{
	if (shape->my_shape == 'O')
	{
		if ((p_info->os_num + p_info->add_num - 1) == p_info->temp_os &&
				(p_info->xs_num == p_info->temp_xs))
			return (0);
		else
			return (1);
	}
	else if (shape->my_shape == 'X')
	{
		if ((p_info->xs_num + p_info->add_num - 1) == p_info->temp_xs &&
				(p_info->os_num == p_info->temp_os))
			return (0);
		else
			return (1);
	}
	return (-1);
}

int		move(t_map_piece *info)
{
	if (info->place_ret == 1)
	{
		info->y_place--;
		info->x_place = info->x_cols - 1;
		info->x_place++;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place--;
	return (0);
}

void	send_coordinate(t_map_piece *info)
{
	ft_putnbr(info->place_coordinate_y);
	ft_putchar(' ');
	ft_putnbr(info->place_coordinate_x);
	ft_putchar('\n');
	info->y_place = info->y_rows - 1;
}

int		main(void)
{
	t_player	*me;
	t_map_piece	*map_size;

	me = (t_player *)malloc(sizeof(*me));
	map_size = (t_map_piece *)malloc(sizeof(*map_size));

	algo_1(map_size, me);
	algo_4(map_size, me);
}
