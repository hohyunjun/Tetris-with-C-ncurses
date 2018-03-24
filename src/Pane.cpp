#include <ncurses.h>
#include "Pane.h"


Pane::Pane(int x, int y, int w, int h) : x_(x), y_(y), width_(w), height_(h){
		win_ = newwin(h,w,y,x); // 새로운 윈도우 생성. 윈도우를 처리하기 위한 구조체의 메모리를 할당받음. 
					// 화면의 다른 부분과 독립적으로 처리할 수 있는 가상의 윈도우의 abstraction.
}
