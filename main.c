/*
** main.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Sat Feb 15 13:33:14 2014 coutar_a
** Last update Wed Mar 12 12:59:15 2014 coutar_a
*/

#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

int	fill_image(t_dump *ptr, t_eye *eye)
{
  int	pixel;
  int	x;
  int	y;

  do_a_thing(ptr);
  x = 0;
  y = 0;
  my_putstr("Doin thangs...\n");
  while (y != ptr->win_y)
    {
      while (x != ptr->win_x)
	{
	  if (y == 0 && x == 1)
	    translation_eye(eye, -300.0, 0.0, 50.0);
	  pixel = calc(ptr, x, y, eye);
	  ptr->color = mlx_get_color_value(ptr->mlx_ptr, pixel);
	  my_pixel_put_to_image(ptr->img, x, y, ptr);
	  x++;
	}
      x = 0;
      y++;
    }
  return (0);
}

void		sub_calc_vc(t_3d *pt, t_eye *eye, t_3d *vector)
{
  float		trans[3][3];

  vector->x = pt->x - eye->x;
  vector->y = pt->y - eye->y;
  vector->z = pt->z - eye->z;
  matrix_rot_x(trans, eye->angle_x);
  trans_pt(vector, trans);
  matrix_rot_y(trans, eye->angle_y);
  trans_pt(vector, trans);
  matrix_rot_z(trans, eye->angle_z);
  trans_pt(vector, trans);
}

void		sub_calc_pt(t_dump *ptr, t_3d *pt, int x, int y)
{
  pt->x = 100.0;
  pt->y = (ptr->win_x / 2) - (x);
  pt->z = (ptr->win_y / 2) - (y);
}

int		color_picker(t_obj *scene[2], t_sec *inter_array[2])
{
  t_3d		spot;

  define_spot1(&spot);
  if (inter_array[0]->k > 0.0 && inter_array[1]->k > 0.0)
    {
      if (k1->k < k2->k)
	return (lumos(&spot, k1));
      return (lumos(&spot, k2));
    }
  else if (k1->k > 0.0 && k2->k == 0.0)
    return (lumos(&spot, k1));
  else if (k2->k > 0.0 && k1->k == 0.0)
    return (lumos(&spot, k2));
  return (COLOR_DEFAULT);
}

int		calc(t_dump *ptr,int x, int y, t_eye *eye)
{
  t_3d		point;
  t_3d		vector;
  t_sec		k_sphere;
  t_sec		k_plan;
  t_obj		scene[2];
  t_sec		inter_array[2];
  t_obj		plan1;
  t_obj		sphere1;

  sub_calc_pt(ptr, &point, x, y);
  sub_calc_vc(&point, eye, &vector);
  define_scene(&scene);
  calc_inter(&scene, &inter_array, eye, vc);
  process_k(&scene, &inter_array, eye, vc);
  return (color_picker(&scene, &inter_array));
}

/* int		color_picker(t_sec *k1, t_sec *k2) */
/* { */
/*   int		color_default; */
/*   t_3d		spot; */

/*   color_default = 0x2FD1D4; */
/*   define_spot1(&spot); */
/*   if (k1->k > 0.0 && k2->k > 0.0) */
/*     { */
/*       if (k1->k < k2->k) */
/* 	return (lumos(&spot, k1)); */
/*       return (lumos(&spot, k2)); */
/*     } */
/*   else if (k1->k > 0.0 && k2->k == 0.0) */
/*     return (lumos(&spot, k1)); */
/*   else if (k2->k > 0.0 && k1->k == 0.0) */
/*     return (lumos(&spot, k2)); */
/*   return (color_default); */
/* } */

/* int		calc(t_dump *ptr,int x, int y, t_eye *eye) */
/* { */
/*   t_3d		point; */
/*   t_3d		vector; */
/*   t_sec		k_sphere; */
/*   t_sec		k_plan; */
/*   t_obj		plan1; */
/*   t_obj		sphere1; */

/*   sub_calc_pt(ptr, &point, x, y); */
/*   define_sphere3(&sphere1); */
/*   define_plan1(&plan1); */
/*   sub_calc_vc(&point, eye, &vector); */
/*   alt_sphere_int(&k_sphere, eye, &vector, &sphere1); */
/*   alt_plan_int(&k_plan, eye, &vector, &plan1); */
/*   process_k_sphere(&k_sphere, eye, &vector, &sphere1); */
/*   process_k_plan(&k_plan, eye, &vector, &plan1); */
/*   return (color_picker(&k_sphere, &k_plan)); */
/* } */

int		main(void)
{
  t_dump	ptr;
  t_eye		eye;

  eye.x = 0.0;
  eye.y = 0.0;
  eye.z = 0.0;
  eye.angle_x = 0.0;
  eye.angle_y = 0.0;
  eye.angle_z = 0.0;
  ptr.win_x = 1024;
  ptr.win_y = 768;
  ptr.mlx_ptr = mlx_init();
  ptr.win_ptr = mlx_new_window(ptr.mlx_ptr,
			       ptr.win_x, ptr.win_y, "trace them rays boy");
  ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, ptr.win_x, ptr.win_y);
  fill_image(&ptr, &eye);
  mlx_key_hook(ptr.win_ptr, key_event, 0);
  mlx_expose_hook(ptr.win_ptr, expose_redraw, &ptr);
  mlx_loop(ptr.mlx_ptr);
  return (0);
}
