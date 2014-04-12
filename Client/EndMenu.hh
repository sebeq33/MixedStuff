#ifndef ENDMENU_HH
#define ENDMENU_HH

#include  "IGUI.hh"

class EndMenu : public IGUI
{
private:
	int score[4];
public:
	EndMenu();
	~EndMenu();
	void update(RType &);
	 void display(RType &);

	 void playAgain();
	 void displayScore() const;
	 void  quit();
};

#endif		/*! ENDMENU_HH */
