#include "Block.h"
#include "Board.h"

LBlock::LBlock() : Block(){}

bool LBlock::insertBlock(int &t_x, int &t_y, Cell **cells){

           t_y = 3; t_x = 4; // 현재 왼쪽 아래
	   rotate = 0;
	
           if(cells[t_y][t_x] == VOID && cells[t_y][t_x+1]==VOID){
                   cells[t_y][t_x] = L; 
                   cells[t_y][t_x+1] = L; // 오른쪽 한칸
                   cells[t_y-1][t_x] = L; // 위로 한칸
                   cells[t_y-2][t_x] = L; // 아래로 한칸
                   return true;
           }
           else return false;

}

bool LBlock::moveBlockLeft(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0){	      
	// 현재 위치는 맨 아래 왼쪽
        if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-1] == VOID){
		if(cells[t_y-2][t_x-1] == VOID){
			if(t_x>0){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x+1] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;
            			cells[t_y][t_x-1] = L; // 왼쪽으로 이동
               			cells[t_y][t_x] = L; 
                     		cells[t_y-1][t_x-1] = L; 
                        	cells[t_y-2][t_x-1] = L; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 1){ // 1회 회전 시	      
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y][t_x-3] == VOID && cells[t_y-1][t_x-1] == VOID){
			if(t_x>2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y-1][t_x] = VOID;
				cells[t_y][t_x-1] = VOID;
				cells[t_y][t_x-2] = VOID;

            			cells[t_y][t_x-3] = L; // 왼쪽으로 이동
               			cells[t_y][t_x-2] = L; 
                     		cells[t_y][t_x-1] = L; 
                        	cells[t_y-1][t_x-1] = L; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
        }
        else return true;
	}

	if(rotate == 2){	      
	// 현재 위치는 맨 위 오른쪽
        if(cells[t_y][t_x-2] == VOID && cells[t_y+1][t_x-1] == VOID){
		if(cells[t_y+2][t_x-1] == VOID){
			if(t_x>1){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x-1] = VOID;
				cells[t_y+1][t_x] = VOID;
				cells[t_y+2][t_x] = VOID;

            			cells[t_y][t_x-2] = L; // 왼쪽으로 이동
               			cells[t_y][t_x-1] = L; 
                     		cells[t_y+1][t_x-1] = L; 
                        	cells[t_y+2][t_x-1] = L; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 3){	      
	// 현재 위치는 맨 위 왼쪽
        if(cells[t_y][t_x-1] == VOID && cells[t_y+1][t_x-1] == VOID){
			if(t_x>0){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x+1] = VOID;
				cells[t_y][t_x+2] = VOID;
				cells[t_y+1][t_x] = VOID;

            			cells[t_y][t_x-1] = L; // 왼쪽으로 이동
               			cells[t_y+1][t_x-1] = L; 
                     		cells[t_y][t_x] = L; 
                        	cells[t_y][t_x+1] = L; 
				t_x = t_x-1;
                        	return true;
                	}
                	else return true;
        }
        else return true;
	}
}
	
bool LBlock::moveBlockRight(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0){
	// 현재 위치는 맨 아래 왼쪽
        if(cells[t_y][t_x+2] == VOID && cells[t_y-1][t_x+1] == VOID){
		if(cells[t_y-2][t_x+1] == VOID){
			if(t_x<width/2-1){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x+1] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;

            			cells[t_y][t_x+1] = L; // 오른쪽으로 이동
               			cells[t_y][t_x+2] = L; 
                     		cells[t_y-1][t_x+1] = L; 
                        	cells[t_y-2][t_x+1] = L; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 1){
	// 현재 위치는 맨 아래 오른쪽
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+1] == VOID){
			if(t_x<width/2){
				cells[t_y][t_x-2] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x-1] = VOID;
				cells[t_y][t_x] = VOID;
				cells[t_y-1][t_x] = VOID;

            			cells[t_y-1][t_x+1] = L; // 오른쪽으로 이동
               			cells[t_y][t_x+1] = L; 
                     		cells[t_y][t_x] = L; 
                        	cells[t_y][t_x-1] = L; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
        }
        else return true;
	}

	if(rotate == 2){
	// 현재 위치는 맨 위 오른쪽
        if(cells[t_y][t_x+1] == VOID && cells[t_y+1][t_x+1] == VOID){
		if(cells[t_y+2][t_x+1] == VOID){
			if(t_x<width/2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y+1][t_x] = VOID;
				cells[t_y+2][t_x] = VOID;
				cells[t_y][t_x-1] = VOID;

            			cells[t_y][t_x+1] = L; // 오른쪽으로 이동
               			cells[t_y+1][t_x+1] = L; 
                     		cells[t_y+2][t_x+1] = L; 
                        	cells[t_y][t_x] = L; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 3){
	// 현재 위치는 맨 위 왼쪽
        if(cells[t_y][t_x+3] == VOID && cells[t_y+1][t_x+1] == VOID){
			if(t_x<width/2-2){
				cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x+1] = VOID;
				cells[t_y][t_x+2] = VOID;
				cells[t_y+1][t_x] = VOID;

            			cells[t_y][t_x+1] = L; // 오른쪽으로 이동
               			cells[t_y+1][t_x+1] = L; 
                     		cells[t_y][t_x+2] = L; 
                        	cells[t_y][t_x+3] = L; 
				t_x = t_x+1;
                        	return true;
                	}
                	else return true;
        }
        else return true;
	}
}

