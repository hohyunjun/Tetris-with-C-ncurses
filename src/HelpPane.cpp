#include <ncurses.h>
#include "Pane.h"

	HelpPane::HelpPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void HelpPane::draw(){
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		wattron(win_, COLOR_PAIR(1));
		box(win_, 0, 0);
		mvwprintw(win_, 0, width_/2-5, "H E L P");
		wattroff(win_, COLOR_PAIR(1));
		mvwprintw(win_, 2,1, " J : Left");
		mvwprintw(win_, 3,1, " L : Right");
		mvwprintw(win_, 4,1, " I : Rotate");
		mvwprintw(win_, 5,1, " K : Drop");
		mvwprintw(win_, 6,1, " ] : Speed up");
		mvwprintw(win_, 7,1, " N : Draw next");
		mvwprintw(win_, 8,1, " SPACE : Drop");
		wrefresh(win_);
	}



