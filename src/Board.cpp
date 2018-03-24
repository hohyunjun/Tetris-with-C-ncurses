#include "Board.h"
#include "Block.h"

Board::Board(int w, int h) : height(h), width(w){
	cells = new Cell*[h];
	for(int i=0; i<h; i++){
		cells[i] = new Cell[w/2];
		for(int j=0; j<w/2; j++)
			cells[i][j] = VOID;
	}
	fulllines = 0;
	iblock = new IBlock();
	oblock = new OBlock();
	lblock = new LBlock();
	jblock = new JBlock();
	sblock = new SBlock();
	zblock = new ZBlock();
	tblock = new TBlock();
	
	Iblockcount = 0;
	Oblockcount = 0;
	Lblockcount = 0;
	Jblockcount = 0;
	Sblockcount = 0;
	Zblockcount = 0;
	Tblockcount = 0;
	total = 0;
	nextblock = 0;

	for(int i=0; i<100; i++){
		name[i] = '\0';
	}

}

void Board::setName(char *string){

	for(int i=0; i<100; i++){
		name[i] = string[i];	
	}
}

void Board::setNextBlock(int nextblock){

	this->nextblock = nextblock;

}

Board::~Board(){

	for(int i=0; i<height; i++) delete[] cells[i];
	delete[] cells;

	delete iblock;
	delete oblock;
	delete lblock;
	delete jblock;
	delete sblock;
	delete zblock;
	delete tblock;

}

bool Board::insertBlock(int curblock){

	total++;

	if(curblock == 1){
		Iblockcount++;
		return ((IBlock *)iblock)->insertBlock(t_x,t_y,cells);
	}
	if(curblock == 2){
		Oblockcount++;
		return ((OBlock *)oblock)->insertBlock(t_x,t_y,cells);
	}
	if(curblock == 3){
		Lblockcount++;
		return ((LBlock *)lblock)->insertBlock(t_x,t_y,cells);
	}	
	if(curblock == 4){
		Jblockcount++;
		return ((JBlock *)jblock)->insertBlock(t_x,t_y,cells);
	}
	if(curblock == 5){
		Sblockcount++;
		return ((SBlock *)sblock)->insertBlock(t_x,t_y,cells);
	}
	if(curblock == 6){
		Zblockcount++;
		return ((ZBlock *)zblock)->insertBlock(t_x,t_y,cells);
	}
	if(curblock == 7){
		Tblockcount++;
		return ((TBlock *)tblock)->insertBlock(t_x,t_y,cells);
	}

}

bool Board::moveBlockLeft(int curblock){

	if(curblock == 1){
		return ((IBlock *)iblock)->moveBlockLeft(t_x,t_y,cells);
	}	
	if(curblock == 2){
		return ((OBlock *)oblock)->moveBlockLeft(t_x,t_y,cells);
	}	
	if(curblock == 3){
		return ((LBlock *)lblock)->moveBlockLeft(t_x,t_y,cells);
	}
	if(curblock == 4){
		return ((JBlock *)jblock)->moveBlockLeft(t_x,t_y,cells);
	}
	if(curblock == 5){
		return ((SBlock *)sblock)->moveBlockLeft(t_x,t_y,cells);
	}
	if(curblock == 6){
		return ((ZBlock *)zblock)->moveBlockLeft(t_x,t_y,cells);
	}
	if(curblock == 7){
		return ((TBlock *)tblock)->moveBlockLeft(t_x,t_y,cells);
	}
}

bool Board::moveBlockRight(int curblock){

	if(curblock == 1){
		return ((IBlock *)iblock)->moveBlockRight(t_x,t_y,cells);
	}	
	if(curblock == 2){
		return ((OBlock *)oblock)->moveBlockRight(t_x,t_y,cells);
	}	
	if(curblock == 3){
		return ((LBlock *)lblock)->moveBlockRight(t_x,t_y,cells);
	}
	if(curblock == 4){
		return ((JBlock *)jblock)->moveBlockRight(t_x,t_y,cells);
	}
	if(curblock == 5){
		return ((SBlock *)sblock)->moveBlockRight(t_x,t_y,cells);
	}
	if(curblock == 6){
		return ((ZBlock *)zblock)->moveBlockRight(t_x,t_y,cells);
	}
	if(curblock == 7){
		return ((TBlock *)tblock)->moveBlockRight(t_x,t_y,cells);
	}
}

