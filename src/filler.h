/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 18:41:47 by jboer          #+#    #+#                */
/*   Updated: 2019/12/14 16:25:39 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <fcntl.h>

# define MD		filler->map.mapdata
# define X		filler->map.x
# define Y		filler->map.y
# define TP		filler->token.piece
# define XDIM	filler->token.xdim
# define YDIM	filler->token.ydim
# define XL		filler->token.xl
# define YU		filler->token.yu
# define YD		filler->token.yd
# define XR		filler->token.xr
# define OP		filler->opponent
# define PLAYER	filler->player
# define DIS	filler->dis

typedef struct		s_token
{
	int				xdim;
	int				ydim;
	int				xl;
	int				yu;
	int				yd;
	int				xr;
	char			**piece;
}					t_token;

typedef struct		s_map
{
	int				x;
	int				y;
	char			**mapdata;
}					t_map;

typedef struct		s_filler
{
	t_token			token;
	t_map			map;
	int				xbest;
	int				ybest;
	int				dis;
	char			player;
	char			opponent;
	int				cheatcount;
	int				hittop;
	int				hitbot;
	int				space;
	int				side;
}					t_filler;

void				get_map(t_filler *filler);
void				createtokenpiece(t_filler *filler);
void				getpiece(t_filler *filler);
void				adddim(t_filler *filler);
void				placepiece(t_filler *filler);
char				*get_new_points(t_filler *filler);
void				getside(t_filler *filler);
int					checkdistwo(t_filler *filler, int i, int j);
int					checkdisthree(t_filler *filler, int i, int j);
int					morechecks(t_filler *filler, int i, int j);
void				freetoken(t_filler *filler);

#endif
