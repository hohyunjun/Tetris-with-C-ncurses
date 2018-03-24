#include "Block.h"
#include "Board.h"

TBlock::TBlock() : Block(){}

bool TBlock::insertBlock(int &t_x, int &t_y, Cell **cells){

           t_y = 2; t_x = 5; // 현재 아래 중간
	   rotate = 0;

           if(cells[t_y][t_x] == VOID && cells[t_y][t_x+1]==VOID){
		if(cells[t_y][t_x-1] == VOID){
                 	 cells[t_y][t_x] = T; 
                	 cells[t_y-1][t_x] = T; // 오른쪽 한칸
              	    	 cells[t_y][t_x-1] = T; // 위로 한칸
                  	 cells[t_y][t_x+1] = T; // 아래로 한칸
                	 return true;
		}
		else return false;
           }
           else return false;

}

bool TBlock::moveBlockLeft(int &t_x, int &t_y, Cell **cells){
	 
	if(rotate == 1){
	// 현재 위치는 오른쪽 맨 아래
        if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-2] == VOID){
		if(cells[t_y-2][t_x-1] == VOID){
		if(t_x>1){
			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-2][t_x] = VOID;
			cells[t_y-1][t_x-1] = VOID;

			cells[t_y][t_x-1] = T;
			cells[t_y-1][t_x-1] = T;
			cells[t_y-2][t_x-1] = T;
			cells[t_y-1][t_x-2] = T;
			t_x = t_x-1;
                        return true;
               	}
                else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 2){
	// 현재 위치는 맨 아래 중간
        if(cells[t_y-1][t_x-2] == VOID && cells[t_y][t_x-1] == VOID){
		if(t_x>1){
			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-1][t_x-1] = VOID;
			cells[t_y-1][t_x+1] = VOID;

			cells[t_y][t_x-1] = T;
			cells[t_y-1][t_x-1] = T;
			cells[t_y-1][t_x-2] = T;
			cells[t_y-1][t_x] = T;

			t_x = t_x-1;
                        return true;
               	}
                else return true;
        }
        else return true;
	}
	if(rotate == 3){
	// 현재 위치는 오른쪽 맨 아래
        if(cells[t_y][t_x-1] == VOID && cells[t_y-1][t_x-1] == VOID){
		if(cells[t_y-2][t_x-1] == VOID){
		if(t_x>0){

			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-2][t_x] = VOID;
			cells[t_y-1][t_x+1] = VOID;

			cells[t_y][t_x-1] = T;
			cells[t_y-1][t_x-1] = T;
			cells[t_y-2][t_x-1] = T;
			cells[t_y-1][t_x] = T;
			t_x = t_x-1;
                        return true;
               	}
                else return true;
		}
		else return true;
        }
        else return true;
	}

	if(rotate == 0){ 
	// 현재 위치는 맨 아래 중간
        if(cells[t_y][t_x-2] == VOID && cells[t_y-1][t_x-1] == VOID){
		if(t_x>1){
			cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
			cells[t_y][t_x-1] = VOID;
			cells[t_y][t_x+1] = VOID;
			cells[t_y-1][t_x] = VOID;

        		cells[t_y][t_x-1] = T; // 왼쪽으로 이동
              		cells[t_y][t_x-2] = T; 
                     	cells[t_y][t_x] = T; 
                        cells[t_y-1][t_x-1] = T; 
			t_x = t_x-1;
                        return true;
               	}
                else return true;
        }
        else return true;
	}

}
	
bool TBlock::moveBlockRight(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1){
	// 현재 위치는 오른쪽 맨 아래
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+1] == VOID){
		if(cells[t_y-2][t_x+1] == VOID){
		if(t_x<width/2){
			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-2][t_x] = VOID;
			cells[t_y-1][t_x-1] = VOID;

			cells[t_y][t_x+1] = T;
			cells[t_y-1][t_x+1] = T;
			cells[t_y-2][t_x+1] = T;
			cells[t_y-1][t_x] = T;
			t_x = t_x+1;
                        return true;
               	}
                else return true;
		}
		else return true;
        }
        else return true;
	}
	if(rotate == 2){
	// 현재 위치는 맨 아래 중간
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+2] == VOID){
		if(t_x<width/2){
			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-1][t_x-1] = VOID;
			cells[t_y-1][t_x+1] = VOID;

			cells[t_y][t_x+1] = T;
			cells[t_y-1][t_x+1] = T;
			cells[t_y-1][t_x] = T;
			cells[t_y-1][t_x+2] = T;

			t_x = t_x+1;
                        return true;
               	}
                else return true;
        }
        else return true;
	}

	if(rotate == 3){
	// 현재 위치는 오른쪽 맨 아래
        if(cells[t_y][t_x+1] == VOID && cells[t_y-1][t_x+2] == VOID){
		if(cells[t_y-2][t_x+1] == VOID){
		if(t_x<width/2){

			cells[t_y][t_x] = VOID;
			cells[t_y-1][t_x] = VOID;
			cells[t_y-2][t_x] = VOID;
			cells[t_y-1][t_x+1] = VOID;

			cells[t_y][t_x+1] = T;
			cells[t_y-1][t_x+1] = T;
			cells[t_y-2][t_x+1] = T;
			cells[t_y-1][t_x+2] = T;
			t_x = t_x+1;
                        return true;
               	}
                else return true;
		}
		else return true;
        }
        else return true;
	}
	if(rotate == 0){
	// 현재 위치는 맨 아래 중간
        if(cells[t_y][t_x+2] == VOID && cells[t_y-1][t_x+1] == VOID){
		if(t_x<width/2){
			cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
			cells[t_y][t_x-1] = VOID;
			cells[t_y][t_x+1] = VOID;
			cells[t_y-1][t_x] = VOID;

           		cells[t_y][t_x+1] = T; // 오른쪽으로 이동
             		cells[t_y][t_x] = T; 
                     	cells[t_y][t_x+2] = T; 
                        cells[t_y-1][t_x+1] = T; 
			t_x = t_x+1;
                        return true;
                }
               	else return true;
        }
        else return true;
	}

}

