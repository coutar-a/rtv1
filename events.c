/*
** events.c for rtv1.c in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat Feb 15 13:51:53 2014 coutar_a
** Last update Tue Feb 18 15:28:58 2014 coutar_a
*/

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "rtv1.h"

int	key_event(int keycode)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

int	expose_redraw(t_dump *ptr)
{
  mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
  return (0);
}
