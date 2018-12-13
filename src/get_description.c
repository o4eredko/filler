#include "../includes/filler.h"

void	get_player_info(int fd, t_desc *desc)
{
	int 	i;
	char	*line;

	i = 0;
	while (++i <= 2)
	{
		get_next_line(fd, &line);
		if (ft_strstr(line, MY_PLAYER))
			desc->p = i;
	}
}

void	get_size(int fd, t_desc *desc)
{
	char	*line;
	get_next_line(fd, &line);
	if (ft_strstr(line, "Plateau"))
	{
		desc->b_height = ft_atoi(line + 8);
		desc->b_width = ft_atoi(line + 8 + count_digits(desc->b_height));
	}
	else if (ft_strstr(line, "Piece"))
	{
		desc->p_height = ft_atoi(line + 6);
		desc->p_width = ft_atoi(line + 6 + count_digits(desc->p_height));
	}
}

void	get_map(int fd, t_desc *desc)
{
	char	*tmp;
	int		i;

	i = -1;
	desc->map = (char**)(malloc(sizeof(char*) * desc->b_height));
	get_next_line(fd, &tmp);
	while (++i < desc->b_height)
		get_next_line(fd, &(desc->map[i]));
	while (i--)
	{
		tmp = ft_strsub(desc->map[i], 4, ft_strlen(desc->map[i]));
		free(desc->map[i]);
		desc->map[i] = tmp;
	}
}

void	get_description(t_desc *desc)
{
	int fd = open("../map", 0);
	get_player_info(fd, desc);
	get_size(fd, desc);
	get_map(fd, desc);
	get_size(fd, desc);
	close(fd);
}
