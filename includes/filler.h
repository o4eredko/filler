#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# define MY_PLAYER "yochered.filler"
# define ABS(x) (x < 0) ? -x : x
//Delete
# include <fcntl.h>

typedef struct		s_desc
{
	int 			p;
	int 			b_height;
	int 			b_width;
	int 			p_height;
	int 			p_width;
	char 			**map;
}					t_desc;

void				get_description(t_desc *desc);
int				 	**fill_map_layout(t_desc *desc);
int					manhattan_distance(int x1, int x2, int y1, int y2);
int					ft_count_digits(int nbr);

#endif
