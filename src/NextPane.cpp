#include <ncurses.h>
#include "Pane.h"

	NextPane::NextPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void NextPane::draw(Board &b){
		init_pair(4, COLOR_CYAN, COLOR_BLACK);
		wattron(win_, COLOR_PAIR(4));
		box(win_,0,0);
		mvwprintw(win_, 0,width_/2-5, "N E X T");
		wattroff(win_, COLOR_PAIR(4));
		wattron(win_, COLOR_PAIR(13));
		mvwhline(win_, 2, 1, ACS_CKBOARD, 20);
		mvwhline(win_, 3, 1, ACS_CKBOARD, 20);
		wattroff(win_, COLOR_PAIR(13));

		if(b.nextblock == 1){
                	wattron(win_, COLOR_PAIR(11)); // 파란색 켠다
                	mvwhline(win_, 2, 8, ACS_CKBOARD, 8); // 테트로미노
                	wattroff(win_, COLOR_PAIR(11)); // 파란색 끈다
		}
		if(b.nextblock == 2){
                	wattron(win_, COLOR_PAIR(6)); // 빨간색 켠다
                	mvwhline(win_, 2, 10, ACS_CKBOARD, 4);
                	mvwhline(win_, 3, 10, ACS_CKBOARD, 4);
                	wattroff(win_, COLOR_PAIR(6)); // 빨간색 끈다
		}
		if(b.nextblock == 3){
                	wattron(win_, COLOR_PAIR(7)); // 보라색 켠다
                	mvwhline(win_, 2, 9, ACS_CKBOARD, 6); // 테트로미노 그린다
                	mvwhline(win_, 3, 9, ACS_CKBOARD, 2); // 테트로미노
                	wattroff(win_, COLOR_PAIR(7)); // 보라색 끈다
		}
		if(b.nextblock == 4){
                	wattron(win_, COLOR_PAIR(12)); // 흰색 켠다
                	mvwhline(win_, 2, 9, ACS_CKBOARD, 6);
                	mvwhline(win_, 3, 13, ACS_CKBOARD, 2);
                	wattroff(win_, COLOR_PAIR(12)); // 흰색 끈다
		}
		if(b.nextblock == 5){
                	wattron(win_, COLOR_PAIR(9)); // 초록색 켠다
                	mvwhline(win_, 2, 9, ACS_CKBOARD, 4);
                	mvwhline(win_, 3, 7, ACS_CKBOARD, 4);
                	wattroff(win_, COLOR_PAIR(9)); // 초록색 끈다
		}
		if(b.nextblock == 6){
                	wattron(win_, COLOR_PAIR(10)); // 시안색 켠다
               		mvwhline(win_, 2, 9, ACS_CKBOARD, 4);
                	mvwhline(win_, 3, 11, ACS_CKBOARD, 4);
                	wattroff(win_, COLOR_PAIR(10)); // 시안색 끈다
		}
		if(b.nextblock == 7){
                	wattron(win_, COLOR_PAIR(8)); // 노란색 켠다
                	mvwhline(win_, 2, 9, ACS_CKBOARD, 6); // 테트로미노      
                	mvwhline(win_, 3, 11, ACS_CKBOARD, 2); // 테트로미노
               		wattroff(win_, COLOR_PAIR(8)); // 노란색 끈다
		}
		wrefresh(win_);
	}




