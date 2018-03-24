#ifndef _PANE_H_
#define _PANE_H_

#include "Board.h"

class Pane{
protected:
	int width_, height_;
	int x_, y_;
	WINDOW *win_;
public:
	Pane(int x, int y, int w, int h);
	virtual ~Pane(){delwin(win_);}
	void draw(){box(win_,0,0); wrefresh(win_);}
};

class InfoPane : public Pane{ // Pane 클래스를 상속받는다
public:
	InfoPane(int x, int y, int w, int h);
	void draw(Board &b);
};

class BoardPane : public Pane{ // Pane 클래스를 상속받는다
public:
	BoardPane(int x, int y, int w, int h);
	void draw(Board &b);
};

class StatPane : public Pane{ // Pane 클래스를 상속받는다
public :
	StatPane(int x, int y, int w, int h);
	void draw(Board &b);
};

class HelpPane : public Pane{ // Pane 클래스를 상속받는다
public :
	HelpPane(int x, int y, int w, int h);
	void draw();
};


class NextPane : public Pane{ // Pane 클래스를 상속받는다
public :
	NextPane(int x, int y, int w, int h);
	void draw(Board &b);
};

#endif


