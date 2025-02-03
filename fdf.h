/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:01:31 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:47:58 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "macros.h"

typedef struct s_point
{
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_point	**grid;
	int		height;
	int		width;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		scale;
	int		x_offset;
	int		y_offset;
	int		iso;
	int		z_min;
	int		z_max;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	int		autorotate;
}	t_map;

typedef struct s_prjc
{
	int	x;
	int	y;
}	t_prjc;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	err;
	int	step_x;
	int	step_y;
	int	swap_axes;
}	t_bresenham;

size_t	ft_strlen(const char *s);
void	p_exit(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
int		ft_atoi_hex(char *str);
void	ft_bresenham(t_map *map, t_prjc p1, t_prjc p2, int color);
void	put_pixel(t_map *map, int x, int y, int color);
void	ft_draw(t_map *map);
void	*ft_memset(void *s, int c, size_t n);
int		count_words(char *s);
void	ft_get_width_height(char *file, int fd, t_map *map);
void	ft_handle_z_color(char *source, t_point *point);
int		ft_check_arg_and_get_fd(int ac, char *file);
t_point	**ft_fill_2d_array(int fd, t_map map);
void	ft_mlx_init(t_map *map);
void	free_2d_array(t_point **grid, int height);
void	put_pixel(t_map *map, int x, int y, int color);
t_prjc	ft_set_point(int x, int y, int z, t_map *map);
void	ft_draw(t_map *map);
int		handle_close(t_map *map);
int		handle_input(int keycode, t_map *map);
void	zoom(int keycode, t_map *map);
void	move(int keycode, t_map *map);
void	rotate(int keycode, t_map *map);
void	ft_apply_rotation(double *x, double *y, double *z, t_map *map);
void	rotate_x(double *y, double *z, double radian);
void	rotate_y(double *x, double *z, double radian);
void	rotate_z(double *x, double *y, double radian);
double	to_radians(double degrees);
void	menu(t_map map);
void	ft_set_z_min_max(t_map *map);
int		get_color(t_point grid, int z_min, int z_max);
void	free_split(char **s);
int		ft_auto_rotation(t_map *map);

#endif