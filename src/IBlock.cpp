#include "Block.h"
#include "Board.h"

IBlock::IBlock() : Block(){}

bool IBlock::insertBlock(int &t_x, int &t_y, Cell **cells){

           t_y = 4; t_x = 4; // 현재 맨 아래
	   rotate = 0;

           if(cells[t_y][t_x] == VOID){
                   cells[t_y][t_x] = I; // 한칸 위
                   cells[t_y-1][t_x] = I; // 두칸 위
                   cells[t_y-2][t_x] = I; // 세칸 위
                   cells[t_y-3][t_x] = I; // 네칸 위
                   return true;
           }
           else return false;

}

bool IBlock::moveBlockLeft(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1 || rotate == 3){ // 회전 후 가로형태일경우
	// 회전 후 최초좌표는 블록의 제일 왼쪽	
        if(cells[t_y][t_x-1] == VOID){
		if(t_x>0){
			cells[t_y][t_x-1] = I;
			cells[t_y][t_x+3] = VOID;
			t_x = t_x-1;
                        return true;
               	}
                else return true;
        }
        else return true;
	}

	else if(rotate == 0 || rotate == 2){ // 기본 세로형태일 경우	      
	// 현재 위치는 맨 아래
        if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-1] == VOID){
		if(cells[t_y-2][t_x-1] == VOID && cells[t_y-3][t_x-1] == VOID){
			if(t_x>0){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;
				cells[t_y-3][t_x] = VOID;
            			cells[t_y][t_x-1] = I; // 왼쪽으로 이동
               			cells[t_y-1][t_x-1] = I; 
                     		cells[t_y-2][t_x-1] = I; 
                        	cells[t_y-3][t_x-1] = I; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

}
	
bool IBlock::moveBlockRight(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1 || rotate == 3){ // 회전 후 가로형태일경우
	// 회전 후 최초좌표는 블록의 제일 왼쪽	
        if(cells[t_y][t_x+4] == VOID){
		if(t_x<width/2-3){
			cells[t_y][t_x+4] = I;
			cells[t_y][t_x] = VOID;
			t_x = t_x+1;
                        return true;
               	}
                else return true;
        }
        else return true;
	}

	else if(rotate == 0 || rotate == 2){
	// 현재 위치는 맨 아래
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+1] == VOID){
		if(cells[t_y-2][t_x+1] == VOID && cells[t_y-3][t_x+1] == VOID){
			if(t_x<width/2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;
				cells[t_y-3][t_x] = VOID;
            			cells[t_y][t_x+1] = I; // 오른쪽으로 이동
               			cells[t_y-1][t_x+1] = I; 
                     		cells[t_y-2][t_x+1] = I; 
                        	cells[t_y-3][t_x+1] = I; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

}

bool IBlock::moveBlockDown(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1 || rotate == 3){ // 회전 후 가로형태일경우
        if(t_y == height-1) return false;
	// 회전 후 최초좌표는 블록의 제일 왼쪽	
        if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x+1] == VOID){
		if(cells[t_y+1][t_x+2] == VOID && cells[t_y+1][t_x+3] == VOID){
			if(t_y<height){
				cells[t_y][t_x] = VOID;
				cells[t_y][t_x+1] = VOID;
				cells[t_y][t_x+2] = VOID;
				cells[t_y][t_x+3] = VOID;

				cells[t_y+1][t_x] = I;
				cells[t_y+1][t_x+1] = I;
				cells[t_y+1][t_x+2] = I;
				cells[t_y+1][t_x+3] = I;

				t_y = t_y+1;
                        	return true;
               		}
                	else return true;
		}
		else return false;
        }
        else return false;
	}

	if(rotate == 0 || rotate == 2){	
	// 현재 위치는 맨 아래
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID){
                if(t_y<height){
			cells[t_y-3][t_x] = VOID;
                        cells[t_y+1][t_x] = I;
                        cells[t_y][t_x] = I;
                        cells[t_y-1][t_x] = I; //
                        cells[t_y-2][t_x] = I; //
                        t_y = t_y+1; // 현재 tx ty는 맨 아래
                        return true;
                }
                else return true;
        }
        else return false;
	}
}

