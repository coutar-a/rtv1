/*
** lumos.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Mon Mar 10 14:14:59 2014 coutar_a
** Last update Tue Mar 11 16:12:03 2014 coutar_a
*/

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "rtv1.h"

void	process_k_plan(t_sec *k, t_eye *eye, t_3d *vector, t_obj *plan)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = plan->x;
  k->y_n = plan->y;
  k->z_n = plan->z;
  k->color = plan->color;
  k->brill = plan->brill;
}

void	process_k_sphere(t_sec *k, t_eye *eye, t_3d *vector, t_obj *sphere)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - sphere->x;
  k->y_n = k->p_y - sphere->y;
  k->z_n = k->p_z - sphere->z;
  k->color = sphere->color;
  k->brill = sphere->brill;
}

void	process_k_cyl(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cyl)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - cyl->x;
  k->y_n = k->p_y - cyl->y;
  k->z_n = 0;
  k->color = cyl->color;
  k->brill = cyl->brill;
}

void	process_k_cone(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cone)
{
  k->p_x = eye->x + k->k * vector->x;
  k->p_y = eye->y + k->k * vector->y;
  k->p_z = eye->z + k->k * vector->z;
  k->x_n = k->p_x - cone->x;
  k->y_n = k->p_y - cone->y;
  k->z_n = -(tanf(cone->r_a * (M_PI / 180.0))) * k->p_z - cone->z;
  k->color = cone->color;
  k->brill = cone->brill;
}

int	lumos(t_3d *spot, t_sec *k)
{
  t_3d	l;
  float	norm_l;
  float	norm_n;
  float	scal;
  float	cos_a;

  l.x = spot->x - k->p_x;
  l.y = spot->y - k->p_y;
  l.z = spot->z - k->p_z;
  scal = l.x * k->x_n + l.y * k->y_n + l.z * k->z_n;
  norm_l = sqrtf(powf(l.x, 2.0) + powf(l.y, 2.0) + powf(l.z, 2.0));
  norm_n = sqrtf(powf(k->x_n, 2.0) + powf(k->y_n, 2.0) + powf(k->z_n, 2.0));
  cos_a = scal / (norm_l * norm_n);
  if (cos_a < 0.0)
    cos_a = 0.0;
  return (apply_light(cos_a, k, spot));
}