bool LBlock::moveBlockDown(int &t_x, int &t_y, Cell **cells){

	if(rotate == 0){	
	// 현재 위치는 맨 아래 왼쪽
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x+1] == VOID){
                if(t_y<height){
			cells[t_y+1][t_x] = L;
                        cells[t_y+1][t_x+1] = L;
                        cells[t_y][t_x+1] = VOID;
                        cells[t_y-2][t_x] = VOID; //
                        t_y = t_y+1; // 현재 tx ty는 맨 아래
                        return true;
                }
                else return true;
        }
        else return false;
	}

	if(rotate == 1){	
	// 현재 위치는 맨 아래 오른쪽
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x-1] == VOID){
		if(cells[t_y+1][t_x-2] == VOID){
                	if(t_y<height){	
                        	cells[t_y][t_x-1] = VOID;
                        	cells[t_y][t_x-2] = VOID;
                        	cells[t_y][t_x] = VOID;
                        	cells[t_y-1][t_x] = VOID;

				cells[t_y+1][t_x-1] = L;
                        	cells[t_y+1][t_x-2] = L;
                        	cells[t_y+1][t_x] = L;
                        	cells[t_y][t_x] = L; //
                        	t_y = t_y+1; // 현재 tx ty는 맨 아래
                        	return true;
                	}
       	        	else return true;
		}
		else return false;
        }
        else return false;
	}

	if(rotate == 2){	
	// 현재 위치는 맨 위 오른쪽
        if(t_y == height-3) return false;
        if(cells[t_y+3][t_x] == VOID && cells[t_y+1][t_x-1] == VOID){
                if(t_y<height+2){
                        cells[t_y][t_x] = VOID;
                        cells[t_y][t_x-1] = VOID;
                        cells[t_y+1][t_x] = VOID;
                        cells[t_y+2][t_x] = VOID;

			cells[t_y+3][t_x] = L;
                        cells[t_y+2][t_x] = L;
                        cells[t_y+1][t_x] = L;
                        cells[t_y+1][t_x-1] = L; //
                        t_y = t_y+1; // 현재 tx ty는 맨 아래
                        return true;
                }
                else return true;
        }
        else return false;
	}

	if(rotate == 3){	
	// 현재 위치는 맨 위 왼쪽
        if(t_y == height-2) return false;
        if(cells[t_y+2][t_x] == VOID && cells[t_y+1][t_x+1] == VOID){
		if(cells[t_y+1][t_x+2] == VOID){
                	if(t_y<height+1){

                        	cells[t_y][t_x] = VOID;
                        	cells[t_y][t_x+1] = VOID;
                        	cells[t_y][t_x+2] = VOID;
                        	cells[t_y+1][t_x] = VOID;

				cells[t_y+1][t_x] = L;
                        	cells[t_y+1][t_x+1] = L;
                        	cells[t_y+1][t_x+2] = L;
                        	cells[t_y+2][t_x] = L; //
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

void LBlock::dropBlock(int &t_x, int &t_y, Cell **cells){


	if(rotate == 0){
	bool notendofline = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x+1] = VOID; 
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-2][t_x] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y][t_x+1] == VOID){ // VOID일 경우
                t_y++;
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y][t_x+1] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x+1] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-3][t_x] = L;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = L;
                        cells[t_y][t_x+1] = L;
                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
        }
        else{
                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x+1] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-3][t_x] = L;
        }
	}

	if(rotate == 1){
	bool notendofline = false;
	bool onlytwo = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x-1] = VOID; 
        cells[t_y][t_x-2] = VOID; 
        cells[t_y-1][t_x] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y][t_x-1] == VOID){ // VOID일 경우
		if(cells[t_y][t_x-2] == VOID)
                	t_y++;
		else{
			onlytwo = true;
			break;
		}
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y][t_x-1] != VOID) notendofline = true;
	if(cells[t_y][t_x-2] != VOID) notendofline = true;

	if(onlytwo){

                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x-1] = L;
                        cells[t_y-1][t_x-2] = L;
                        cells[t_y-2][t_x] = L;
	}
	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x-1] = L;
                        cells[t_y-1][t_x-2] = L;
                        cells[t_y-2][t_x] = L;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = L;
                        cells[t_y][t_x-1] = L;
                        cells[t_y][t_x-2] = L;
                        cells[t_y-1][t_x] = L;
        }
        else{
                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x-1] = L;
                        cells[t_y-1][t_x-2] = L;
                        cells[t_y-2][t_x] = L;
        }
	}

	if(rotate == 2){
	bool notendofline = false;

        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x-1] = VOID; 
        cells[t_y+1][t_x] = VOID; 
        cells[t_y+2][t_x] = VOID; 

	// 기준값을 맨 아래값으로 바꿔준다
	t_y = t_y+2;

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y-2][t_x-1] == VOID){ // VOID일 경우
                t_y++;
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y-2][t_x-1] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-3][t_x] = L;
                        cells[t_y-3][t_x-1] = L;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = L;
                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-2][t_x-1] = L;
        }
        else{
                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-3][t_x] = L;
                        cells[t_y-3][t_x-1] = L;
        }
	}

	if(rotate == 3){
	bool notendofline = false;
	bool onlytwo = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y+1][t_x] = VOID; 
        cells[t_y][t_x+1] = VOID; 
        cells[t_y][t_x+2] = VOID; 

	// 기준값을 맨 아래값으로 바꾼다
	t_y = t_y + 1;

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다
        while(cells[t_y][t_x] == VOID && cells[t_y-1][t_x+1] == VOID){ // VOID일 경우
		if(cells[t_y-1][t_x+2] == VOID)
                	t_y++;
		else{
			onlytwo = true; break;
		}
                if(t_y == height -1){
                        break;
                }
        }

	if(cells[t_y][t_x] != VOID || cells[t_y-1][t_x+1] != VOID) notendofline = true;
	if(cells[t_y-1][t_x+2] != VOID) notendofline = true;

	if(onlytwo){
                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-2][t_x+1] = L;
                        cells[t_y-2][t_x+2] = L;
	}
	if(t_y == height-1 && notendofline){

                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-2][t_x+1] = L;
                        cells[t_y-2][t_x+2] = L;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = L;
                        cells[t_y-1][t_x] = L;
                        cells[t_y-1][t_x+1] = L;
                        cells[t_y-1][t_x+2] = L;
        }
        else{

                        cells[t_y-1][t_x] = L;
                        cells[t_y-2][t_x] = L;
                        cells[t_y-2][t_x+1] = L;
                        cells[t_y-2][t_x+2] = L;
        }
	}

}