void IBlock::dropBlock(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1 || rotate == 3){
	bool onlytwo = false;
	bool notendofline = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x+1] = VOID; 
        cells[t_y][t_x+2] = VOID; 
        cells[t_y][t_x+3] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y][t_x+1] == VOID){ // VOID일 경우
		if(cells[t_y][t_x+2] == VOID && cells[t_y][t_x+3] == VOID)
                	t_y++;
		else{ onlytwo = true; break;}
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y][t_x+1] != VOID) notendofline = true;
	if(cells[t_y][t_x+2] != VOID || cells[t_y][t_x+3] != VOID) notendofline = true;

	if(onlytwo){
                        cells[t_y-1][t_x] = I;
                        cells[t_y-1][t_x+1] = I;
                        cells[t_y-1][t_x+2] = I;
                        cells[t_y-1][t_x+3] = I;
	}
	else if(t_y == height-1 && notendofline){

                        cells[t_y-1][t_x] = I;
                        cells[t_y-1][t_x+1] = I;
                        cells[t_y-1][t_x+2] = I;
                        cells[t_y-1][t_x+3] = I;


	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = I;
                        cells[t_y][t_x+1] = I;
                        cells[t_y][t_x+2] = I;
                        cells[t_y][t_x+3] = I;
        }
        else{
                        cells[t_y-1][t_x] = I;
                        cells[t_y-1][t_x+1] = I;
                        cells[t_y-1][t_x+2] = I;
                        cells[t_y-1][t_x+3] = I;
        }
	}

	else if(rotate == 0 || rotate == 2){
	bool notendofline = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-2][t_x] = VOID; 
        cells[t_y-3][t_x] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID){ // VOID일 경우
                t_y++;
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = I;
                        cells[t_y-2][t_x] = I;
                        cells[t_y-3][t_x] = I;
                        cells[t_y-4][t_x] = I;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = I;
                        cells[t_y-1][t_x] = I;
                        cells[t_y-2][t_x] = I;
                        cells[t_y-3][t_x] = I;
        }
        else{
                        cells[t_y-1][t_x] = I;
                        cells[t_y-2][t_x] = I;
                        cells[t_y-3][t_x] = I;
                        cells[t_y-4][t_x] = I;
        }
	}
	

}

bool IBlock::rotateBlock(int &t_x, int &t_y, Cell **cells){


	rotate = (++rotate) % 4;
	
	// 현재 I블록의 좌표는 맨 아래

	if(rotate == 1 || rotate == 3){

		/*	
		// x,y 좌표가 board크기를 넘어가는 경우
		if(t_x-1 < 0){rotate--; return true;}
		if(t_y-2 < 0){rotate--; return true;}
		if(t_x+1 > width/2){rotate--; return true;}
		if(t_x+2 > width/2){rotate--; return true;}
		if(t_x+3 > width/2){rotate--; return true;}
		
		// 움직일 좌표값이 void가 아닐경우
		if(cells[t_y+2][t_x+1] != VOID){rotate--; return true;}	
		if(cells[t_y+2][t_x+2] != VOID){rotate--; return true;}		
		if(cells[t_y+2][t_x+3] != VOID){rotate--; return true;}	
		if(cells[t_y+2][t_x+4] != VOID){rotate--; return true;}	
*/
		// 원래 있던 값들 다 지워주고
		cells[t_y][t_x] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-2][t_x] = VOID;
		cells[t_y-3][t_x] = VOID;

		// 좌표 가로블록 맨 왼쪽으로 이동
		t_y = t_y-2;
		t_x = t_x-1;


		if(t_x < 0){ // 회전했을 때 보드 길이를 넘어가는 경우 예외처리
			cells[t_y][t_x+1] = I;		
			cells[t_y][t_x+2] = I;		
			cells[t_y][t_x+3] = I;		
			cells[t_y][t_x+4] = I;
			
			t_x = t_x+1;
		}
		else if(t_x+2 > width/2){
			cells[t_y][t_x-2] = I;		
			cells[t_y][t_x-1] = I;		
			cells[t_y][t_x] = I;		
			cells[t_y][t_x+1] = I;
	
			t_x = t_x-2;
		}
		else if(t_x+3 > width/2){
			cells[t_y][t_x-1] = I;		
			cells[t_y][t_x] = I;		
			cells[t_y][t_x+1] = I;		
			cells[t_y][t_x+2] = I;
	
			t_x = t_x-1;
		}
		else{
			cells[t_y][t_x] = I;		
			cells[t_y][t_x+1] = I;		
			cells[t_y][t_x+2] = I;		
			cells[t_y][t_x+3] = I;
		}
	
	}
	else{
/*
		if(t_y+2>height){rotate--; return true;}
		
		if(cells[t_y-1][t_x+1] != VOID){rotate--; return true;}
		if(cells[t_y][t_x+1] != VOID){rotate--; return true;}
		if(cells[t_y+1][t_x+1] != VOID){rotate--; return true;}
		if(cells[t_y+2][t_x+1] != VOID){rotate--; return true;}
*/
		cells[t_y][t_x] = VOID;		
		cells[t_y][t_x+1] = VOID;		
		cells[t_y][t_x+2] = VOID;		
		cells[t_y][t_x+3] = VOID;		

		cells[t_y-1][t_x+1] = I;
		cells[t_y][t_x+1] = I;
		cells[t_y+1][t_x+1] = I;
		cells[t_y+2][t_x+1] = I;

		// 좌표 세로블록 맨 아래로 이동
		t_y = t_y+2;
		t_x = t_x+1;
	}
	return true;
}

