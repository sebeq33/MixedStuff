/*
** lemiPC.h for lemiPC.h in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 15:01:26 2013 sebastien bequignon
** Last update Sun Mar 31 21:41:06 2013 sebastien bequignon
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <math.h>

# define PATH		"lemipc"
# define MAP_X		(30)
# define MAP_Y		(30)
# define NSEM		(1)
# define USLEEP_TIME	(200000)
# define MAX_PLAYER	(MAP_X * MAP_Y / 4)
# define MAX_TEAM	(6)
# define SIZE_MSG	(20)

# define IN_GAME(y, x) (x >= 0 && x < MAP_X && y >= 0 && y < MAP_Y)
# define GET_MAP(game, y, x) ((IN_GAME(y, x)) ? game->map[y][x] : 0)
# define IN_TEAM(x) (x > 0 && x <= MAX_TEAM)
# define NB_ALLY(game, x) ((IN_TEAM(x)) ? game->nb_ally[x - 1] : 0)
# define GET_DISTANCE(x0, y0, x1, y1) (sqrt((x1 - x0) * (x1 - x0) \
					+ (y1 - y0) * (y1 - y0)))
# define ABS(x) ((x < 0) ? (x * -1) : (x))
# define GET_DIRECTION(x) ((x == 0) ? (0) : ((x > 0) ? -1 : 1))

typedef struct	s_msg
{
  long		type;
  char		str[SIZE_MSG];
}		t_msg;

typedef struct	s_lemipc
{
  char		map[MAP_Y][MAP_X];
  char		nb_ally[MAX_TEAM];
  int		nb_players;
  int		nb_team;
  int		started;
}		t_lemipc;

typedef struct	s_player
{
  int		nb_team;
  int		x;
  int		y;
  int		chief;
}		t_player;

int		make_game();
t_lemipc	*get_game();
int		sem_lock();
int		sem_unlock();
int		release_game(t_lemipc *);
int		destroy_ipc();
void		die();
int		my_getch(int);
void		*my_puterr_ptr(char *);
int		my_puterr(char *);
int		should_die(t_lemipc *, t_player *);
int		wait_game_start();
int		tick(t_lemipc *, t_player *);
void		remove_player(t_lemipc *, t_player *);
void		die(int);
int		launch_player(int);
void		move_target(t_lemipc *, t_player *, int, int);
void		move_random(t_lemipc *, t_player *);
char		*get_message(int);
int		send_message(int, char *);
int             will_kill(t_lemipc *, t_player *);

#endif /* !LEMIPC_H_ */
