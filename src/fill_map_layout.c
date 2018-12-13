#include "../includes/filler.h"

int		**create_layout(t_desc *desc)
{
	int **layout;
	int i;

	i = -1;
	layout = (int**)malloc(sizeof(int*) * desc->b_height);
	while (++i < desc->b_height)
		layout[i] = (int*)malloc(sizeof(int) * desc->b_width);
	return (layout);
}

void	fill_digits(int **layout, t_desc *desc, int y, int x)
{
	char p;

	p = (char)(desc->p == 1 ? 'O' : 'X');

}

int 	**fill_map_layout(t_desc *desc)
{
	int		**layout;
	char	p;
	int 	i;
	int 	j;

	layout = create_layout(desc);
	p = (char)(desc->p == 1 ? 'O' : 'X');
	i = 0;
	j = 0;
	while (i < desc->b_height && !ft_strchr(desc->map[i], p))
		i++;
	while (desc->map[i][j] != p)
		j++;
	fill_digits(layout, desc, i, j);
	return (layout);
}
