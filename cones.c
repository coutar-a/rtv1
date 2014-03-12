/*
** cones.c for rtv1.h in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:57:33 2014 coutar_a
** Last update Tue Mar 11 13:38:56 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

void	define_cone1(t_obj *cone)
{
  cone->type = 'k';
  cone->x = 0.0;
  cone->y = 0.0;
  cone->z = 60.0;
  cone->r_a = 30.0;
  cone->color = 0xE32B68;
  cone->brill = 0.6;
}
