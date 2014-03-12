/*
** test.c for rtv1 in /home/coutar_a/Documents/I_graph/Semestre 2/rtv1
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Fri Feb 28 15:27:29 2014 coutar_a
** Last update Tue Mar 11 10:02:45 2014 coutar_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rtv1.h"

void	test_return(int color)
{
  int 	r;
  int 	g;
  int 	b;
  int	ret;
  r = color >> 16;
  g = color >> 8 & 0xFF;
  b = color & 0xFF;
  printf("r = %d, g = %d, b = %d\n", r, g, b);
}

int			apply_light(float cos_a, int color)
{
  unsigned char 	r;
  unsigned char 	g;
  unsigned char 	b;
  int			ret;

  r = (unsigned char)(color >> 16) * cos_a;
  g = (unsigned char)(color >> 8 & 0xFF) * cos_a;
  b = (unsigned char)(color & 0xFF) * cos_a;
  ret = b;
  ret = ret | g << 8;
  ret = ret | r << 16;
  return (ret);
}

void	main()
{
  int	test;

  test = apply_light(0.5, 0xF9FD90);
  test_return(test);
}
