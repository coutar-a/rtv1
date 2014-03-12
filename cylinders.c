/*
** cylinders.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:47:28 2014 coutar_a
** Last update Tue Mar 11 13:36:03 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

void	define_cyl(t_obj *cyl)
{
  cyl->type = 'c';
  cyl->x = 0.0;
  cyl->y = 0.0;
  cyl->z = 0.0;
  cyl->r_a = 100.0;
  cyl->color = 0xAAAAAA;
  cyl->brill = 0.82;
}
