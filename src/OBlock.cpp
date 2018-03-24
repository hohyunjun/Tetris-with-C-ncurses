#include "Block.h"
#include "Board.h"

        OBlock::OBlock() : Block(){}
        bool OBlock::insertBlock(int &t_x, int &t_y, Cell **cells){
                t_y = 2; t_x = 4; // 현재 왼쪽 아래
		rotate = 0;
                if(cells[t_y][t_x] == VOID){
                        cells[t_y-1][t_x] = O; // 왼쪽 위
                        cells[t_y-1][t_x+1] = O; // 오른쪽 위
                        cells[t_y][t_x+1] = O; // 오른쪽 아래
                        cells[t_y][t_x] = O; // 왼쪽 아래
                        return true;
                }
                else return false;
	}

        bool OBlock::moveBlockLeft(int &t_x, int &t_y, Cell **cells){
	        // 현재 위치는 2,4 왼쪽 아래
       		if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-1] == VOID){
               		 if(t_x>0){
            			cells[t_y][t_x-1] = O; // 왼쪽 아래
               		        cells[t_y-1][t_x-1] = O; // 왼쪽 위
                        	cells[t_y-1][t_x+1] = VOID; //
                        	cells[t_y][t_x+1] = VOID; //
                        	t_x = t_x-1; // 현재 tx ty는 왼쪽 아래
                        	return true;
                	}
                	else return true;
        	}
        	else return true;
	}
	
	bool OBlock::moveBlockRight(int &t_x, int &t_y, Cell **cells){

        	// 현재 위치는 2,4 왼쪽 아래
        	if(cells[t_y][t_x+2] == VOID && cells[t_y-1][t_x+2] == VOID){
                	if(t_x<width/2-1){
                        	cells[t_y-1][t_x+2] = O; // 오른쪽 위
                        	cells[t_y][t_x+2] = O; // 오른쪽 아래
                        	cells[t_y][t_x] = VOID; //
                        	cells[t_y-1][t_x] = VOID; //
                        	t_x = t_x+1; // 현재 tx ty는 왼쪽 아래
                        	return true;
                	}
                	else return true;
        	}
        	else return true;
	}

        bool OBlock::moveBlockDown(int &t_x, int &t_y, Cell **cells){
	
		// 현재 위치는 2,4 왼쪽 아래
       	 	if(t_y == height-1) return false;
        	if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x+1] == VOID){
                	if(t_y<height){
                        	cells[t_y-1][t_x] = VOID;
                        	cells[t_y-1][t_x+1] = VOID;
                        	cells[t_y+1][t_x] = O; //
                        	cells[t_y+1][t_x+1] = O; //
                        	t_y = t_y+1; // 현재 tx ty는 왼쪽 아래
                        	return true;
                	}
                	else return true;
        	}
        	else return false;

	}

        void OBlock::dropBlock(int &t_x, int &t_y, Cell **cells){
	
		bool notendofline = false;

        	// 원래 있던 값들 다 지운다
        	cells[t_y][t_x] = VOID; // 왼쪽 아래
        	cells[t_y][t_x+1] = VOID; // 오른쪽 아래
        	cells[t_y-1][t_x] = VOID; // 왼쪽 위
        	cells[t_y-1][t_x+1] = VOID; // 오른쪽 위

        	// 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        	while(cells[t_y][t_x] ==VOID && cells[t_y][t_x+1] == VOID){
                	t_y++;
                	if(t_y == height -1){
                        	break;
                	}
        	}

		if(cells[t_y][t_x] != VOID || cells[t_y][t_x+1] != VOID){
			notendofline = true;
		}

		if(notendofline && t_y == height-1){
                	        cells[t_y-2][t_x] = O;// 왼쪽위
                        	cells[t_y-2][t_x+1] = O;// 오른쪽 위
                        	cells[t_y-1][t_x] = O;// 왼쪽 아래
                        	cells[t_y-1][t_x+1] = O;// 오른쪽 아래
		}
        	else if(t_y==height-1){
                        	cells[t_y-1][t_x] = O;// 왼쪽위
                        	cells[t_y-1][t_x+1] = O;// 오른쪽 위
                        	cells[t_y][t_x] = O;// 왼쪽 아래
                        	cells[t_y][t_x+1] = O;// 오른쪽 아래
        	}
        	else{
                        	cells[t_y-2][t_x] = O;// 왼쪽위
                        	cells[t_y-2][t_x+1] = O;// 오른쪽 위
                        	cells[t_y-1][t_x] = O;// 왼쪽 아래
                        	cells[t_y-1][t_x+1] = O;// 오른쪽 아래
        	}



	}

	bool OBlock::rotateBlock(int &x, int &y, Cell **cells){

		rotate = (rotate++)%4;

		return true;

	}




