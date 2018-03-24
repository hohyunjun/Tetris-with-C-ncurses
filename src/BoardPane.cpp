#include <ncurses.h>
#include "Pane.h"
#include "Board.h"

	BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
	void BoardPane::draw(Board &b){
		init_pair(5, COLOR_BLUE, COLOR_BLACK); // IBLOCK, 테두리
		init_pair(6, COLOR_RED, COLOR_BLACK); // OBLOCK
		init_pair(13, COLOR_BLACK, COLOR_BLACK); // VOID인 부분 지워주기
		wattron(win_, COLOR_PAIR(5));
		mvwvline(win_, 1, 0, ACS_DIAMOND, height_ -4); // win_의 1,0 좌표값부터 다이아몬드를 height -4개 찍는다(왼쪽 ㅣ)
		mvwvline(win_, 1, width_-1, ACS_DIAMOND, height_-4); // win_의 1, width-1 좌표값부터 다이아몬드를 height -4개 찍는다.(오른쪽 ㅣ)
		mvwhline(win_, height_-4, 0, ACS_DIAMOND, width_); // win_의 height-4,0 좌표값부터 다이아몬드를 width개 찍는다.(아래 ㅡ)

		for(int i=1; i<b.height; i++){ // 1부터 19까지
			for(int j=0; j<b.width/2+1; j++){ // 0 부터 9까지
				
				if(b.cells[i][j] == T){
					wattron(win_, COLOR_PAIR(8));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(8));
				}
				else if(b.cells[i][j] == Z){
					wattron(win_, COLOR_PAIR(10));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(10));
				}
				else if(b.cells[i][j] == S){
					wattron(win_, COLOR_PAIR(9));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(9));
				}
				else if(b.cells[i][j] == J){
					wattron(win_, COLOR_PAIR(12));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(12));
				}
				else if(b.cells[i][j] == L){
					wattron(win_, COLOR_PAIR(7));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(7));
				}
				else if(b.cells[i][j] == I){
					wattron(win_, COLOR_PAIR(5));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(5));
				}
				else if(b.cells[i][j] == O){
					wattron(win_, COLOR_PAIR(6));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(6));
				}
				else if(b.cells[i][j] == VOID){
					wattron(win_, COLOR_PAIR(13));
					mvwhline(win_, i, 2+2*j, ACS_CKBOARD, 2);
					wattroff(win_, COLOR_PAIR(13));	
				}
			}
		}

		wattroff(win_, COLOR_PAIR(5));
		wrefresh(win_);
	}


