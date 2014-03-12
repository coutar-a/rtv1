/*
** draw_line.c for fdf in /home/coutar_a/Documents/I_graph/tp_04/draw_line
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon Dec  2 17:31:27 2013 coutar_a
** Last update Fri Dec  6 16:05:48 2013 coutar_a
*/

#include "fdf.h"

int	draw_line_horizontal(int x1, int y1, int x2, int y2, t_ptr *ptr)
{
  int	x;

  if (x2 < x1)
    {
      x = x2;
      while (x++ <= x1)
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, x, Y_PLOT(x2, y2, x1, y1, x), 0xFFFFFF);
    }   
  if (x2 > x1)
    {
      x = x1;
      while (x++ <= x2)
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, x, Y_PLOT(x1, y1, x2, y2, x), 0xFFFFFF);
    }
}

int	draw_line_vertical(int x1, int y1,  int x2, int y2, t_ptr *ptr)
{
  int	y;

  if (y2 > y1)
    {
      y = y2;
      while (y-- >= y1)
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, X_PLOT(x2, y2, x1, y1, y), y, 0xFFFFFF);
    }
  if (y1 > y2)
    {
      y = y1;
      while (y-- >= y2)
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, X_PLOT(x1, y1, x2, y2, y), y, 0xFFFFFF); 
    }
}

int	draw_line(int x1, int y1, int x2, int y2, t_ptr *ptr)
{
  if (ABS((x2 - x1)) > ABS((y2 - y1)))
    draw_line_horizontal(x1, y1, x2, y2, ptr);
  if (ABS((x2 - x1)) <= ABS((y2 - y1)))
    draw_line_vertical(x1, y1, x2, y2, ptr);
}
