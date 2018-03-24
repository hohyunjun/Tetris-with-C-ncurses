#include <ncurses.h>
#include "Pane.h"

	StatPane::StatPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void StatPane::draw(Board &b){
		init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6, COLOR_RED, COLOR_BLACK);
		init_pair(8, COLOR_YELLOW, COLOR_BLACK);
		init_pair(9, COLOR_GREEN, COLOR_BLACK);
		init_pair(10, COLOR_CYAN, COLOR_BLACK);
		init_pair(11, COLOR_BLUE, COLOR_BLACK);
		init_pair(12, COLOR_WHITE, COLOR_BLACK);
		
		wattron(win_, COLOR_PAIR(10));
		box(win_, 0, 0); // 윈도우의 범위에 박스를 그린다
		mvwprintw(win_, 0,5, "STATISTICS"); // 윈도우에서의 좌표를 이동하고 거기에 STATISTICS를 넣는다.
		wattroff(win_, COLOR_PAIR(10));
		wattron(win_, COLOR_PAIR(7)); // 보라색 켠다
		mvwhline(win_, 2,1, ACS_CKBOARD, 6); // 테트로미노 그린다
		mvwhline(win_, 2, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 2, width_-4, "%d", b.Lblockcount); // 숫자
		mvwhline(win_, 3,1, ACS_CKBOARD, 2); // 테트로미노
		wattroff(win_, COLOR_PAIR(7)); // 보라색 끈다

		wattron(win_, COLOR_PAIR(11)); // 파란색 켠다
		mvwhline(win_, 4,4, ACS_CKBOARD, 8); // 테트로미노
		mvwhline(win_, 4, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 4, width_-4, "%d", b.Iblockcount); // 숫자
		wattroff(win_, COLOR_PAIR(11)); // 파란색 끈다
		
		wattron(win_, COLOR_PAIR(8)); // 노란색 켠다
		mvwhline(win_, 6,1, ACS_CKBOARD, 6); // 테트로미노	
		mvwhline(win_, 6, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 6, width_-4, "%d", b.Tblockcount); // 숫자
		mvwhline(win_, 7, 3, ACS_CKBOARD, 2); // 테트로미노
		wattroff(win_, COLOR_PAIR(8)); // 노란색 끈다

		wattron(win_, COLOR_PAIR(9)); // 초록색 켠다
		mvwhline(win_, 8, 8, ACS_CKBOARD, 4);
		mvwhline(win_, 8, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 8, width_-4, "%d", b.Sblockcount); // 숫자
		mvwhline(win_, 9, 6, ACS_CKBOARD, 4);
		wattroff(win_, COLOR_PAIR(9)); // 초록색 끈다

		wattron(win_, COLOR_PAIR(10)); // 시안색 켠다
		mvwhline(win_, 10, 1, ACS_CKBOARD, 4);
		mvwhline(win_, 10, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 10, width_-4, "%d", b.Zblockcount); // 숫자
		mvwhline(win_, 11, 3, ACS_CKBOARD, 4);
		wattroff(win_, COLOR_PAIR(10)); // 시안색 끈다

		wattron(win_, COLOR_PAIR(6)); // 빨간색 켠다
		mvwhline(win_, 12, 8, ACS_CKBOARD, 4);
		mvwhline(win_, 12, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 12, width_-4, "%d", b.Oblockcount); // 숫자
		mvwhline(win_, 13, 8, ACS_CKBOARD, 4);
		wattroff(win_, COLOR_PAIR(6)); // 빨간색 끈다

		wattron(win_, COLOR_PAIR(12)); // 흰색 켠다
		mvwhline(win_, 14, 1, ACS_CKBOARD, 6);
		mvwhline(win_, 14, width_/2+3, ACS_S7, 1); // -
		mvwprintw(win_, 14, width_-4, "%d", b.Jblockcount); // 숫자
		mvwhline(win_, 15, 5, ACS_CKBOARD, 2);
		mvwhline(win_, 16, 1, ACS_S7, 18); // ---------
		mvwprintw(win_, 17, 5, "TOTAL"); // Total
		mvwprintw(win_, 17, width_/2+3, ":"); // :
		mvwprintw(win_, 17, width_-4, "%d", b.total); // 숫자
		wattroff(win_, COLOR_PAIR(12)); // 흰색 끈다

		wrefresh(win_);
	}





