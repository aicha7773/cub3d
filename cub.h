#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pos
{
    double x;
    double y;
}t_pos;

typedef struct s_keys
{
    int w;
    int d;
    int s;
    int a;
    int left;
    int right;
}t_keys;



typedef struct t_data
{
    char **s;
    void *mlx;
    void *window;
    double angle;
    t_pos *pos;
    void	*img;
	char	*addr;
    t_keys  keys;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    double *rays;
}t_data;

void	new_position(t_data *data);
void affiche(t_data *data);
void	carre(t_data *data,int k,int d);
void circle(t_data *data, int centerX, int centerY, int radius);
t_pos *position(char **s);
int check_key(t_data *data);
int	ft_exit(void);
int key_down(int key,t_data *data);
int key_up(int key,t_data *data);
double distance(t_data *data, double angle);
