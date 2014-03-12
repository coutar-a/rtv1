/*
** stuff.c for wolf3d in /home/coutar_a/Documents/I_graph/wolf3d
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat Jan 11 16:16:43 2014 coutar_a
** Last update Mon Feb 17 16:54:00 2014 coutar_a
*/

#include <mlx.h>
#include "rtv1.h"

int		do_a_thing(t_dump *ptr)
{
  char		*data_ptr;
  int		sizeline;
  int		bpp;
  int		endian;

  data_ptr = mlx_get_data_addr(ptr->img_ptr, &bpp, &sizeline, &endian);
  ptr->img = data_ptr;
  ptr->sizeline = sizeline;
  ptr->bpp = bpp;
  ptr->endian = endian;
  return (0);
}
