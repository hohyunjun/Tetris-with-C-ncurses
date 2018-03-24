#include <ncurses.h>
#include <fstream>
#include <iostream>
#include "Tetris.h"
using namespace std;

int main(){
	
	char string[100];
	for(int i=0; i<100; i++) string[i] = '\0';
	ifstream instream;
	instream.open("input1.txt");
	if(instream.fail()){
		cout << "테트리스 게임을 시작합니다" << endl;
		cout << "사용자의 이름을 입력하세요" << endl;
		cout << "이름 : "; cin >> string;
		Tetris t;
		t.setname(string);
		t.play();
	}

	Tetris t;
	t.replay(instream);

	return 0;
}





