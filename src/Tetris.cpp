#include <ncurses.h>
#include "Tetris.h"
#include "Pane.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

	Tetris::Tetris() : b(B_WIDTH, B_HEIGHT){
		initscr(); // curses mode로 터미널 초기화
		start_color(); // 색을 사용하기 위해 호출
		keypad(stdscr, TRUE);
		noecho();
		cbreak(); // 라인 버퍼링 비활성화
		refresh(); // refresh를 써줘야 화면에 출력된다

		for(int i=0; i<100; i++){
			name[i] = '\0';
		}

		// 각 Pane들의 좌표와 크기를 할당한다.
		infoPane_ = new InfoPane(1,1,25,5);
		helpPane_ = new HelpPane(1,6,25,12);
		nextPane_ = new NextPane(1,18,25,5);
		boardPane_ = new BoardPane(30,0,24,24);
		statPane_ = new StatPane(60,3,20,20);
	}

	void Tetris::setname(char *string){
		for(int i=0; i<100; i++){
			name[i] = string[i];
		}
	}

	Tetris::~Tetris(){
		delete infoPane_;
		delete helpPane_;
		delete nextPane_;
		delete boardPane_;
		delete statPane_;
		endwin(); // 최종적으로 curses 모드를 끝내주어야 한다.
	}

	void Tetris::play(){
		b.setName(name);
		srand(time(NULL));
		int input;
		bool gameOver = false;
		bool newBlock = false;
		int nextBlock = rand()%7 +1; // 다음 블록을 나타내는 변수
		int curBlock; // 현재 블록을 나타내는 변수
		updateScreen();
		input = getch();


		while(1){ // 새로운 블록을 생성하는 반복문
			curBlock = nextBlock;
			nextBlock = rand()%7+1; // 새로운 블록 랜덤 생성
			b.setNextBlock(nextBlock); // 다음 블록 넘겨줌
			b.eraseBlock(); // 일단 꽉찬블록 다 지워주고
			gameOver = !b.insertBlock(curBlock);
			updateScreen();
			if(gameOver){
				input = getch();
				break;
			}
			while(!newBlock){
				input = getch();
				switch(input){
					case KEY_LEFT:
						newBlock = !b.moveBlockLeft(curBlock);
						break;
					case KEY_RIGHT:
						newBlock = !b.moveBlockRight(curBlock);
						break;
					case KEY_DOWN:
						newBlock = !b.moveBlockDown(curBlock);
						break;
					case KEY_UP:
						newBlock = !b.rotateBlock(curBlock);
						break;
					case ' ':
						b.dropBlock(curBlock);
						newBlock = true;
						break;
				}
				updateScreen();
			}
			newBlock = false;
		}
	}

	void Tetris::replay(ifstream &instream){
		instream >> name;
		b.setName(name);
		int seed;
		instream >> seed;
		srand(seed);
		char input;
		bool gameOver = false;
		bool newBlock = false;
		int nextBlock = rand()%7+1;
		int curBlock;
		updateScreen();
		input = getch();


		while(1){ // 새로운 블록을 생성하는 반복문
			curBlock = nextBlock;
			nextBlock = rand()%7+1; // 새로운 블록 랜덤 생성
			b.setNextBlock(nextBlock); // 다음 블록 넘겨줌
			b.eraseBlock(); // 일단 꽉찬블록 다 지워주고
			if(gameOver){
				input = getch();
				break;
			}
			nextBlock = rand()%7+1;
			gameOver = !b.insertBlock(curBlock);
			updateScreen();
			if(gameOver){
				input = getch();
				break;
			}
			while(!newBlock){
				instream >> input;
				switch(input){
					case 'l':
						newBlock = !b.moveBlockLeft(curBlock);
						break;
					case 'r':
						newBlock = !b.moveBlockRight(curBlock);
						break;
					case 'g':
						newBlock = !b.moveBlockDown(curBlock);
						break;
					case 'd':
						b.dropBlock(curBlock);
						newBlock = true;
						break;
					case 't':
						newBlock = !b.rotateBlock(curBlock);
						break;
						
					case 'q':
						newBlock = true;
						gameOver = true;
						break;
				}
				updateScreen();
			}
			newBlock = false;
		}
	}

	void Tetris::updateScreen(){
		((InfoPane *)infoPane_)->draw(b);
		((HelpPane *)helpPane_)->draw();
		((NextPane *)nextPane_)->draw(b);
		((BoardPane *)boardPane_)->draw(b);
		((StatPane *)statPane_)->draw(b);
	}


