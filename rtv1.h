/*
** rtv1.h for rtv1 in /home/coutar_a/rendu/MUL_2013_fdf
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Nov 15 17:56:41 2013 coutar_a
** Last update Wed Mar 12 12:46:56 2014 coutar_a
*/

#ifndef RTV1_H_
# define RTV1_H_
# define CPR_MIN(x, y) (x < y ? x : y)
# define COLOR_DEFAULT (0x2FD1D4)

typedef struct	s_dump
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*img;
  int		sizeline;
  int		bpp;
  int		endian;
  unsigned long	color;
  int		win_x;
  int		win_y;
}		t_dump;

typedef struct	s_3d
{
  float		x;
  float		y;
  float		z;
  int		color;
}		t_3d;

typedef struct	s_sec
{
  float		k;
  float		p_x;
  float		p_y;
  float		p_z;
  float		x_n;
  float		y_n;
  float		z_n;
  int		color;
  float		brill;
}		t_sec;

typedef struct	s_eye
{
  float		x;
  float		y;
  float		z;
  float		angle_x;
  float		angle_y;
  float		angle_z;
}		t_eye;

typedef struct	s_obj
{
  char		type;
  float		x;
  float		y;
  float		z;
  float		r_a;
  int		color;
  float		brill;
}		t_obj;

typedef struct	s_secs
{
  int		nb_obj;
  struct s_node	*first;
  struct s_node	*last;
}		t_scene;

typedef struct	s_node
{
  t_obj		*obj;
  t_sec		*k;
  struct s_node	*next;
}		t_node;

int	key_event(int keycode);
int	expose_redraw(t_dump *ptr);
float	sphere_intersection(t_eye *eye, t_3d *vc, float ray);
float	plan_intersection(t_eye *eye, t_3d *vc);
float	cyl_intersection(t_eye *eye, t_3d *vc, float ray);
float	cone_intersection(t_eye *eye, t_3d *vc, float angle);
int	fill_image(t_dump *ptr, t_eye *eye);
int	calc(t_dump *ptr, int x, int y, t_eye *eye);
int	my_pixel_put_to_image(char *img, int x, int y, t_dump *ptr);
int	do_a_thing(t_dump *ptr);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);

void	define_sphere1(t_obj *sphere);
void	define_sphere2(t_obj *sphere);
void	define_sphere3(t_obj *sphere);
void	define_plan1(t_obj *plan);
void	define_cyl(t_obj *cyl);
void	define_cone1(t_obj *cone);
void	define_spot1(t_3d *spot);
void	alt_sphere_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *sph);
void	alt_plan_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *pl);
void	alt_cyl_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cyl);
void	alt_cone_int(t_sec *k, t_eye *eye, t_3d *vc, t_obj *cone);

void	rotate_z(t_3d *pt, float angle);
void	rotate_x(t_3d *pt, float angle);
void	rotate_y(t_3d *pt, float angle);

void	matrix_rot_z(float matrix[3][3], float angle);
void	matrix_rot_x(float matrix[3][3], float angle);
void	matrix_rot_y(float matrix[3][3], float angle);
void	trans_pt(t_3d *pt, float m[3][3]);
void	translation_point(t_3d *pt, float x_plus, float y_plus, float z_plus);
void	translation_eye(t_eye *eye, float x_plus, float y_plus, float z_plus);
void	process_k_plan(t_sec *k, t_eye *eye, t_3d *vector, t_obj *plan);
void	process_k_sphere(t_sec *k, t_eye *eye, t_3d *vector, t_obj *sphere);
void	process_k_cyl(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cyl);
void	process_k_cone(t_sec *k, t_eye *eye, t_3d *vector, t_obj *cone);
int	lumos(t_3d *spot, t_sec *k);
int	apply_light(float cos_a, t_sec *k, t_3d *spot);
#endif /* !RTV1_H_ */
