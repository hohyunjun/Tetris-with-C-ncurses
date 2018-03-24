#ifndef _TETRIS_H_
#define _TETRIS_H_
#include "Pane.h"
#include "Board.h"
#include <fstream>
using namespace std;

class Tetris{

	friend class InfoPane;

	static const int B_WIDTH = 18;
	static const int B_HEIGHT = 20;
	Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
	Board b;
	char name[100];

public:
	Tetris();	
	~Tetris();
	void setname(char *string);
	void play();
	void replay(ifstream &instream);
	void updateScreen();
};

#endif