bool LBlock::rotateBlock(int &t_x, int &t_y, Cell **cells){

	rotate = (++rotate) % 4;

	if(rotate == 1){ // 한번 회전 시 기준값은 아랫줄 제일 오른쪽으로
		cells[t_y][t_x] = VOID;		
		cells[t_y][t_x+1] = VOID;		
		cells[t_y-1][t_x] = VOID;		
		cells[t_y-2][t_x] = VOID;		

		// 기준값 이동
		t_y = t_y - 1;
		t_x = t_x + 1;

		cells[t_y][t_x] = L;		
		cells[t_y][t_x-1] = L;		
		cells[t_y][t_x-2] = L;		
		cells[t_y-1][t_x] = L;		
	}
	if(rotate == 2){ // 두번 회전 시 기준값은 맨윗줄 오른쪽
		
		cells[t_y][t_x] = VOID;	
		cells[t_y-1][t_x] = VOID;		
		cells[t_y][t_x-1] = VOID;		
		cells[t_y][t_x-2] = VOID;		
		
		// 기준값 이동
		t_x = t_x - 1;
		t_y = t_y - 1;
		
		cells[t_y][t_x-1] = L;		
		cells[t_y][t_x] = L;		
		cells[t_y+1][t_x] = L;		
		cells[t_y+2][t_x] = L;		
	}
	if(rotate == 3){ // 세번 회전 시 기준값은 맨윗줄 왼쪽

		cells[t_y][t_x-1] = VOID;		
		cells[t_y][t_x] = VOID;		
		cells[t_y+1][t_x] = VOID;		
		cells[t_y+2][t_x] = VOID;		
		
		//기준값 이동
		t_x = t_x - 1;
		t_y = t_y + 1;

		cells[t_y][t_x] = L;		
		cells[t_y][t_x+1] = L;		
		cells[t_y][t_x+2] = L;		
		cells[t_y+1][t_x] = L;		
	}
	if(rotate == 0){ // 다시 원래대로
	
		cells[t_y][t_x] = VOID;		
		cells[t_y][t_x+1] = VOID;		
		cells[t_y][t_x+2] = VOID;		
		cells[t_y+1][t_x] = VOID;		
		
		//기준값 이동
		t_x = t_x + 1;
		t_y = t_y + 1;

		cells[t_y][t_x] = L;		
		cells[t_y-1][t_x] = L;		
		cells[t_y-2][t_x] = L;		
		cells[t_y][t_x+1] = L;		

	}

	return true;
}