bool TBlock::moveBlockDown(int &t_x, int &t_y, Cell **cells){
	
	if(rotate == 1){
	// 현재 위치는 맨 아래 중간
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y][t_x-1] == VOID){
      	        	if(t_y<height){
				cells[t_y][t_x] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;
				cells[t_y-1][t_x-1] = VOID;

				cells[t_y+1][t_x] = T;
				cells[t_y][t_x] = T;
				cells[t_y-1][t_x] = T;
				cells[t_y][t_x-1] = T;

                        	t_y = t_y+1; // 현재 tx ty는 맨 아래
                        	return true;
                	}
                	else return true;
        }
        else return false;
	}
	if(rotate == 2){
	// 현재 위치는 맨 아래 중간
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y][t_x+1] == VOID){
		if(cells[t_y][t_x-1] == VOID){
      	        	if(t_y<height){
        	 		cells[t_y][t_x] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-1][t_x-1] = VOID;
				cells[t_y-1][t_x+1] = VOID;               	

				cells[t_y+1][t_x] = T;
				cells[t_y][t_x] = T;
				cells[t_y][t_x-1] = T;
				cells[t_y][t_x+1] = T;
				t_y = t_y+1; // 현재 tx ty는 맨 아래
                        	return true;
                	}
                	else return true;
		}
		else return false;
        }
        else return false;
	}
	if(rotate == 3){
	// 현재 위치는 맨 아래 중간
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y][t_x+1] == VOID){
      	        	if(t_y<height){
				cells[t_y][t_x] = VOID;
				cells[t_y-1][t_x] = VOID;
				cells[t_y-2][t_x] = VOID;
				cells[t_y-1][t_x+1] = VOID;

				cells[t_y+1][t_x] = T;
				cells[t_y][t_x] = T;
				cells[t_y-1][t_x] = T;
				cells[t_y][t_x+1] = T;
                        	t_y = t_y+1; // 현재 tx ty는 맨 아래
                        	return true;
                	}
                	else return true;
        }
        else return false;
	}
	if(rotate == 0){
	// 현재 위치는 맨 아래 중간
        if(t_y == height-1) return false;
        if(cells[t_y+1][t_x] == VOID && cells[t_y+1][t_x+1] == VOID){
		if(cells[t_y+1][t_x-1] == VOID){
      	        	if(t_y<height){
		 		cells[t_y][t_x] = VOID; // 원래 있던값들 지워준다
				cells[t_y][t_x-1] = VOID;
				cells[t_y][t_x+1] = VOID;
				cells[t_y-1][t_x] = VOID;

				cells[t_y+1][t_x] = T;
                        	cells[t_y+1][t_x-1] = T;
                        	cells[t_y+1][t_x+1] = T;
                        	cells[t_y][t_x] = T; //
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

void TBlock::dropBlock(int &t_x, int &t_y, Cell **cells){

	if(rotate == 1){
	bool notendofline = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-2][t_x] = VOID; 
        cells[t_y-1][t_x-1] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다

        while(cells[t_y][t_x] == VOID && cells[t_y-1][t_x-1] == VOID){ // VOID일 경우
		t_y++;

                if(t_y == height -1){
                        break;
                }
       	}

	if(cells[t_y][t_x] != VOID || cells[t_y-1][t_x-1] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-3][t_x] = T;
                        cells[t_y-2][t_x-1] = T;

	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = T;
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-1][t_x-1] = T;
        }
	else{
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-3][t_x] = T;
                        cells[t_y-2][t_x-1] = T;
	}

	}
	if(rotate == 2){
	bool onlytwo = false;
	bool notendofline = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-1][t_x-1] = VOID; 
        cells[t_y-1][t_x+1] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다

        while(cells[t_y][t_x] == VOID && cells[t_y-1][t_x-1] == VOID){ // VOID일 경우
               	if(cells[t_y-1][t_x+1] == VOID)
			t_y++;
		else { onlytwo = true; break;}

                if(t_y == height -1){
                        break;
                }
       	}

	if(cells[t_y][t_x] != VOID || cells[t_y-1][t_x-1] != VOID) notendofline = true;
	if(cells[t_y-1][t_x+1] != VOID) notendofline = true;

	if(onlytwo){
			
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-2][t_x-1] = T;
                        cells[t_y-2][t_x+1] = T;

	}
	else if(t_y == height-1 && notendofline){

                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-2][t_x-1] = T;
                        cells[t_y-2][t_x+1] = T;

	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = T;
                        cells[t_y-1][t_x] = T;
                        cells[t_y-1][t_x-1] = T;
                        cells[t_y-1][t_x+1] = T;
        }
	else{

                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-2][t_x-1] = T;
                        cells[t_y-2][t_x+1] = T;

	}
	}
	if(rotate == 3){
	bool notendofline = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y-1][t_x] = VOID; 
        cells[t_y-2][t_x] = VOID; 
        cells[t_y-1][t_x+1] = VOID; 

        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다

        while(cells[t_y][t_x] == VOID && cells[t_y-1][t_x+1] == VOID){ // VOID일 경우
		t_y++;
                if(t_y == height -1){
                        break;
                }
       	}

	if(cells[t_y][t_x] != VOID || cells[t_y-1][t_x+1] != VOID) notendofline = true;

	if(t_y == height-1 && notendofline){
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-3][t_x] = T;
                        cells[t_y-2][t_x+1] = T;
	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = T;
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-1][t_x+1] = T;
        }
	else{
                        cells[t_y-1][t_x] = T;
                        cells[t_y-2][t_x] = T;
                        cells[t_y-3][t_x] = T;
                        cells[t_y-2][t_x+1] = T;
	}
	}
	if(rotate == 0){
	bool onlytwo = false;
        // 원래 있던 값들 다 지운다
        cells[t_y][t_x] = VOID;
        cells[t_y][t_x-1] = VOID; 
        cells[t_y][t_x+1] = VOID; 
        cells[t_y-1][t_x] = VOID; 


        // 현재 t_x좌표에서 가장 작은 t_y값을 가지는 t_y좌표를 찾는다

        while(cells[t_y][t_x-1] == VOID && cells[t_y][t_x+1] == VOID){ // VOID일 경우
               	if(cells[t_y][t_x] == VOID)
			t_y++;
		else { onlytwo = true; break;}

                if(t_y == height -1){
                        break;
                }
       	}

	if(cells[t_y][t_x-1] != VOID || cells[t_y][t_x+1] != VOID) onlytwo = true;

	if(onlytwo){
			
                       cells[t_y-1][t_x] = T;
                       cells[t_y-1][t_x-1] = T;
                       cells[t_y-1][t_x+1] = T;
                       cells[t_y-2][t_x] = T;

	}
        else if(t_y == height-1){
                        cells[t_y][t_x] = T;
                        cells[t_y][t_x-1] = T;
                        cells[t_y][t_x+1] = T;
                        cells[t_y-1][t_x] = T;
        }
	else{
                        cells[t_y-1][t_x] = T;
                        cells[t_y-1][t_x-1] = T;
                        cells[t_y-1][t_x+1] = T;
                        cells[t_y-2][t_x] = T;
	}
	}

}

