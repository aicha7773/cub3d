#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../ray-casting/cub.h"

typedef struct s_map
{
	char	**map;
	int		weidth;
	int		height;
	char	*init_map;
	char	**rgb;
	int		rgbc;
	int		rgbf;
	char	*line;
	char	*tmp;
	char	**arr;
	char	*NO;
	char	*EA;
	char	*SO;
	char	*WE;
	char	*c;
	char	*f;
	int		len;
	int		i;

}			t_map;

typedef struct s_unit
{
	int		c;
	int		f;
	int		no;
	int		ea;
	int		so;
	int		we;
	int		count_elem;
	int		num_elem;
}			t_unit;

void		check_filename(char *name);
void		save_map(char *file, t_map *map);
int			check_elem(char **holder, t_unit *elem, int i, t_map *map);
char		*get_next_line(int fd);
void		print_2d(char **str);
t_unit		init_elem(void);
void		East(char *holder, t_map *map);
void		West(char *holder, t_map *map);
void		South(char *holder, t_map *map);
void		North(char *holder, t_map *map);
char		*spaces_end(char *s);
int			check_line(char *holder);
char		*ft_strjoin_modif(char const *s1, char c);
void		Ceiling(char *holder, t_map *map);
void		Floor(char *holder, t_map *map);
int			skip_space(char *s);
int			check_line_cf(char *holder);
void		check_map(char **holder, t_unit *elem, t_map *param);
void		print_error(char *str);
int			ft_strnstr_modf(const char *haystack, const char *needle,
				size_t len);
int			skip_space(char *s);
int			safe_line(char *str);
void		parse_map(t_map *src);
void		get_real_map(t_unit elem, t_map *src, char **map);
int			check_line(char *holder);
char		*spaces_end(char *s);
void		ft_parse(char **map);
void		valid_elem(t_unit elem, char **map);
void		ft_player(char **map);
void		elem_checker(char **map);
int			ft_calculate(char *str, char c);
void		check_sides(int curr, char *next, char *prev);
void		ft_len(char *file, t_map *src);
#endif