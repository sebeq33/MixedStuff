#ifndef		HANDLEID_HH_
# define	HANDLEID_HH_

#include <map>
#include <stdint.h>

class			HandleID
{
public:
	HandleID();
  ~HandleID();

  enum ClassName
  {
    GAME,
    CLIENT,
  };

  int16_t getNewId(ClassName);
  void  removeId(int16_t);

private:
	HandleID(HandleID const &);
  HandleID &operator=(HandleID const &);

  std::map<int16_t, ClassName> IDList;
};

#endif /* !HANDLEID_HH_ */