bool TBlock::rotateBlock(int &t_x, int &t_y, Cell **cells){

	rotate = (++rotate) % 4;

	if(rotate == 1){
		
		cells[t_y][t_x] = VOID;
		cells[t_y][t_x-1] = VOID;
		cells[t_y][t_x+1] = VOID;
		cells[t_y-1][t_x] = VOID;

		//현재 좌표값 이동 : 오른쪽 맨 아래
		t_y = t_y+1;
		
		cells[t_y][t_x] = T;
		cells[t_y-1][t_x] = T;
		cells[t_y-2][t_x] = T;
		cells[t_y-1][t_x-1] = T;
		
	}

	if(rotate == 2){

		cells[t_y][t_x] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-2][t_x] = VOID;
		cells[t_y-1][t_x-1] = VOID;

		//현재 좌표값 이동 : 가운데 아래
		//그대로
		cells[t_y][t_x] = T;
		cells[t_y-1][t_x] = T;
		cells[t_y-1][t_x-1] = T;
		cells[t_y-1][t_x+1] = T;

	}

	if(rotate == 3){
		cells[t_y][t_x] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-1][t_x-1] = VOID;
		cells[t_y-1][t_x+1] = VOID;

		//현재 좌표값 이동 : 왼쪽 맨 아래
		//그대로

		cells[t_y][t_x] = T;
		cells[t_y-1][t_x] = T;
		cells[t_y-2][t_x] = T;
		cells[t_y-1][t_x+1] = T;
	}

	if(rotate == 0){

		cells[t_y][t_x] = VOID;
		cells[t_y-1][t_x] = VOID;
		cells[t_y-2][t_x] = VOID;
		cells[t_y-1][t_x+1] = VOID;

		//현재 좌표값 이동 : 아래 가운데
		t_y = t_y-1;

		cells[t_y][t_x] = T;
		cells[t_y][t_x-1] = T;
		cells[t_y][t_x+1] = T;
		cells[t_y-1][t_x] = T;
	}

	return true;
}
