#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <unistd.h>

typedef struct t_data
{
    char **s;
    void *mlx;
    void *window;
}t_data;


int	new_position(int key, t_data *data);
void affiche(t_data *data);
void	carre(t_data *data,int k,int d);
