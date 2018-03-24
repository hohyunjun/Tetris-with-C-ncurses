#include <ncurses.h>
#include "Pane.h"

	InfoPane::InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void InfoPane::draw(Board &b){ // Pane클래스의 가상함수인 draw() 구현
		init_pair(1, COLOR_CYAN, COLOR_BLACK); // 색깔 정의. (색상짝 정의 숫자, 전경색, 후경색)
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);

		wattron(win_, COLOR_PAIR(1));
		box(win_,0,0);
		mvwprintw(win_, 0, width_/2-5, "I N F O"); // win_에서의 커서를 0,0으로 옮기고 INFO PANE 출력
		wattroff(win_, COLOR_PAIR(1));
		mvwprintw(win_, 1, 1, "Your Name : ");
		mvwprintw(win_, 1, width_-10, b.name);
		mvwprintw(win_, 2, 1, "Full Lines : ");
		mvwprintw(win_, 2, width_-5, "%d", b.fulllines);
		mvwprintw(win_, 3, 1, "SCORE :");
		wattron(win_, COLOR_PAIR(2)); // 색깔 속성을 켠다
		mvwprintw(win_, 3, width_-5, "%d", b.fulllines*10);
		wattroff(win_, COLOR_PAIR(2)); // 색깔 속성을 끈다
		wrefresh(win_); // win_를 출력
	}