bool Board::moveBlockDown(int curblock){

	if(curblock == 1){
		return ((IBlock *)iblock)->moveBlockDown(t_x,t_y,cells);
	}	
	if(curblock == 2){
		return ((OBlock *)oblock)->moveBlockDown(t_x,t_y,cells);
	}	
	if(curblock == 3){
		return ((LBlock *)lblock)->moveBlockDown(t_x,t_y,cells);
	}
	if(curblock == 4){
		return ((JBlock *)jblock)->moveBlockDown(t_x,t_y,cells);
	}
	if(curblock == 5){
		return ((SBlock *)sblock)->moveBlockDown(t_x,t_y,cells);
	}
	if(curblock == 6){
		return ((ZBlock *)zblock)->moveBlockDown(t_x,t_y,cells);
	}
	if(curblock == 7){
		return ((TBlock *)tblock)->moveBlockDown(t_x,t_y,cells);
	}

}

void Board::dropBlock(int curblock){

	if(curblock == 1){
		return ((IBlock *)iblock)->dropBlock(t_x,t_y,cells);
	}	
	if(curblock == 2){
		return ((OBlock *)oblock)->dropBlock(t_x,t_y,cells);
	}	
	if(curblock == 3){
		return ((LBlock *)lblock)->dropBlock(t_x,t_y,cells);
	}
	if(curblock == 4){
		return ((JBlock *)jblock)->dropBlock(t_x,t_y,cells);
	}
	if(curblock == 5){
		return ((SBlock *)sblock)->dropBlock(t_x,t_y,cells);
	}
	if(curblock == 6){
		return ((ZBlock *)zblock)->dropBlock(t_x,t_y,cells);
	}
	if(curblock == 7){
		return ((TBlock *)tblock)->dropBlock(t_x,t_y,cells);
	}
}

void Board::eraseBlock(){

	bool erase = true;

	// 줄이 채워지는 경우
	int k = 19;
	while(k>0){
		erase = true;
		// 하나라도 VOID일 경우 지우지 않는다
		for(int j=0; j<width/2+1; j++){ // cells 0부터 9까지
			if(cells[k][j] == VOID){ erase = false; break;}
		}
		// 줄을 지우는 경우, 먼저 지우는 줄을 Void로 만들고
		if(erase){
			fulllines++;
			for(int l=0; l< width/2+1; l++) cells[k][l] = VOID;
			
			Cell *tmp = cells[k];

			int a = k;
			// 지우는 줄의 윗 줄을 하나씩 내려준다
			while(a>1){
				cells[a] = cells[a-1];
				a--;
			}

			cells[a] = tmp;

			k=20; // 하나씩 내려주니까 다시 처음부터 체크하기위해 20으로
		}
		k--;
	}
}

bool Board::rotateBlock(int curblock){

	if(curblock == 1){
		return ((IBlock *)iblock)->rotateBlock(t_x,t_y,cells);
	}
	if(curblock == 2){
		return ((OBlock *)oblock)->rotateBlock(t_x,t_y,cells);
	}
	if(curblock == 3){
		return ((LBlock *)lblock)->rotateBlock(t_x,t_y,cells);
	}	
	if(curblock == 4){
		return ((JBlock *)jblock)->rotateBlock(t_x,t_y,cells);
	}
	if(curblock == 5){
		return ((SBlock *)sblock)->rotateBlock(t_x,t_y,cells);
	}
	if(curblock == 6){
		return ((ZBlock *)zblock)->rotateBlock(t_x,t_y,cells);
	}
	if(curblock == 7){
		return ((TBlock *)tblock)->rotateBlock(t_x,t_y,cells);
	}

}
