#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//# include "../parsing/cub3d.h"

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_pos_int
{
	int		x;
	int		y;
}			t_pos_int;

typedef struct s_keys
{
	int		w;
	int		d;
	int		s;
	int		a;
	int		left;
	int		right;
}			t_keys;

typedef struct s_rays
{
	double	dis;
	t_pos	h;
	t_pos	v;
	int		cas;
}			t_rays;

typedef struct t_data
{
	char	**s;
	int weidth;
	int hight;
	void	*mlx;
	void	*window;
	double	angle;
	t_pos	*pos;
	void	*img;
	char	*addr;
	t_keys	keys;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_rays	*rays;
	double	pi;
}			t_data;

void		new_position(t_data *data);
void		affiche(t_data *data);
void		carre(t_data *data, int k, int d);
void		circle(t_data *data, int centerX, int centerY, int radius);
t_pos		*position(char **s);
int			check_key(t_data *data);
int			ft_exit(void);
int			key_down(int key, t_data *data);
int			key_up(int key, t_data *data);
void		distance(t_data *data, double angle, int i);
double		thales(double a, double b, double c);
double		pythagore(t_pos *s, t_pos *d);
void		angle_n(t_data *data, double angle, int i, t_pos_int p);
void		angle_e(t_data *data, double angle, int i, t_pos_int p);
void		angle_s(t_data *data, double angle, int i, t_pos_int p);
void		angle_w(t_data *data, double angle, int i, t_pos_int p);
void		raycasting(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		put_ray(t_data *data, double angle, double dis);
t_pos		*position(char **s);
int			ft_exit(void);
double		thales(double a, double b, double c);
double		pythagore(t_pos *s, t_pos *d);
void		circle(t_data *data, int centerX, int centerY, int radius);
void		put_ray(t_data *data, double angle, double dis);
void		carre(t_data *data, int k, int d);
void		carre_t(t_data *data, int k, int d);
void		initialize_angle(t_data *data);
void		transmitter(char **s,int weidth, int hight);

#endif