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

typedef struct t_data
{
    char **s;
    void *mlx;
    void *window;
    double angle;
    t_pos *pos;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

int	new_position(int key, t_data *data);
void affiche(t_data *data);
void	carre(t_data *data,int k,int d);
void circle(t_data *data, int centerX, int centerY, int radius);

t_pos *position(char **s);
