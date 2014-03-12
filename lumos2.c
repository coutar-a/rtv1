/*
** lumos2.c for rtv1.h in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Tue Mar 11 10:02:35 2014 coutar_a
** Last update Tue Mar 11 14:21:02 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

int			apply_light(float cos_a, t_sec *k, t_3d *spot)
{
  unsigned char 	r;
  unsigned char 	g;
  unsigned char 	b;
  unsigned char 	r_spot;
  unsigned char 	g_spot;
  unsigned char 	b_spot;
  int			ret;

  r = (unsigned char)(k->color >> 16) * cos_a;
  g = (unsigned char)(k->color >> 8 & 0xFF) * cos_a;
  b = (unsigned char)(k->color & 0xFF) * cos_a;
  r_spot = (unsigned char)(spot->color >> 16) * cos_a;
  g_spot = (unsigned char)(spot->color >> 8 & 0xFF) * cos_a;
  b_spot = (unsigned char)(spot->color & 0xFF) * cos_a;
  r = r * (1 - k->brill) + r_spot * k->brill;
  g = g * (1 - k->brill) + g_spot * k->brill;
  b = b * (1 - k->brill) + b_spot * k->brill;
  ret = b;
  ret = ret | g << 8;
  ret = ret | r << 16;
  return (ret);
}
