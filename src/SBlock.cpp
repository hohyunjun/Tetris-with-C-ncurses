#include "Block.h"
#include "Board.h"

SBlock::SBlock() : Block(){}

bool SBlock::insertBlock(int &t_x, int &t_y, Cell **cells){

           t_y = 3; t_x = 5; // 현재 맨 아래 오른쪽
 	   rotate = 0;

           if(cells[t_y][t_x] == VOID){
                   cells[t_y][t_x] = S; // 한칸 위
                   cells[t_y-1][t_x] = S; // 두칸 위
                   cells[t_y-1][t_x-1] = S; // 세칸 위
                   cells[t_y-2][t_x-1] = S; // 네칸 위
                   return true;
           }
           else return false;

}

bool SBlock::moveBlockLeft(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0 || rotate == 2){	      
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-2] == VOID){
		if(cells[t_y-2][t_x-2] == VOID){
			if(t_x>1){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y-1][t_x-1] = VOID;
				cells[t_y-2][t_x-1] = VOID;
            			cells[t_y][t_x-1] = S; // 왼쪽으로 이동
               			cells[t_y-1][t_x-2] = S; 
                     		cells[t_y-2][t_x-2] = S; 
                        	cells[t_y-1][t_x-1] = S; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 1 || rotate == 3){
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y][t_x-2] == VOID && cells[t_y-1][t_x-1] == VOID){
			if(t_x>1){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x-1] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-1][t_x+1] = VOID;

				cells[t_y][t_x-1] = S; // 원래 있던값들 지워준다
				cells[t_y][t_x-2] = S;
				cells[t_y-1][t_x-1] = S;
				cells[t_y-1][t_x] = S;
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
        }
        else return true;
	}
}
	
bool SBlock::moveBlockRight(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0 || rotate == 2){
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+1] == VOID){
		if(cells[t_y-2][t_x] == VOID){
			if(t_x<width/2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y-1][t_x-1] = VOID;
				cells[t_y-2][t_x-1] = VOID;

            			cells[t_y][t_x+1] = S; // 오른쪽으로 이동
               			cells[t_y-1][t_x+1] = S; 
                     		cells[t_y-2][t_x] = S; 
                        	cells[t_y-1][t_x] = S; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}
	if(rotate == 1 || rotate == 3){
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y-1][t_x+2] == VOID && cells[t_y][t_x+1] == VOID){
			if(t_x<width/2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y][t_x-1] = VOID;
				cells[t_y-1][t_x+1] = VOID;

				cells[t_y][t_x+1] = S; // 원래 있던값들 지워준다
				cells[t_y-1][t_x+1] = S;
				cells[t_y][t_x] = S;
				cells[t_y-1][t_x+2] = S;
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
        }
        else return true;


	}

}

bool SBlock::moveBlockDown(int &t_x, int &t_y, Cell **cells){
	
	if(rotate == 0 || rotate == 2){
	// 현재 위치는 맨 아래 오른쪽
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID){
                if(t_y<height){
			cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
			cells[t_y-1][t_x] = VOID;
			cells[t_y-1][t_x-1] = VOID;
			cells[t_y-2][t_x-1] = VOID;

                        cells[t_y+1][t_x] = S;
                        cells[t_y][t_x] = S;
                        cells[t_y][t_x-1] = S; //
                        cells[t_y-1][t_x-1] = S; //
                        t_y = t_y+1; // 현재 tx ty는 맨 아래
                        return true;
                }
                else return true;
        }
        else return false;
	}
	
	if(rotate == 1 || rotate == 3){
	// 현재 위치는 맨 아래 오른쪽
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x-1] == VOID){
		if(cells[t_y][t_x+1] == VOID){
                if(t_y<height){
			cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
			cells[t_y][t_x-1] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-1][t_x+1] = VOID;

			cells[t_y+1][t_x] = S; // 원래 있던값들 지워준다
			cells[t_y+1][t_x-1] = S;
			cells[t_y][t_x] = S;
			cells[t_y][t_x+1] = S;
                        t_y = t_y+1; // 현재 tx ty는 맨 아래
                        return true;
                }
                else return true;
		}
		else return false;
        }
        else return false;
	}

}

void SBlock::dropBlock(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0 || rotate == 2){
	bool notendofline = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-1][t_x-1] = VOID; 
        cells[t_y-2][t_x-1] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y-1][t_x-1] == VOID){ // VOID일 경우
                t_y++;
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y-1][t_x-1] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = S;
                        cells[t_y-2][t_x] = S;
                        cells[t_y-2][t_x-1] = S;
                        cells[t_y-3][t_x-1] = S;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = S;
                        cells[t_y-1][t_x] = S;
                        cells[t_y-1][t_x-1] = S;
                        cells[t_y-2][t_x-1] = S;
        }
        else{
                        cells[t_y-1][t_x] = S;
                        cells[t_y-2][t_x] = S;
                        cells[t_y-2][t_x-1] = S;
                        cells[t_y-3][t_x-1] = S;
        }
	}

	if(rotate == 1 || rotate == 3){
	bool notendofline = false;
	bool onlytwo = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x-1] = VOID; 
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-1][t_x+1] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y][t_x-1] == VOID){ // VOID일 경우
		if(cells[t_y-1][t_x+1] == VOID)
                	t_y++;
		else{
			onlytwo = true; break;
		}
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y][t_x-1] != VOID) notendofline = true;
	if(cells[t_y-1][t_x+1] != VOID) notendofline = true;

	if(onlytwo){

                        cells[t_y-1][t_x] = S;
                        cells[t_y-1][t_x-1] = S;
                        cells[t_y-2][t_x] = S;
                        cells[t_y-2][t_x+1] = S;
	}
	if(t_y == height-1 && notendofline){

                        cells[t_y-1][t_x] = S;
                        cells[t_y-1][t_x-1] = S;
                        cells[t_y-2][t_x] = S;
                        cells[t_y-2][t_x+1] = S;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = S;
                        cells[t_y][t_x-1] = S;
                        cells[t_y-1][t_x] = S;
                        cells[t_y-1][t_x+1] = S;
        }
        else{
                        cells[t_y-1][t_x] = S;
                        cells[t_y-1][t_x-1] = S;
                        cells[t_y-2][t_x] = S;
                        cells[t_y-2][t_x+1] = S;
        }



	}

}

bool SBlock::rotateBlock(int &t_x, int &t_y, Cell **cells){

	rotate = (++rotate) % 4;
	
	// 현재 좌표 맨 아래 오른쪽

	if(rotate == 1 || rotate == 3){
		
		cells[t_y][t_x] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-1][t_x-1] = VOID;
		cells[t_y-2][t_x-1] = VOID;

		//기본 좌표값 변경 : 오른쪽 아래
		t_y = t_y-1;
		t_x = t_x-1;

		cells[t_y][t_x] = S;
		cells[t_y][t_x-1] = S;
		cells[t_y-1][t_x] = S;
		cells[t_y-1][t_x+1] = S;

	}
	else if(rotate == 0 || rotate == 2){

		cells[t_y][t_x] = VOID;
		cells[t_y][t_x-1] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-1][t_x+1] = VOID;

		//현재 좌표값 변경 : 아래 오른쪽
		t_x = t_x+1;
		t_y = t_y+1;

		cells[t_y][t_x] = S;
		cells[t_y-1][t_x] = S;
		cells[t_y-1][t_x-1] = S;
		cells[t_y-2][t_x-1] = S;

	}

	return true;


}
