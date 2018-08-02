/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:30:30 by tnghondz          #+#    #+#             */
/*   Updated: 2018/07/26 13:23:37 by tnghondz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"

void find_left_start_p(t_map_piece *info)
{
	int	x;
	int	y;

	x = 0;		
	while(x < info->x_piece)
	{
		y = 0;
		while(y < info->y_piece)
		{
			if(info->piece[y][x] == '*')
			{
				info->p_left_start = x;
				return ;
			}
			y++;
		}
	x++;
	}
}

void find_top_start_p(t_map_piece *info)
{
	int	x;
	int	y;
	y = 0;
	while(y < info->y_piece)
	{
		x = 0;
		while(x < info->y_piece)
		{
			if(info->piece[y][x] == '*')
			{
				info->p_top_start = y;
				return ;
			}  	
			x++;
		}
		y++;
	}
}
void find_right_end_p(t_map_piece *info)
{
	int	x;
	int	y;
	x = info->x_piece - 1;
	while(x >= 0)
	{
		y = info->y_piece - 1;
		while(y >= 0)
		{
			if(info->piece[y][x] == '*')
			{
				info->p_right_end = x;
				return ;
			}
			y--;
		}
		x--;
	}
}
void find_bottom_end_p(t_map_piece *info)
{
	int	x;
	int	y;
	y = info->y_piece - 1;
 	while(y >= 0)
	{
		x = info->x_piece - 1;
		while(x >= 0)
		{
			if(info->piece[y][x] == '*')
			{
				info->p_bottom_end = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void trim(t_map_piece * info)
{
    find_bottom_end_p(info);
    find_left_start_p(info);
    find_right_end_p(info);
    find_top_start_p(info);
}