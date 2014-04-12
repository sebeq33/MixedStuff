#ifndef		GAME_HH_
# define	GAME_HH_

# include <list>
# include "Timer.hh"
# include "Client.hh"
# include "AEntity.hh"
# include "EntityManager.hh"

class Client;

class			Game
{
public:
  enum	GameState
    {
      WAITING_ROOM,
      IN_GAME,
      FINISHED,
    };

  Game(Client *);
  ~Game();

  GameState	getStatus() const;
  void			update(const Timer &, EntityManager &);
  void			addEntity(AEntity *);
  bool      addPlayer(Client *);
  bool      removePlayer(const Client *);
  int16_t   getID() const;
  void      setID(int16_t);
  int8_t    getNBPlayer() const;

private:
  Game(Game const &);
  Game &operator=(Game const &);

  Client								*players[4];
  GameState							status;
  std::list<AEntity *>	entityList;
  int16_t               id;
};

#endif /* !GAME_HH_ */
