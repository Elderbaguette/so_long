/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:31:01 by marbaret          #+#    #+#             */
/*   Updated: 2023/02/10 11:33:31 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftprintfgnl/libftprintfgnl.h"
# include "mlx.h"

typedef struct s_data
{
	char	**map;
	char	**cap;
	void	*win;
	void	*mlx;
	void	**img;
	int		p;
}	t_data;

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	counter(t_data *data, int nb);
int		put_road(t_data *data, int x, int y, int i);
int		put_item(t_data *data, int x, int y, int i);
int		put_exit(t_data *data, int x, int y, int i);
int		put_player(t_data *data, int x, int y, int i);
int		put_wall(t_data *data, int x, int y, int i);
void	*ft_memset(void *pointer, int value, size_t count);
int		playermove(t_data *data, int event_trigger);
int		read_map(t_data *data, int fd);
int		put_img(t_data *data, int *player_p, int *index);
int		check_path(t_data *data);
int		sl_check_error(t_data *data);
int		so_long(t_data *data);
int		init_mlx(t_data *data);
char	**ft_split(char const *s, char c);
int		mapsize(t_data *data, int i);
int		key_event(int event_trigger, t_data *data);
void	so_exit(t_data *data);
int		check_path(t_data *data);
int		close_window(t_data *data);
int		alloc_img(t_data *data);
void	free_img(t_data *data);
void	free_tab(char **str);
void	final_free(t_data *data);
void	free_img_error(t_data *data, int i);
int		check_arg(char *av);

#endif
