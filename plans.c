/*
** plans.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Mar  7 16:45:58 2014 coutar_a
** Last update Tue Mar 11 13:56:47 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

void	define_plan1(t_obj *plan)
{
  plan->type = 'p';
  plan->x = 0.0;
  plan->y = 0.0;
  plan->z = 1.0;
  plan->r_a = 0.0;
  plan->color = 0xFF55FF;
  plan->brill = 0.1;
}
