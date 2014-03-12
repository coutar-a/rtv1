/*
** basic_functions.c for basic_functions in /home/coutar_a/rendu/101pong
** 
** Made by coutar_a
** Login   <coutar_a@epitech.net>
** 
** Started on  Tue Nov 12 15:54:12 2013 coutar_a
** Last update Tue Feb 18 11:26:26 2014 coutar_a
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_getnbr(char *str)
{
  int	a;
  int	n;
  int	c;

  a = 0;
  n = 0;
  c = 1;
  while (str[a] != '\0')
    {
      while (str[a] < '0' || str[a] > '9')
	{
	  if (str[a] == '-')
	      c = c * (-1);
	  else
	    return (n * c);
	  a = a + 1;
	}
      while (str[a] >= '0' && str[a] <= '9')
	{
	  n = n * 10;
	  n = n + (str[a] - 48);
	  a = a + 1;
	}
    }
  if (n < 0)
    return (0);
  else
    return (n * c);
}


void	my_put_nbr(int nb)
{
  int	a;
  int	n;
  
  a = 1;
  n = 0;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  while ((nb / a) >= 10)
    a = a * 10; 
  while (a != 0)
    {
      n = nb / a;
      n = n % 10;
      my_putchar(n + 48);
      a = a / 10;
    }
}
