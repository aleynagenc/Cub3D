/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:00 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:01 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define IMG_WIDTH 256
# define IMG_HEIGHT 256

typedef struct s_cam
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			display;
}				t_cam;

typedef struct s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		r;
	int		l;
}			t_kbd;

typedef struct s_swne
{
	int		s_count;
	int		w_count;
	int		n_count;
	int		e_count;
}			t_swne;

typedef struct s_fc
{
	int		f_count;
	int		c_count;
}			t_fc;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	int		rgb;
}			t_rgb;

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	void	*img;
	char	*imgadd;
	int		img_x;
	int		img_y;
}			t_img;

typedef struct s_plyr
{
	double	loc_x;
	double	loc_y;
	double	dir_x;
	double	dir_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	double	movespd;
	double	rotspd;
	double	cam_x;
	double	cam_y;
	double	map_x;
	double	map_y;
	double	wall_x;
	double	wall_y;
	double	wall_dist;
	int		wall_pass;
	int		wall_dir;
	int		sx;
	int		sy;
}			t_plyr;

typedef struct s_cub
{
	t_rgb	f_rgb;
	t_rgb	c_rgb;
	t_kbd	kbd;
	t_cam	t_cam;
	t_img	img;
	t_swne	swne;
	t_fc	fc;
	t_img	imgs[4];
	t_img	screen;
	t_plyr	g_plyr;
	char	**map;
	int		**i_map;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*imgaddr;
	int		x;
	int		y;
	int		bpp;
	int		line_size;
	int		endian;
	int		color;
	int		draw_start;
	int		draw_end;
	int		lineheight;
	int		arg_count;
	int		i_count;
	int		c_count;
	int		row_cnt;
	int		row_len;
	int		counter;
	int		arg_c;
	int		arg_i;
	int		new_cnt;
	int		map_start_index;
	int		crgb_i;
	int		crgb_j;
	int		frgb_i;
	int		frgb_j;
	char	**res;
	int		res_i;
	int		comma;
}			t_cub;

void	map_control(char **av, t_cub *cub);
int		av_check(char *str);
void	swne_fc_control(char *map, t_cub *cub);
void	begin_reset(t_cub *cub);
void	begin_reset2(t_cub *cub);
char	**ft_split(char const *s, char c, t_cub *cub);
int		ft_strlen(char *str);
void	trans_image_rgb(t_cub *cub);
void	top_map_check(t_cub *cub, int i);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	read_map(t_cub *cub, char *av);
void	read_map2(t_cub *cub, char *av, int fd);
char	*get_map(int fd, char *av);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcmpc(const char *s1, const char s2);
void	crgb_control2(char **rgbno, t_cub *cub);
void	crgb_control(char *Crgb, t_cub *cub);
void	frgb_control(char *Crgb, t_cub *cub);
void	top_map_check(t_cub *cub, int i);
void	game_map_control(t_cub *cub);
int		ft_atoi(char *str);
int		ft_is_digit(char c);
char	*ft_strjoin(char *s1, char *s2, char *s3);
int		gmap_out_check(char **map, char c);
void	game_map_out_control(t_cub *cub);
char	*ft_strchr(const char *str, int c);
int		ft_atoic(char str);
void	gmap_int(t_cub *cub);
char	location_init(char cmap, int i, int j, t_cub *cub);
void	number_control(int i);
void	map_zero_control(t_cub *cub);
void	error_message(void);
void	skip_line2(int e, int i, int t, char **m);
void	skip_line1(int e, int i, int t, char **m);
char	*ft_strdup(char *s1);
char	**ft_split2(char const *s, char c, t_cub *cub);
void	mlx_image_make(t_cub *cub);
void	wall_image_make(t_cub *cub);
void	raycasting_column_start_end(t_cub *cub);
void	raycasting_all(t_cub *cub);
void	button_assignment(t_cub *cub);
int		button_down(int key, t_cub *cub);
int		button_up(int key, t_cub *cub);
int		ft_exit(void *tmp);
void	key_move(t_cub *cub, t_cam *cam);
void	raycasting_init(t_cub *cub);
void	raycasting_player_angle(t_cub *cub);
void	raycasting_wall_pass(t_cub *cub);
void	raycasting_wall_dist(t_cub *cub);
void	raycasting_wall_orien(t_cub *cub);
int		print_map(t_cub *cub);
void	c_rgb_down_color(t_cub *cub);
void	f_rgb_up_color(t_cub *cub);
void	game_pixel_put(t_cub *cub, int x, int y, int color);
void	map_char_control(char *map);
void	map_out_control(char *map);
void	map_valid_check(char *map, t_cub *cub);
int		map_len(char *av);
void	map_control(char **av, t_cub *cub);
void	error_comma(t_cub *cub);
void	comma_counter(char map, t_cub *cub);
void	swne_control(char *map, t_cub *cub, int *index);
void	first_space_error(void);
int		first_space_wall(char map, t_cub *cub, int *index);
int		space_tab_control(char *map, int *index);
void	fc_control(char *map, t_cub *cub, int *index);
void	error_file(void);
void	free_fcno(char **rgb);
#endif
