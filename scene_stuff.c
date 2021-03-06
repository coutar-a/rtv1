/*
** scene_stuff.c for rtv1 in /home/coutar_a/rendu/MUL_2013_rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Tue Mar 11 14:03:59 2014 coutar_a
** Last update Wed Mar 12 12:40:28 2014 coutar_a
*/

#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

void		define_scene(t_obj scene[2])
{
  t_obj		plan1;
  t_obj		sphere1;

  define_plan1(scene[0]);
  define_sphere1(scene[1]);
}

int		find_object_type(t_obj *obj)
{
  if (obj->type == 's')
    return (0);
  if (obj->type == 'c')
    return (1);
  if (obj->type == 'k')
    return (2);
  if (obj->type == 'p')
    return (3);
  return (-1);
}

void		calc_inter(t_obj scene[2], t_sec inter[2], t_eye *eye, t_3d *vc)
{
  int		i;
  void		(inter_array[4])(t_sec*, t_eye*, t_3d*, t_sec*);

  inter_array[0] = &alt_sphere_int;
  inter_array[1] = &alt_cyl_int;
  inter_array[2] = &alt_cone_int;
  inter_array[3] = &alt_plan_int;
  i = 0;
  while (i != 2)
    {
      inter_array[find_object_type(scene[i])](inter[i], eye, vc, scene[i]);
      i++;
    }
}

void		process_k(t_obj scene[2], t_sec inter[2], t_eye *eye, t_3d *vc)
{
  int		i;
  void		(process_array[4])(t_sec*, t_eye*, t_3d*, t_sec*);

  process_array[0] = &process_k_sphere;
  process_array[1] = &process_k_cyl;
  process_array[2] = &process_k_cone;
  process_array[3] = &process_k_plan;
  i = 0;
  while (i != 2)
    {
      process_array[find_object_type(scene[i])](inter[i], eye, vc, scene[i]);
      i++;
    }
}
